/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<stdio.h>
#include<malloc.h>
int length_Of_String(char *str)
{
	int len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return len;
}
char removeSpaces(char *str) {
	int index,len,index1;
	if (str != NULL)
	{
		len = length_Of_String(str);
		for (index = len-1; index>=0; index--)
		{
			if (str[index]==' ')
			{
				len--;
				for (index1 = index; index1 < len; index1++)
				{
					str[index1] = str[index1 + 1];
				}
			}
		}
		//if (len > 0)
			str[len]= '\0';
	}
	return '\0';
}