/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int givey(char *date)
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
int givem(char *date)
{
	int month;
	month = date[4] - '0';
	month = month + (date[3] - '0') * 10;
	return month;
}
int gived(char *date)
{
	int day;
	day = date[1] - '0';
	day = day + (date[0] - '0') * 10;
	return day;
}
char compare(char *A, int a, char *B, int b)
{
	int ad, am, ay, bd, bm, by;
	ad = gived(A);
	am = givem(A);
	ay = givey(A);
	bd = gived(B);
	bm = givem(B);
	by = givey(B);
	if (ad == bd&&am == bm&&ay == by)
		return 'e';
	else if (ay >= by)
	{
		if (ay > by)
			return 'a';
		else if (am >= bm)
		{
			if (am > bm)
				return 'a';
			else if (ad > bd)
				return 'a';
			else return 'b';
		}
		else 'b';
	}
	else return 'b';
}
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A==nullptr||B==nullptr)
	 return NULL;
	struct transaction *result;
	result = (transaction*)malloc((ALen + BLen)*sizeof(transaction));
	int i=0,j=0,k=0,d;
	while (i < (ALen + BLen))
	{
		while (j<ALen&&k<BLen&&compare(A[j].date, j, B[k].date, k) == 'a')
		{
			result[i++].amount = B[k++].amount;
		}
		while (j < ALen&&k < BLen&&compare(A[j].date, j, B[k].date, k) == 'b')
		{
			result[i++].amount = A[j++].amount;
		}
		while (j < ALen&&k < BLen&&compare(A[j].date, j, B[k].date, k) == 'e')
		{
			result[i++].amount = A[j++].amount;
			result[i++].amount = B[k++].amount;
		}
		while (j == ALen&&k < BLen)
		{
			result[i++].amount = B[k++].amount;
		}
		while (k == BLen&&j < ALen)
		{
			result[i++].amount = A[j++].amount;
		}
	}
	return result;
}