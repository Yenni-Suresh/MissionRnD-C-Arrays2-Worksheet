/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int giveyear(char *date)
{
	int i = 9,year=0,p=1;
	while (i >= 6)
	{
		year = year + (date[i] - '0') * p;
		p = p * 10;
		i--;
	}
	return year;
}
int givemonth(char *date)
{
	int month;
	month = date[4] - '0';
	month = month + (date[3] - '0') * 10;
	return month;
}
int giveday(char *date)
{
	int day;
	day = date[1] - '0';
	day = day + (date[0] - '0') * 10;
	return day;
}
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int day, mon, year, i=0,j,temp;
	year = giveyear(date);
	mon = givemonth(date);
	day = giveday(date);
	while (i < len)
	{
		temp = giveyear(Arr[i].date);
		if (temp >= year)
		{
			if (temp > year)
				return len - i;
		}
		else{
			i++;
			continue;
		}
		temp = givemonth(Arr[i].date);
		if (temp >= mon)
		{
			if (temp > mon)
				return len - i;
		}
		else{
			i++;
			continue;
		}
		temp = giveday(Arr[i].date);
		if (temp >= day)
		{
			if (temp > day)
				return len - i;
		}
		i++;
	}
	return 0;
}
