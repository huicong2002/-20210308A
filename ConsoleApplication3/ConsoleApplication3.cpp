#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct JieMu {
	int StartTime;
	int EndTime;
}Arr[102];
int main()
{
	int a, b, c;

	int n, i, j, X;

	struct JieMu temp;

	while (scanf("%d", &n))
	{
		if (n == 0) {
			break;
		}
		X = 1;
		for (i = 1; i <= n; i++)
		{
			scanf("%d%d", &a, &b);

			Arr[i].StartTime = a;
			Arr[i].EndTime = b;

		}

		for (i = 1; i < n; i++)
		{
			for (j = 1; j < n - i; j++)
			{
				if (Arr[j].EndTime > Arr[j + 1].EndTime)
				{
					temp = Arr[j];
					Arr[j] = Arr[j + 1];
					Arr[j + 1] = temp;
				}
			}
		}

		int End;

		End = Arr[1].EndTime;

		for (i = 2; i <= n; i++)
		{
			if (End <= Arr[i].StartTime)
			{
				End = Arr[i].EndTime;
				X++;
			}
		}
		printf("%d\n", X);
	}

	return 0;
}