#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>	
#include <wincon.h>
#include <memory.h>
#include <stdbool.h> //Use the bool
#include <time.h>

#pragma warning(disable:4996)

#define _PROGRAM_ERROR_ printf("Program_Error !!\nDon't run this program\n\n");

int upper_num_list[26];
char upper_char_list[26];

int lower_num_list[26];
char lower_char_list[26];

int num_int_list[10];
char num_char_list[10]; //This is inteager

int Special_num_list[31];
char Special_char_list[31];
int Special_end;

char Original_String[1000];
char Encode_String[1000];

int key;

int Encrypt_upper(int x) {
	for (int j = 0; upper_char_list[j] != NULL; j++) {
		if (upper_char_list[j] == Original_String[x]) {
			int flag_int = j;// on the j.
			if (flag_int + key > 25) { // I know the number of upper case
				int more = key - (25 - flag_int);
				Encode_String[x] = upper_char_list[more - 1];
			}
			else {
				Encode_String[x] = upper_char_list[flag_int + key];
			}
		}
	}
}

int Encrypt_lower(int x) {
	for (int j = 0; lower_char_list[j] != NULL; j++) {
		if (lower_char_list[j] == Original_String[x]) {
			int flag_int = j;// on the j.
			if (flag_int + key > 25) { // I know the number of upper case
				int more = key - (25 - flag_int);
				Encode_String[x] = lower_char_list[more - 1];
			}
			else {
				Encode_String[x] = lower_char_list[flag_int + key];
			}
		}
	}
}

int Encrypt_num(int x){
	for (int j = 0; num_char_list[j] != NULL; j++) {
		if (num_char_list[j] == Original_String[x]) {
			int flag_int = j;// on the j.
			if (flag_int + key > 9) { // I know the number of upper case
				int more = key - (9 - flag_int);
				Encode_String[x] = num_char_list[more - 1];
			}
			else {
				Encode_String[x] = num_char_list[flag_int + key];
			}
		}
	}
}
 
int Encrypt_special(int x) {
	for (int j = 0; Special_char_list[j] != NULL; j++) {
		if (Special_char_list[j] == Original_String[x]) {
			int flag_int = j;// on the j.
			if (flag_int + key > Special_end-1) { // I know the number of upper case
				int more = key - (Special_end -1- flag_int);
				Encode_String[x] = Special_char_list[more - 1];
			}
			else {
				Encode_String[x] = Special_char_list[flag_int + key];
			}
		}
	}
}

int Decrypt_upper(int x) {
	for (int j = 0; upper_char_list[j] != NULL; j++) {
		if (upper_char_list[j] == Encode_String[x]) {
			int flag_int = j;// on the j.
			if (flag_int - key < 0) { // I know the number of upper case
				int less = 25 - (key - flag_int) + 2;
				Original_String[x] = upper_char_list[less - 1];
			}
			else {
				Original_String[x] = upper_char_list[flag_int - key];
			}
		}
	}

}int Decrypt_lower(int x) {
	for (int j = 0; lower_char_list[j] != NULL; j++) {
		if (lower_char_list[j] == Encode_String[x]) {
			int flag_int = j;// on the j.
			if (flag_int - key < 0) { // I know the number of upper case
				int less = 25 - (key - flag_int) + 2;
				Original_String[x] = lower_char_list[less - 1];
			}
			else {
				Original_String[x] = lower_char_list[flag_int - key];
			}
		}
	}
}

int Decrypt_num(int x) {
	for (int j = 0; num_char_list[j] != NULL; j++) {
		if (num_char_list[j] == Encode_String[x]) {
			int flag_int = j;// on the j.
			if (flag_int - key < 0) { // I know the number of upper case
				int less = 9 - (key - flag_int) + 2;
				Original_String[x] = num_char_list[less - 1];
			}
			else {
				Original_String[x] = num_char_list[flag_int - key];
			}
		}
	}
}

int Decrypt_special(int x) {
	for (int j = 0; Special_char_list[j] != NULL; j++) {
		if (Special_char_list[j] == Encode_String[x]) {
			int flag_int = j;// on the j.
			if (flag_int - key < 0) { // I know the number of upper case
				int less = Special_end - (key - flag_int) + 1;
				Original_String[x] = Special_char_list[less - 1];
			}
			else {
				Original_String[x] = Special_char_list[flag_int - key];
			}
		}
	}
}

int upper() {
	int i=0;
	FILE *fp = fopen("upper.txt", "r");
	if (fp == NULL) {
		printf("upper.txt file doesn't exist.\nFirst, make that file\n");
		return 0;
	}
	else {
		while (fscanf(fp, "%d\t%c", &upper_num_list[i], &upper_char_list[i]) != EOF) {
			i = i + 1;
		}
	}
	fclose(fp);
}

int lower() {
	int i = 0;
	FILE *fp = fopen("lower.txt", "r");
	if (fp == NULL) {
		printf("lower.txt file doesn't exist.\nFirst, make that file\n");
		return 0;
	}
	else {
		while (fscanf(fp, "%d\t%c", &lower_num_list[i], &lower_char_list[i]) != EOF) {
			i = i + 1;
		}
	}
	fclose(fp);
}

int int_num() {
	int i = 0;
	FILE *fp = fopen("int_num.txt", "r");
	if (fp == NULL) {
		printf("int_num.txt file doesn't exist.\nFirst, make that file\n");
		return 0;
	}
	else {
		while (fscanf(fp, "%d\t%c", &num_int_list[i], &num_char_list[i]) != EOF) {
			i = i + 1;
		}
	}
	fclose(fp);
}

int Special_char() {
	int i = 0;
	FILE *fp = fopen("Special_char.txt", "r");
	if (fp == NULL) {
		printf("int_num.txt file doesn't exist.\nFirst, make that file\n");
		return 0;
	}
	while (fscanf(fp, "%d\t%c", &Special_num_list[i], &Special_char_list[i]) != EOF) {
		i = i + 1;
	}
	Special_end = i;
	fclose(fp);
}

int Make_upper() {
	int want;
	printf("Make : 0\nStop : 1\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("Warning : if upper.txt already exists, it will removed ==>");
	scanf("%d", &want);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	if (want == 0) {
		char Alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		char Encrypt_Alphabet[26];
		int flag[1000];
		int v;
		int j=0;
		memset(flag, NULL, 4000);
		memset(Encrypt_Alphabet, NULL, sizeof(char) * sizeof(Encrypt_Alphabet));
		srand(time(NULL));
		for (int i = 0; i <= 4000; i++) {
			v = rand() % 26;
			if (Alphabet[v] == NULL) {
				flag[v] = 1;
			}
			if (flag[v]==1) {
				continue;
			}
			else {
				if (j + 1 == 27) {
					break;
				}
				Encrypt_Alphabet[j] = Alphabet[v];
				flag[v] = 1;
				j = j + 1;
			}
		}
		FILE *fp = fopen("upper.txt", "w");
		for (int i = 0; i <= 25; i++) {
			if (i == 25) {
				fprintf(fp, "%d\t%c", i, Encrypt_Alphabet[i]);
				break;
			}
			fprintf(fp, "%d\t%c\n", i, Encrypt_Alphabet[i]);
		}
		fclose(fp);
	}
	else if(want==1){
		printf("Stop!!\n");
		return 1;
	}
	else {
		printf("Only 0 or 1\n\n");
	}
}

int Make_lower() {
	int want;
	printf("Make : 0\nStop : 1\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("Warning : if lower.txt already exists, it will removed ==>");
	scanf("%d", &want);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	if (want == 0) {
		char Alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
		char Encrypt_Alphabet[26];
		int flag[1000];
		int v;
		int j = 0;
		memset(flag, NULL, 4000);
		memset(Encrypt_Alphabet, NULL, sizeof(char) * sizeof(Encrypt_Alphabet));
		srand(time(NULL));
		for (int i = 0; i <= 4000; i++) {
			v = rand() % 26;
			if (Alphabet[v] == NULL) {
				flag[v] = 1;
			}
			if (flag[v] == 1) {
				continue;
			}
			else {
				if (j + 1 == 27) {
					break;
				}
				Encrypt_Alphabet[j] = Alphabet[v];
				flag[v] = 1;
				j = j + 1;
			}
		}
		FILE *fp = fopen("lower.txt", "w");
		for (int i = 0; i <= 25; i++) {
			if (i == 25) {
				fprintf(fp, "%d\t%c", i, Encrypt_Alphabet[i]);
				break;
			}
			fprintf(fp, "%d\t%c\n", i, Encrypt_Alphabet[i]);
		}
		fclose(fp);
	}
	else if (want == 1) {
		printf("Stop!!\n");
		return 1;
	}
	else {
		printf("Only 0 or 1\n\n");
	}
}

int Make_int_num() {
	int want;
	printf("Make : 0\nStop : 1\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("Warning : if int_num.txt already exists, it will removed ==>");
	scanf("%d", &want);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	if (want == 0) {
		char num[10] = "0123456789";
		char Encrypt_num[10];
		int flag[1000];
		int v;
		int j = 0;
		memset(flag, NULL, 4000);
		memset(Encrypt_num, NULL, sizeof(char) * sizeof(Encrypt_num));
		srand(time(NULL));
		for (int i = 0; i <= 4000; i++) {
			v = rand() % 10;
			if (num[v] == NULL) {
				flag[v] = 1;
			}
			if (flag[v] == 1) {
				continue;
			}
			else {
				if (j + 1 == 11) {
					break;
				}
				Encrypt_num[j] = num[v];
				flag[v] = 1;
				j = j + 1;
			}
		}
		FILE *fp = fopen("int_num.txt", "w");
		for (int i = 0; i <= 9; i++) {
			if (i == 9) {
				fprintf(fp, "%d\t%c", i, Encrypt_num[i]);
				break;
			}
			fprintf(fp, "%d\t%c\n", i, Encrypt_num[i]);
		}
		fclose(fp);
	}
	else if (want == 1) {
		printf("Stop!!\n");
		return 1;
	}
	else {
		printf("Only 0 or 1\n\n");
	}
}

int Make_Special_char() {
	int want;
	printf("Make : 0\nStop : 1\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("Warning : if Special_char.txt already exists, it will removed ==>");
	scanf("%d", &want);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	if (want == 0) {
		int shake;
		char Specials[1000];
		int check=0;
		while (1) {
			rewind(stdin);
			memset(Specials, NULL, sizeof(char) * sizeof(Specials));
			printf("Input (max : 1000) => ");
			gets_s(Specials, sizeof(Specials));
			int Len = strlen(Specials);
			char k[1000];
			memset(k, NULL, sizeof(char) * sizeof(k));
			int a[1000];
			memset(a, NULL, sizeof(a));	
			for (int i = 0; Specials[i] != NULL; i++) {
				k[i] = Specials[i];
			}
			for (int i = 0; k[i] != NULL; i++) {
				for (int j = 0; Specials[j] != NULL; j++) {
					if (k[i] == Specials[j]) {
						a[i] += 1;
						if (a[i] >= 2) {
							check = 1;
							printf("Error!\n");
							continue;
						}
					}
				}
			}
			if (check == 0) {
				break;
			}
		}
		rewind(stdin);
		int Len = strlen(Specials);
		printf("Do you want to shake?\nDon't shake : 0\nshake : 1\n=> ");
		scanf("%d", &shake);
		if (shake == 0) {
			FILE *fp = fopen("Special_char.txt", "w");
			for (int i = 0; i <= Len - 1; i++) {
				if (i == Len - 1) {
					fprintf(fp, "%d\t%c", i, Specials[i]);
					break;
				}
				fprintf(fp, "%d\t%c\n", i, Specials[i]);
			}
			fclose(fp);
		}
		else if (shake == 1) {
			char Encrypt_Specials[1000];
			int flag[1000];
			int v;
			int j = 0;
			memset(flag, NULL, 4000);
			memset(Encrypt_Specials, NULL, sizeof(char) * sizeof(Encrypt_Specials));
			srand(time(NULL));
			for (int i = 0; i <= 10000; i++) {
				v = rand() % Len;
				if (Specials[v] == NULL) {
					flag[v] = 1;
				}
				if (flag[v] == 1) {
					continue;
				}
				else {
					if (j + 1 == Len+1) {
						break;
					}
					Encrypt_Specials[j] = Specials[v];
					flag[v] = 1;
					j = j + 1;
				}
			}
			FILE *fp = fopen("Special_char.txt", "w");
			for (int i = 0; i <= Len - 1; i++) {
				if (i == Len - 1) {
					fprintf(fp, "%d\t%c", i, Encrypt_Specials[i]);
					break;
				}
				fprintf(fp, "%d\t%c\n", i, Encrypt_Specials[i]);
			}
			fclose(fp);
		}
		else {
			printf("Only 0 or 1\n");
		}
		
	}
	else if (want == 1) {
		printf("Stop!!\n");
		return 1;
	}
	else {
		printf("Only 0 or 1\n\n");
	}
}

int main(void) {
	int Len = NULL;
	int choice=NULL;
	key = NULL;
	int make = NULL;
	memset(Original_String, NULL, sizeof(char) * sizeof(Original_String));
	memset(Encode_String, NULL, sizeof(char) * sizeof(Encode_String));
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("===========================================================\n");
	printf("Made by L0RQ2 - Cipher Encoder/Decoder - Upgrade\n");
	printf("l0rq2.tistory.com\n");
	printf("MMHS 10703 LORQ2\n");
	printf("===========================================================\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	
	printf("En/Decode : 0 \nMake Agreement : 1 \n==>");
	scanf("%d", &make);
	rewind(stdin);
	
	if (make == 0) {
		upper();
		lower();
		int_num();
		Special_char();
		/*
		printf("\n\n");
		for (int i = 0; Special_num_list[i] != NULL; i++) {
			printf("%d %c\n", Special_num_list[i], Special_char_list[i]);
		}
		*/
		printf("Encode : 0\nDecode : 1\n==>");
		scanf("%d", &choice);
		rewind(stdin);
		if (choice == 0) {
			int i, flag_int;
			char flag_char;
			printf("Original_String To Encode => ");
			gets_s(Original_String, 100); //Get Oiriginal_String

			printf("Key => ");
			scanf("%d", &key); //GetKey 0+앤터

			Len = strlen(Original_String); //Get strlen of Original_String

			for (i = 0; i < Len; i++) {  //Orginal_string[i]!=NULL   ++i    i++
				if (isalpha(Original_String[i])) { // Is it Alpha?
					if (isupper(Original_String[i])) {
						Encrypt_upper(i);
					}
					else if (islower(Original_String[i])) {
						Encrypt_lower(i);
					}
					else {
						_PROGRAM_ERROR_
							break;
					}
				}
				else if (isdigit(Original_String[i])) {
					Encrypt_num(i);
				}
				else {
					char *is = strchr(Special_char_list, Original_String[i]);
					if (is == NULL) {
						Encode_String[i] = Original_String[i];
					}
					else if (is != NULL) {
						Encrypt_special(i);
					}
					else {
						_PROGRAM_ERROR_
							break;
					}
				}
			}
			printf("\n\nEncode_String : ");
			puts(Encode_String);
		}
		else if (choice == 1) { //Decode
			printf("Encode_Stirng to Decode => ");
			gets_s(Encode_String, sizeof(char) * sizeof(Encode_String));

			printf("Key => ");
			scanf("%d", &key);

			Len = strlen(Encode_String);
			
			int i;
			for (i = 0; i < Len; i++) {  //Orginal_string[i]!=NULL   ++i    i++
				if (isalpha(Encode_String[i])) { // Is it Alpha?
					if (isupper(Encode_String[i])) {
						Decrypt_upper(i);
					}
					else if (islower(Encode_String[i])) {
						Decrypt_lower(i);
					}
					else {
						_PROGRAM_ERROR_
							break;
					}
				}
				else if (isdigit(Encode_String[i])) {
					Decrypt_num(i); 
				}
				else {
					char *is = strchr(Special_char_list, Encode_String[i]);
					if (is == NULL) {
						Original_String[i] = Encode_String[i];
					}
					else if (is != NULL) {
						Decrypt_special(i);
					}
					else {
						_PROGRAM_ERROR_
							break;
					}
				}
			}
			printf("\n\nOriginal(Decrypt)_String : ");
			puts(Original_String);
		}
		else {
			printf("Just 0 Or 1\n");
		}
		system("pause");
		return 0;
	}
	else if (make == 1) {
		while (1) {
			int which;
			printf("\nIf you want to stop : 9\nmake upper.txt : 1 \nmake lower.txt : 2\nmake int_num.txt : 3\nmake Special_char.txt : 4\n ==>");
			scanf("%d", &which);
			if (which == 9) {
				break;
			}
			else if (which == 1) {
				Make_upper();
			}
			else if (which == 2) {
				Make_lower();
			}
			else if (which == 3) {
				Make_int_num();
			}
			else if (which == 4) {
				Make_Special_char();
			}
		}
	}
	else {
		printf("Just 0 Or 1\n");
	}
	return 0;
}
