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

int char_to_int(char c);
int array_to_int(char *c);
int till_first_enter();

int main() {
	int number;
	printf("Enter size of input:\n");
	number = till_first_enter();
	if ( number == -1) {
		printf("Invalid size");
		return 0;
	}
	//printf("number: %d", number);
	int current_int, sum = 0;
	printf("Enter numbers:\n");
	for (int i = 0; i < number; ++i) {
		current_int = till_first_enter();
		//printf("number: %d\n", current_int);
		int i = 2, j = 1;
		while ( i <= current_int) {
			if (i == current_int) {
				printf("The number %d is a power of 2: %d = 2^%d\n", i, i, j);
			} else {
				//printf("this is not\n");
			}
			i *= 2;
			j++;
		}
		sum += current_int;
	}
	printf("Total exponent sum is %d", sum);
	return 0;
}

int char_to_int(char c) {
	int i = c - '0';
	if (i>=0 && i<=9) {
		return i;
	}
	return -1;
}

inline int till_first_enter(){
	int c=0, result = 0, i = 0;
	bool negative = false;
	while (c != 10 && c != 32){
		//printf("this is number: %d", result);
		c = getchar();
		if ( c >= 48 && c <= 57) {
			//printf("this is number:");
			result += (c - 48);
			result *= 10;
			//printf("this is number: %d", result);
			//putchar( c );
			//printf("\n");
		} else if ( c != 10 && c != 32 && c != 45) {
			//printf("int: %d\n", c);
			printf("Invalid number\n");
			return 0;
		} else if ( c == 45 && i == 0) {
			negative = true;
			//printf("negative");
		}
		i++;
	}
	if (negative) {
		return - result/10;
	}
	return result/10;
}

int array_to_int(char *c){
	int i,j = 0;
	int sum = 0;
	while (c[i] != 0) {
		sum *= 10;
		j = char_to_int(c[i]);
		if (j != -1) sum += j;
		else return -1;
		//printf("%i\n", sum);
		i++;
	}
	return sum;
	//printf("second: %c\n",c[1]);
	//int i = strlen(c);
	//return 0;
}
