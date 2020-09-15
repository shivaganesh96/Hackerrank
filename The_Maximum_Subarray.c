//Problem Statement link:https://www.hackerrank.com/challenges/maxsubarray/submissions/code/32157522

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int max(int a, int b)
{
	if (a>b)
	{
		return a;
	}
	else
		return b;
}


/* Enter your code here. Read input from STDIN. Print output to STDOUT */
int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	int queries;

	int i;
	scanf("%d", &queries);
	for (i = 0; i<queries; i++)
	{
		int n;
		int nsum = 0;
		int check = 0, curr_max, sum, sum1 = 0, sum2 = 0, sum3;
		scanf("%d", &n);
		int a[n], hold[n];
		for (int k = 0; k<n; k++)
		{

			scanf("%d", &a[k]);
			//non contiguous
			if (a[k]>0)
			{
				sum1 += a[k];
			}
			else
			{
				if (check == 0 || sum2<a[k])
				{
					sum2 = a[k];
					check = 1;
				}
			}

			//contiguous
			if (k != 0)
			{
				curr_max = max(a[k], curr_max + a[k]);
				sum = max(sum, curr_max);
			}
			else
			{
				curr_max = a[0]; sum = a[0];
			}

		}
		if (sum1 == 0)
		{
			sum3 = sum2;
		}
		else
		{
			sum3 = sum1;
		}

		printf("%d %d\n", sum, sum3);




	}
	return 0;
}
 
