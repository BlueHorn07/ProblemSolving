#include<bits/stdc++.h>
#define MAX 1024

using namespace std;

int C, N, L;
int arr[MAX];

long long findMinSum(int length) {
	long long sum = 0;
	for (int j = 0; j < length; j++) {
		sum += arr[j];
	}

	long long minSum = sum;

	for (int k = length; k < N; k++) {
		sum -= arr[k - length];
		sum += arr[k];
		minSum = min(minSum, sum);
	}
	return minSum;
}


int main() {
	scanf("%d", &C);

	for (int i = 0; i < C; i++) {
		scanf("%d %d", &N, &L);
		
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[j]);
		}

		double minMean = LDBL_MAX_10_EXP;

		for (int k = L; k <= N; k++) {
			long long out = findMinSum(k);
			minMean = min(minMean, (double) out / (double) k);
		}

		printf("%.10f\n", minMean); // 소수점 유효자리 중요!
	}

	return 0;
}