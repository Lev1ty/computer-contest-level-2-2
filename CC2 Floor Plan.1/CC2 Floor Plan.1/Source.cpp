#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
char grid[27][27];
bool vis[27][27];
int tot, r, c, cnt, trav[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
vector<int>area;
int dfs(int rr, int cc) {
	int accum = 1; vis[rr][cc] = true;
	for (int i = 0; i < 4; i++) {
		int nr = rr + trav[i][0]; int nc = cc + trav[i][1];
		if (nr >= 1 && nr <= r&&nc >= 1 && nc <= c&&grid[nr][nc] == '.'&&!vis[nr][nc]) {
			accum+=dfs(nr, nc);
		}
	}
	return accum;
}
int main() {
	cin >> tot >> r >> c;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			cin >> grid[i][j];
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (grid[i][j] == '.'&&!vis[i][j]) {
				area.push_back(dfs(i, j));
			}
		}
	}
	sort(area.begin(), area.end());
	for (int i = area.size() - 1; i >= 0; i--) {
		if (tot>=area[i]) {
			cnt++; tot -= area[i];
		}
		else break;
	}
	cout << cnt << (cnt == 1 ? " room, " : " rooms, ") << tot << " square metre(s) left over" << endl;
}