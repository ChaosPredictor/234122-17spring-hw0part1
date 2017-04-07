/*
 * part1.c
 *
 *  Created on: Mar 31, 2017
 *      Author: master
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum { false, true } Boolean;

int charToInt(char c);
int arrayToInt(char *c);
int tillFirstEnter();
int removeDoubleSpaces(char *string, int len);

int main() {
	int number;
	char str[5];
	printf("Enter size of input:\n");
	scanf("%s", str);
	//number = tillFirstEnter();
	number = arrayToInt(str);
	if ( number < 1) {
		printf("Invalid size\n");
		return 0;
	}

	char ch;
    while((ch= getchar()) != '\n' && ch != EOF);

	char *ptr = malloc(sizeof(char) * number * 10);
	if (ptr == NULL) {
		printf(" Out of memory!\n");
		exit(1);
	}

	printf("Enter numbers:\n");
	scanf ("%[^\n]s", ptr);

	//printf("You entered: %s\n", ptr);
	//printf("sting len: %d\n", strlen(ptr));
	int len = strlen(ptr);

	if (checkStringValidity(ptr, len) == -1) {
		printf("Invalid number\n");
		free(ptr);
		return 0;
	} else {
		//printf("Valid String\n");
	}


	int c=0, length = 0;


	//printf("STRING1: %s\n" , ptr);
	/*int i, j = 1;
	for (i = 1; i < length; ++i) {
		if((int)ptr[j] == 32 && (int)ptr[j-1] == 32) {
			ptr[i] = ptr[j+1];
			i--;
		} else {
			ptr[i] = ptr[j];
		}
		j++;
	}*/
	printf("old length: %d\n", len);
	printf("STRING1: %s\n" , ptr);
	int new_len = removeDoubleSpaces(ptr, len);
	printf("STRING2: %s\n" , ptr);
	if ( new_len == -1){
		//printf("STRING2: %s\n" , ptr);
		free(ptr);
		return 0;
	}

	printf("new length: %d\n", new_len);

	char* pch = strtok (ptr," ");
	int current_int, sum = 0, k;
	while (pch != NULL && k < 100)	{
		k++;
		//printf ("%s\n",pch);
		current_int = arrayToInt(pch);
		//printf("int: %d\n", current_int);
		int i = 1, j = 0;
		while ( i <= current_int) {
			if (i == current_int) {
				printf("The number %d is a power of 2: %d = 2^%d\n", i, i, j);
				sum += j;
			}
			i *= 2;
			j++;
		}
		pch = strtok (NULL, " ");
	}
	printf("Total exponent sum is %d", sum);
	return 0;
}

int charToInt(char c) {
	int i = c - '0';
	if (i>=0 && i<=9) {
		return i;
	}
	return -1;
}

int printMainPart(char *string, int len) {

	return 0;
}

int removeDoubleSpaces(char *string, int len) {
	int i = 1, j;
	for (j = 1; j < len; ++j) {
		if((int)string[j] == 32 && (int)string[j-1] == 32) {
			//string[i] = string[j+1];
		} else {
			string[i] = string[j];
			i++;
		}
	}
	string[i] = '\0';
	return i;
}

int checkStringValidity(const char *string, int len){
	int i = 0;
	char tmp;
	tmp = string[0];
	while (tmp != 10 && i < len){
		if ( (tmp >= 48 && tmp <= 57) || ((tmp == 45) || (tmp == 32))) {
			//printf("%c\n", tmp);
		} else if ( tmp != 10) {
			return -1;
			//printf("Invalid number\n");
			//return 0;
		}
		tmp = string[++i];
	}
	return 0;
}

inline int tillFirstEnter(){
	int c=0, result = 0, i = 0;
	Boolean negative = false;
	while (c != 10){
		//printf("this is number: %d", result);
		c = getchar();
		if ( c == 45 && i == 0) {
			negative = true;
			//printf("negative");
		} else if ( c >= 48 && c <= 57) {
			//printf("this is number:");
			result += (c - 48);
			result *= 10;
			//printf("this is number: %d", result);
			//putchar( c );
			//printf("\n");
		} else if ( c != 10) {
			//printf("int: %d\n", c);
			printf("Invalid number\n");
			break;
			return 0;
		}
		i++;
	}
	if (negative) {
		return - result/10;
	}
	return result/10;
}

int arrayToInt(char *c){
	int i = 0,tmp = 0;
	int sum = 0;
	Boolean negative = false;
	if (c[0] == 45) {
		negative = true;
		i++;
	}
	while (c[i] != 0) {
		sum *= 10;
		tmp = charToInt(c[i]);
		if (tmp != -1) {
			 sum += tmp;
		}
		else {
			return 0;
		}
		//printf("%i\n", sum);
		i++;
	}
	if (negative) {
		return -sum;
	}
	return sum;
}
