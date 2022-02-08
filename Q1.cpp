#include <bits/stdc++.h>
using namespace std;

int countWays(int index, int cnt, int dp[][max], int n, int m){
	if (index == n) {
		if (cnt == 0)
			return 1;
		else
			return 0;
	}
	if (dp[index][cnt] != -1)
		return dp[index][cnt];

	int ans = 0;
	ans += countWays(index + 1, cnt, dp, n, m);
	ans += (m - 1) * countWays(index + 1, cnt + 1, dp, n, m);
	return dp[index][cnt] = ans;
}
int main()
{
	int n = 3, m = 2;
	int dp[n + 1][n];
	memset(dp, -1, sizeof dp);
	cout << m * countWays(1, 0, dp, n, m);
}
