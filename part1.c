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

int main() {
	char str1[10];
	printf("Enter size of input:");
	scanf("%s", str1);
	//printf("was entered: %s\n", str1);
	//int i = char_to_int(str1[0]);
	int size = array_to_int(str1);
	if (size < 1) {
		printf("Invalid size");
		return 0;
	}
	int *array_ptr;
	array_ptr = (int*) malloc(size * sizeof(int));
    if(array_ptr == NULL)
	{
        printf("Error! memory not allocated.");
        exit(0);
    }
	int temp_int = 0, sum = 0;
	for (int i = 0; i < size; ++i) {
		printf("Enter numbers:\n");
		scanf("%s",str1);
		temp_int = array_to_int(	str1);
		if (temp_int<0) {
			printf("Invalid number");
			free(array_ptr);
			return 0;
		}
		array_ptr[i] = temp_int;
		sum += temp_int;
	}
	printf("sum:%i ", sum);
	free(array_ptr);
	return 0;
}

int char_to_int(char c) {
	int i = c - '0';
	if (i>=0 && i<=9) {
		return i;
	}
	return -1;
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
