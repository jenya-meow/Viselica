/*****************************************************
* ������: "����� ���, ����� ��� ��������� ���������" *     
* �: "��".                                           *
*****************************************************/

#include <stdio.h>

/******************************************************
* ������, ���������� �� ���� ��������� �������������: *
******************************************************/
char symbol;

/****************************************************************
*         ���������� ������, �������� �������, �������:         *
*                                                               *
* �) �������� ������� ���������� ��������;                      *
* �) ���� ������� ������������� ����� ������ ���� �� ���� ����; *
* �) �� ����������� � ���.                                      *
*                                                               *
*              ����������� ����� ������� � 26 �����             * 
*            ���������� ������ ����������� ��������.            *
****************************************************************/
char alphabet[26]; 

/*****************************************************
 *                �������� �������,                  * 
 *        ������� ������������ �������������         *
 *                 ������� �������:                  *
 *                                                   *
 *        ������ ������ ������� �������������        *
 *   �������� �������� ������� '0' � ASCII - ����.   *
 *                                                   *
 *      �������� ����� ������� �������, �������      *
 * �� ������������ ����������� � �������� ���� ����. *
 ****************************************************/     

alphabet_init() {
	int i;
	for	(i=0; i<26; i++) {
		alphabet[i]='0';
	}
	alphabet[26] = '\0';			  
}

/**********************************************
 *             �������� �������,              * 
 *        ������� ������������ ��������       *
 *  �� ��������� ���� ������� �������������.  *
 *********************************************/         

int check_repeat(char symbol) {
	int i;
	for(i=0; i<26; i++)
	{
		if (symbol == alphabet[i] &&((symbol >= 'a') && (symbol <='z'))){
			printf("You already inputted this letter. Please try a new one:");
			return  1;
		}
		if (alphabet[i] == '0' &&((symbol >= 'a') && (symbol <='z'))){
			alphabet[i] = symbol;
			return 0;
		}	
	}
}

void case_1() {
	alphabet_init();	
	printf("Case number one \n");
	printf("Input any letter:");	
	scanf("%c", &symbol);
	while (check_repeat(symbol)!=0) {
		scanf("%c", &symbol);
	};
}

void case_2() {
	alphabet_init();
	int i;
	for	(i=0; i<25; i++) {
	alphabet[i]='a'+i;
	}
	printf("Case number two \n");
	printf("Repeat any letter");	
	scanf("%c", &symbol);
	while (check_repeat(symbol)!=0) {
		printf("Input 'z' to stop loop:");
		scanf("%c", &symbol);
	};	
}

void case_3() {
	alphabet_init();
	int i;
	for	(i=0; i<1; i++) {
		alphabet[i]='a';
	}
printf("Case number three \n");
printf(" Input a letter 'a':");	
scanf("%c", &symbol);
while (check_repeat(symbol)!=0) {
		scanf("%c", &symbol);
	};
}

void case_4() {
alphabet_init();
printf("Case number four \n");
printf(" Input a letter 'a':");	
scanf("%c", &symbol);

while (check_repeat(symbol)!=0) {
		scanf("%c", &symbol);
	};

printf(" Input a letter 'a' again:");	
scanf("%c", &symbol);

while (check_repeat(symbol)!=0) {
		scanf("%c", &symbol);
	};
}

int main() {

/******************************
* ����� ���  ������� �������: *
* alphabet_init();            *
* for(??;??;??) {             *
* scanf("%c", &symbol);       * 
* while(check_repeat!=0) {    *
* 	scanf("%c", &symbol);     *
* }                           *
******************************/
	

/* ��������� ������ �������, ����� ������ ��� ������ � ������ ���: */

case_1();


/* ��������� ������ �������, ����� ������ �� 'a' �� 'y' ��� ������ ��������: */

case_2();/* (�������� � ���������� ��������, ��������������)*/ 

/* ��������� ������ �������, ����� ������ 'a' ��� ������ ��������: */

case_3();

/* ��������� ������ �������, ����� ������ '�' ��� ��������������� ������ 2 ����: */

case_4();

return 0;

}

