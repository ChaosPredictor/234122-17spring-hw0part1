/*
 * part1.c
 *
 *  Created on: Mar 31, 2017
 *      Author: master
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int char_to_int(char c);
int array_to_int(char *c);
int till_first_enter();

int main() {
	int number;
	printf("Enter size of input:");
	number = till_first_enter();
	if ( number == -1) {
		printf("Invalid size");
		return 0;
	}
	printf("number: %d", number);
	return 0;
}

int char_to_int(char c) {
	int i = c - '0';
	if (i>=0 && i<=9) {
		return i;
	}
	return -1;
}

int till_first_enter(){
	int c=0, result = 0;
	while (c != 10){
		//printf("this is number: %d", result);
		c = getchar();
		if ( c >= 48 && c <= 57) {
			//printf("this is number:");
			result += (c - 48);
			result *= 10;
			//printf("this is number: %d", result);
			//putchar( c );
			//printf("\n");
		} else if ( c != 10) {
			//printf("this is not a number\n %d", c);
			return -1;
		}
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
