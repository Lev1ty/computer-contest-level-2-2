#include <iostream>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int N, H, g[1502][1502], dis[1502][1502];
int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
inline void read(int &x) {
	char c;
	while (c = getchar(), c<'0' || c>'9'); x = c - '0';
	while (c = getchar(), c >= '0'&&c <= '9')x = x * 10 + c - '0';
}
int main() {
	read(N), read(H);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N;j++)
			read(g[i][j]);
	queue<pii>Q;
	Q.push(make_pair(1, 1)); dis[1][1] = 1;
	while (!Q.empty()) {
		int r = Q.front().first, c = Q.front().second; Q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + d[i][0];int nc = c + d[i][1];
			if (nr >= 1 && nr <= N&&nc >= 1 && nc <= N&&dis[nr][nc] == 0 && abs(g[r][c] - g[nr][nc]) <= H) {
				Q.push(make_pair(nr, nc));
				dis[nr][nc] = dis[r][c] + 1;
			}
		}
	}
	if (dis[N][N]) printf("yes\n");
	else printf("no\n");
}