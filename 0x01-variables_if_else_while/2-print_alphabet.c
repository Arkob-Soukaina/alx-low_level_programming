#include <stdio.h>
/**
 * main - Prints alphabets
 * 
 * Return: 0
*/

int main(void)
{
	int i;
	char a[26] = "abcdefghijklmnopqrstuvwxyz";

	for (i = 0; i < 26; i++)
		putchar(a[i]);
	putchar('\n');
	return (0);
}
