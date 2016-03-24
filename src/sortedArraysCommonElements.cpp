/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int giveyr(char *date)
{
	int i = 9, year = 0, p = 1;
	while (i >= 6)
	{
		year = year + (date[i] - '0') * p;
		p = p * 10;
		i--;
	}
	return year;
}
int givemon(char *date)
{
	int month;
	month = date[4] - '0';
	month = month + (date[3] - '0') * 10;
	return month;
}
int givedy(char *date)
{
	int day;
	day = date[1] - '0';
	day = day + (date[0] - '0') * 10;
	return day;
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A==nullptr||B==nullptr||ALen<1||BLen<1)
	   return NULL;
	int aday, amon, ayear, bday, bmon, byear, i=0, j,k=-1,l;
	while (i < BLen)
	{
		aday = givedy(B[i].date);
		amon = givemon(B[i].date);
		ayear = giveyr(B[i].date);
		for (j = 0; j < ALen; j++)
		{
			bday = givedy(A[j].date);
			bmon = givemon(A[j].date);
			byear = giveyr(A[j].date);
			if (aday == bday&&amon == bmon&&ayear == byear)
			{
				if (k != j)
				{
					k++;
					for (l = 0; l < 10; l++)
						B[k].date[l] = A[j].date[l];
					B[k].date[l] = '\0';
				}
			}
			else {
				if (ayear >= byear)
					if (amon >= bmon)
						if (aday >= bday)
							break;
			     }
		}
		i++;
	}
	if (k==-1)
	return NULL;
	else return B;
}