/*
 * part1.c
 *
 *  Created on: Mar 31, 2017
 *      Author: master
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum { false, true } bool;

int charToInt(char c);
int arrayToInt(char *c);
int tillFirstEnter();

int main() {
	int number;
	printf("Enter size of input:\n");
	number = tillFirstEnter();
	if ( number == -1) {
		printf("Invalid size");
		return 0;
	}

	char *ptr = malloc(sizeof(char) * number * 10);
	if (ptr == NULL) {
		printf(" Out of memory!\n");
		exit(1);
	}

	int c=0, length = 0;
	char ch;
	printf("Enter numbers:\n");
	while (c != 10){
		c = getchar();
		ch = (char)c;
		if ( (c >= 48 && c <= 57) || ((c == 45) || (c == 32))) {
			ptr[length] = ch;
		} else if ( c != 10) {
			//printf("char: %c, int: %d", ch, c);
			printf("Invalid number\n");
			return 0;
		}
		length++;
	}
	//printf("STRING1: %s\n" , ptr);
	int i, j = 1;
	for (i = 1; i < length; ++i) {
		if((int)ptr[j] == 32 && (int)ptr[j-1] == 32) {
			ptr[i] = ptr[j+1];
			i--;
		} else {
			ptr[i] = ptr[j];
		}
		j++;
	}
	//printf("STRING2: %s\n" , ptr);

	char* pch = strtok (ptr," ");
	int current_int, sum = 0, k;
	while (pch != NULL && k < number)	{
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


	//printf("number: %d", number);
	/*int current_int, sum = 0;
	printf("Enter numbers:\n");
	for (int i = 0; i < number; ++i) {
		current_int = tillFirstEnter();
		//printf("number: %d\n", current_int);
		int i = 2, j = 1;
		while ( i <= current_int) {
			if (i == current_int) {
				printf("The number %d is a power of 2: %d = 2^%d\n", i, i, j);
				sum += j;
			}
			i *= 2;
			j++;
		}

	}*/
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

inline int tillFirstEnter(){
	int c=0, result = 0, i = 0;
	bool negative = false;
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
	int i = 0,j = 0;
	int sum = 0;
	bool negative = false;
	if (c[0] == 45) {
		negative = true;
		i++;
	}
	while (c[i] != 0) {
		sum *= 10;
		j = charToInt(c[i]);
		if (j != -1) sum += j;
		else return 0;
		//printf("%i\n", sum);
		i++;
	}
	if (negative) {
		return -sum;
	}
	return sum;
	//printf("second: %c\n",c[1]);
	//int i = strlen(c);
	//return 0;
}
