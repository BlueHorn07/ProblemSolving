#include<bits/stdc++.h>
using namespace std;
int C, N;
char board[5][5];

// 종만북의 코드와 비교하면, 개선할 점이 많은 코드입니다 ㅠㅠ

bool dfs(int y, int x, string query) {
	if (query.length() == 0) {
		return true;
	}

	if ((board[y][x] != query[0])) {
		return false;
	}

	string next_query = query.substr(1);

	bool out = false;

	if (0 <= y - 1) {
		out = dfs(y - 1, x, next_query);
		if (out) return out;
		if (0 <= x - 1) {
			out = dfs(y - 1, x - 1, next_query);
			if (out) return out;
		}
		if (x + 1 < 5) {
			out = dfs(y - 1, x + 1, next_query);
			if (out) return out;
		}
	}

	if (y + 1 < 5) {
		out = dfs(y + 1, x, next_query);
		if (out) return out;
		if (0 <= x - 1) {
			out = dfs(y + 1, x - 1, next_query);
			if (out) return out;
		}
		if (x + 1 < 5) {
			out = dfs(y + 1, x + 1, next_query);
			if (out) return out;
		}

		if (0 <= x - 1) {
			out = dfs(y, x - 1, next_query);
			if (out) return out;
		}

		if (x + 1 < 5) {
			out = dfs(y, x + 1, next_query);
			if (out) return out;
		}
		return out;
	}
}

void testCase() {
	for (int i = 0; i < 5; i++) {
		scanf("%s", board[i]);
	}

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		string query;
		cin >> query;

		bool out = false;
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				out = dfs(y, x, query);
				if (out) {
					break;
				}
			}
			if (out) {
				break;
			}
		}

		if (out) {
			cout << query << " YES" << endl;
		}
		else {
			cout << query << " NO" << endl;
		}

	}
}

int main() {
	scanf("%d", &C);

	for (int i = 0; i < C; i++) {
		testCase();
	}

	return 0;
}