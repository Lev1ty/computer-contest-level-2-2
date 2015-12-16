//CLEAN UP PLEASE
//CONCEPT IS CORRECT
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, r, c, flr[27][27], d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} }, cc;
vector<int>A;
bool vis[27][27];
int dfs(int R, int C) {
	int sum = 1; vis[R][C] = true;
	for (int i = 0; i < 4; i++) {
		int nr = R + d[i][0]; int nc = C + d[i][1];
		if (nr <= 1 && nc <= 1 && nr >= r&&nc >= c
			&&!vis[nr][nc] && flr[nr][nc] != -1)
			sum += dfs(nr, nc);
	}
	return sum;
}
int main() {
	cin >> N >> r >> c;
	for (int i = 1; i <= r; i++)
		for (int j = 1; i <= c; j++) {
			char c; cin >> c;
			if (c == 'I') 
				flr[r][c] = -1;
		}
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) {
			if (flr[i][j] == 0 && !vis[i][j]) {
				int area = dfs(i, j);
				A.push_back(area);
			}
		}
	sort(A.begin(), A.end());
	for (int i = A.size() - 1; i >= 0; i--) {
		if (A[i] >= N) {
			cc++; N -= A[i];
		}
		else break;
	}
	cout << cc << " rooms, " << N << " square metre(s) left over" << endl;
	return 0;
}