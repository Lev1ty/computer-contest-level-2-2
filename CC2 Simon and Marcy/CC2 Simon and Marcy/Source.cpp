#include <iostream>
#include <algorithm>
using namespace std;
short c, m, n, k, val[1002], timee[1002], dp[2][1002];
int main()
{
	cin >> c >> m; 
	for (unsigned short i = 1; i <= c; ++i) {
		cin >> n >> k;
		val[i] = n; timee[i] = k;
	}
	for (unsigned short i = 1, k = 0; i <= c; ++i) {
		for (unsigned short j = timee[i]; j <= m; ++j) dp[1][j] = max(dp[0][j], (short)(val[i] + dp[0][j - timee[i]]));
		for (unsigned short l = timee[i]; l <= m; ++l) dp[0][l] = max(dp[0][l], dp[1][l]);
	}
	cout << dp[1][m] << endl;
}