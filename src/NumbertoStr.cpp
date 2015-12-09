/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>


int reverseOfNumber(int number)
{
	int reverse = 0;
	while (number>0)
	{
		reverse = (reverse * 10) + (number % 10);
		number = number / 10;
	}
	return reverse;
}
void number_to_str(float number, char *str, int afterdecimal){
	int beforeDecimal, index = 0, temp, afterDecimal;
	beforeDecimal = (int)number;
	number = number - beforeDecimal;
	if (beforeDecimal<0)
	{
		beforeDecimal = -beforeDecimal;
		str[index] = '-';
		index++;
	}
	if (number<0)
	{
		number = -number;
	}
	beforeDecimal = reverseOfNumber(beforeDecimal);
	while (beforeDecimal>0)
	{
		str[index] = (beforeDecimal % 10) + '0';
		beforeDecimal = beforeDecimal / 10;
		index++;
	}
	if (afterdecimal > 0)
	{
		str[index] = '.';
		index++;
		temp = afterdecimal;
		while (afterdecimal > 0)
		{
			number = number * 10;
			afterdecimal--;
		}
		afterDecimal = (int)number;
		index = index + temp - 1;
		while (afterDecimal>0)
		{
			str[index] = (afterDecimal % 10) + '0';
			afterDecimal = afterDecimal / 10;
			index--;
		}
	}
}
