#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t = 1;
	printf("%d\n", t);
	while (t--)
	{
		long long x = 0;
		int n = 10000;
		printf("%d\n", n);
		for (int i = 0; i < n; i++)
			printf("%010lld\n", x++);
	}
}