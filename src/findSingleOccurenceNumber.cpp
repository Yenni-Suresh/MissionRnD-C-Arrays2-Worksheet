/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

int findSingleOccurenceNumber(int *A, int len) {
	if (A==nullptr||len<1)
	return -1;
	int i=1, j=0, count=1;
		while (i<len)
		{
			if (A[i] == A[j])
			{
				count++;
				if (i != j + 1)
				{
					A[j + 1] = A[j + 1] + A[i];
					A[i] = A[j + 1] - A[i];
					A[j + 1] = A[j + 1] - A[i];
				}
				j++;
			}
			if (count == 3)
			{
				j++;
				count = 1;
				i = j;
			}
			i++;
		}
		return A[j];
}