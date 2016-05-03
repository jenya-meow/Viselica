#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include <locale.h>
#include <string.h>
#include <wchar.h>

void risunok(int life);
void random_word(unsigned int choice);
void asteriks(char cens[], wchar_t guess);
wchar_t input();
wchar_t word[20];
const char themes[3][18] = {
    "Животные", 
    "Спорт",
    "Растения"
};

void game()
{
    unsigned int choice = 0;
    int life = 12, flg = 0;
    wchar_t guess;
    clear();
    keypad(stdscr, true);
    curs_set(0); 
    while (!flg) {
        unsigned i;
        clear();
        printw("Выберите тему:\n");
        for (i = 0; i < 3; i++) {
            if ( i == choice )
                addch('>');
            else          
                addch(' ');
            printw("%s\n", themes[i]);
        }
        attron(A_REVERSE);
        mvwprintw(stdscr, getmaxy(stdscr) - 1, 0, "Нажмите ENTER для подтверждения, стрелки вверх/вниз для выбора");
        attroff(A_REVERSE);
        switch (getch()) {
            case KEY_UP:
                if (choice)
                    choice--; 
            break;
            case KEY_DOWN:
                if (choice != 2)
                    choice++;
            break;
            case '\n':
                flg++;
            break;
        }
    }
    keypad(stdscr, false);
    random_word(choice);
    char cens[(wcslen(word)+1)];
    while (life > 0 && guess != 'q') {
        clear();
        asteriks(cens, guess);//обработчик от Мариши
        printw("Ваше слово сейчас: %s\n", cens);
        mvprintw(2, 0,"Жизней: %d\n", life);
        mvprintw(5, 0,"%s\n", word);
        risunok(life);//рисунок от Дани
        attron(A_REVERSE);
        mvwprintw(stdscr, getmaxy(stdscr) - 1, 0, "Нажмите ENTER для подтверждения, Q для выхода");
        attroff(A_REVERSE);
        guess = input();//ввод от Ксюни
        life--;
    }
    clear();
    return;
}

int main()
{
    setlocale(LC_ALL,"");
    initscr();
    wchar_t a;
    mvwprintw(stdscr, 1, (getmaxx(stdscr) - 18)/ 2, "Добро пожаловать в\n");
    while (a != 'q' && a != 'Q') {
        attron(A_BOLD);
        WINDOW *welc = subwin(stdscr, 6, 64, (LINES - 6) / 2, (COLS - 64) / 2);
        wprintw(welc, 
        "██╗  ██╗ █████╗ ███╗   ██╗ ██████╗ ███╗   ███╗ █████╗ ███╗   ██╗"
        "██║  ██║██╔══██╗████╗  ██║██╔════╝ ████╗ ████║██╔══██╗████╗  ██║"
        "███████║███████║██╔██╗ ██║██║  ███╗██╔████╔██║███████║██╔██╗ ██║"
        "██╔══██║██╔══██║██║╚██╗██║██║   ██║██║╚██╔╝██║██╔══██║██║╚██╗██║"
        "██║  ██║██║  ██║██║ ╚████║╚██████╔╝██║ ╚═╝ ██║██║  ██║██║ ╚████║"
        "╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝");
        refresh();
        delwin(welc);
        attroff(A_BOLD);
        attron(A_REVERSE);
        mvwprintw(stdscr, getmaxy(stdscr) - 1, 0, "Нажмите ENTER для начала, Q для выхода");
        attroff(A_REVERSE);
        cbreak();
        a = getch();
        if (a == '\n')
            game();
    }
    endwin();
    printf("Bye - bye!\n");
    return 0;
}
    
