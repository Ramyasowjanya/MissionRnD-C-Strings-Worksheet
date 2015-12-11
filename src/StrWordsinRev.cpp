/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void rev_the_words(char *str, int start, int end)
{
	int index; char temp;
	for (index = start; index <= end / 2; index++)
	{
		temp = str[index];
		str[index] = str[end - index];
		str[end - index] = temp;
	}
}

void str_words_in_rev(char *input, int len){
	int temp = 0, index, flag = 0,space=0;
	if (input != NULL)
	{
		for (index = 0; index < len; index++)
		{
			if (input[index] == ' ')
			{
				space = index;
				flag++;
			}
			else
			{
				if (flag != 0)
				{
					rev_the_words(input, temp, temp + space - flag);
					temp = space + 1;
					flag = 0;
				}
			}
		}
		rev_the_words(input, temp, temp + len - 1);
		rev_the_words(input, 0, len - 1);
	}
}
