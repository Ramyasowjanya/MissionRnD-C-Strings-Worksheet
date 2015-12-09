/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/

int lengthOfString(char *str)
{
	int len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return len;
}
char KthIndexFromEnd(char *str, int k) {
	int length = 0; char returnChar;
	if (str)
	{
		length = lengthOfString(str);
		if (k > length || k < 0)
			return '\0';
		returnChar = str[length - k - 1];
		return returnChar;
	}
	return '\0';
}