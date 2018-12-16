#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>	
#include <wincon.h>
#include <memory.h>

#define col GetStdHandle(STD_OUTPUT_HANDLE)//콘솔창에 핸들정보
#pragma warning(disable:4996)

char abc[50] = "Hello";

int main(void) {
	char Original_String[101];
	char Encode_String[101];
	int Len = 0;
	int key = 0;
	int i = 0;
	int choice;
	memset(Original_String, NULL, 101); 
	memset(Encode_String, NULL, 101);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

	printf("==============================\n");
	printf("Made by L0RQ2 - Cipher Encoder/Decoder\n");
	printf("l0rq2.tistory.com\n");
	printf("MMHS 10703 LORQ2\n");
	printf("==============================\n");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("Encode = 0 \nDecode = 1\n=>");
	scanf("%d", &choice);
	
	rewind(stdin); //Stdin Buffer Clear
	
	if (choice == 0) {
		printf("To Encode => ");
		gets_s(Original_String, 100); //Get Oiriginal_String

		printf("Key => ");
		scanf("%d", &key); //Get Key

		Len = strlen(Original_String); //Get strlen of Original_String

		for (i = 0; i < Len; i++) {  //Orginal_string[i]!=NULL
			if (isalpha(Original_String[i])) { // Is it Alpha?
				if (isupper(Original_String[i])) { //Upper case : 65~90
					//Encode_String[i] = Original_String[i] + (key % 26);
					if (Original_String[i] + (key % 26) > 90) {
						int more = (Original_String[i] + (key % 26)) - 90;
						Encode_String[i] = 65 + (more - 1);
					}
					else {
						Encode_String[i] = Original_String[i] + (key % 26);
					}
				}

				else if (islower(Original_String[i])) {  //Lower case : 97~122
					if (Original_String[i] + (key % 26) > 122) {
						int more = (Original_String[i] + (key % 26)) - 122;
						Encode_String[i] = 97 + (more - 1);
					}
					else {
						Encode_String[i] = Original_String[i] + (key % 26);
					}
				}
				else {
					printf("\nProgram_Error!!\n");
					break;
				}
			}
			else if (Original_String[i] >= '0' && Original_String[i] <= '9') { //num = 48~57 = 0~9
				if (Original_String[i] + (key % 10) > 57) {
					int more = (Original_String[i] + (key % 10)) - 57;
					Encode_String[i] = 48 + (more - 1);
				}
				else {
					Encode_String[i] = Original_String[i] + (key % 10);
				}
			}
			else {
				Encode_String[i] = Original_String[i];   //Special symbol
			}
		}
		puts(Encode_String); //res
	}
	else if (choice == 1) {
		int key = 0;
		char Original_String[26][101];
		int Len;
		
		printf("To Decode => ");
		gets_s(Encode_String, 101); //Get Oiriginal_String
		
		Len = strlen(Encode_String);
		Encode_String[Len] = '\0';

		for (key = 0; key <= 25; key++) {
			memset(Original_String[key], NULL, sizeof(char)*(Len-1));
		}

		for (key = 0; key <= 25; key++) {
			//printf("%d\n",key);
			for (int i = 0; i <= Len+1; i++) {
				//Original_String[key][i] = i;
				if (i > Len) {
					Original_String[key][i] = '\0';
				}
				else if (isalpha(Encode_String[i])) {
					if (isupper(Encode_String[i])) { //Upper 65~90
						if (Encode_String[i] - (key+1) < 65) {
							int less = ((key+1) - (Encode_String[i] - 65));
							Original_String[key][i] = 90 - (less - 1);
						}
						else {
							Original_String[key][i] = Encode_String[i] - (key+1);
						}
					}
					else if (islower(Encode_String[i])) {
						if (Encode_String[i] - (key + 1) < 97) {
							int less = ((key + 1) - (Encode_String[i] - 97));
							Original_String[key][i] = 122 - (less - 1);
						}
						else {
							Original_String[key][i] = Encode_String[i] - (key + 1);
						}
					}
					else {
						printf("Program Error!\n");
						return 0;
					}
				}
				else if (Encode_String[i] >= '0' && Encode_String[i] <= '9') { //num = 48~57 = 0~9
					int less = (((key + 1) - ('0' - Encode_String[i])) % 10);
					char imsi = '9' - (less - 1);
					if (Encode_String[i] - (key + 1) <= '0') {
						if (less == 0) {
							Original_String[key][i] = Encode_String[i];
						}
						else {
							Original_String[key][i] = imsi;
						}
					}
					else {
						Original_String[key][i] = Encode_String[i] - (key + 1);
					}
				}
				/*
				else {
					printf("Program Error!\n");
					return 0;
				}
				*/
			}
		}
		for (key = 0; key <= 25; key++) {
			printf("Key : %d => ", key + 1);
			for (int i = 0; i <= Len - 1; i++) {
				printf("%c", Original_String[key][i]);
			}
			printf("\n");
		}
	}
	//===========================================================================================
	else {
		printf("Just 0 Or 1\n");
	}
	system("pause");
	return 0;
}