#include <stdio.h>

const int MAX_N = 100;
const int MAX_M = 200;

int N, M;
double x[MAX_M];

bool check(double d) 
{
	int old = 0;

	for(int i = 1; i < N; i++) 
	{
		int n = old + 1;

		while(n < M && x[n] - x[old] < d) n++;

		if (n == M) return false;
		old = n;
	}

	return true;
}

int main()
{
	int c;

	scanf("%d", &c);

	while(c--)
	{
		scanf("%d %d", &N, &M);

		for(int i = 0; i < M; i++)
		{
			scanf("%lf", &x[i]);
		}

		double l = 0, r = 2*(x[M-1] - x[0]);

		while(r > l + 0.001) 
		{
			double mid = (l + r) / 2;

			if (check(mid)) l = mid;
			else r = mid;
		}

		printf("%.2lf\n", l);
	}

	return 0;
}

