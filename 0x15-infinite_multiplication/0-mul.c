#include "holberton.h"
#include <math.h>

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vectors
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *str1 = argv[1];
	char *str2 = argv[2];
	int num1, num2;

	if (argc != 3 || !isNumber(str1) || !isNumber(str2))
	{
		printf("Error\n");
		exit(98);
	}
	sscanf(str1, "%d", &num1);
	sscanf(str2, "%d", &num2);
	printf("%d\n", karatsuba(num1, num2));
	return (0);
}

/**
 * isNumber - check number
 * @number: string number
 * Return: 0 on error else 1
 */
int isNumber(char *number)
{
	while (*number)
	{
		if (*number < '0' || *number > '9')
			return (0);
		number++;
	}
	return (1);
}

int numLen(int num)
{
	int size;
	for ( size = 0; num % 10; size++)
	{
		num = num / 10;
	}
	return (size);
}

int powB10(int m) {
	int num = 10;
	for (; m > 1; m--)
	{
		num = num * num;
	}
	return(num);
}

int karatsuba(int num1, int num2)
{
	int m, len1, len2, h1, h2, l1, l2, z0, z1, z2;

	if (num1 < 10 && num2 < 10)
		return num1 * num2;

	len1 = numLen(num1);
	len2 = numLen(num2);

	if (len1 >= len2)
	{
		m = len1/2;
	}
	else
	{
		m = len2/2;
	}

	h1 = num1 / powB10(m);
	l1 = num1 % powB10(m);

	h2 = num2 / powB10(m);
	l2 = num2 % powB10(m);

	z0 = karatsuba(l1, l2);
    z1 = karatsuba(h1 + l1, h2 + l2);
    z2 = karatsuba(h1, h2);
	
	
	return (z2*(powB10(m*2)) + (z1 - z2 - z0)*(powB10(m)) + z0);
	
}
