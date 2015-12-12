/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31
int length_of_string(char *str,int *spacecount)
{
	int len = 0; spacecount = 0;
	while (*str != '\0')
	{
		len++;
		if (*str == ' ')
			spacecount++;
		str++;
	}
	return len;
}
int compare(char* str1,int start1,char* str2,int start2, int len)
{
	int comparevalue = 0;
	while (len > 0)
	{
		if (str1[start1 + len] == str2[start2 + len])
			comparevalue = 1;
		else
			comparevalue = 0;
		len--;
	}
	return comparevalue;
}
char ** commonWords(char *str1, char *str2) {
	char** commonwords = NULL;
	int index, index1, len1, len2, temp = 0, temp1 = 0, retvalue = 0, spacecount1 = 0, spacecount2 = 0, commonindex = 0, index2;
	if (str1 != NULL &&str2 != NULL)
	{
		len1 = length_of_string(str1, &spacecount1);
		len2 = length_of_string(str2, &spacecount2);
		if (spacecount1<spacecount2)
			commonwords = (char**)malloc((spacecount1 + 1)*sizeof(char*));
		else
			commonwords = (char**)malloc((spacecount2 + 1)*sizeof(char*));
		for (index = 0; index < len1; index++)
		{
			if (str1[index] == ' ')
			{
				if (index != 0 && str1[index + 1] != ' ')
				{
					temp1 = 0;
					for (index1 = 0; index1 < len2; index1++)
					{
						if (' ' == str2[index1])
						{
							if (index - temp == index1 - temp1)
							{
								retvalue = compare(str1, temp, str2, temp1, index1 - temp1 - 1);
								if (retvalue == 1)
								{
									commonwords[commonindex] = (char*)malloc((index - temp)*sizeof(char));
									for (index2 = 0; index2 < (index - temp); index2++)
									{
										commonwords[commonindex][index2] = str1[temp + index2];
									}
									commonindex++;
								}
							}
							temp1 = index1 + 1;
						}
					}
					temp = index + 1;
				}
			}
		}
		if (commonindex != 0)
			return commonwords;
	}
	return NULL;
}