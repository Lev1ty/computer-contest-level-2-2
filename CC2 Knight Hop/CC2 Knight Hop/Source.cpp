#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct POINT { int r, c; };
int dis[10][10], mov[8][2] = { {1,2},{2,1},{2,-1},{1,-2},{-2,1},{-1,2},{-2,-1},{-1,-2} }, endr, endc;
queue<POINT>Q;
int main() {
	POINT p; cin >> p.r >> p.c >> endr >> endc;
	memset(dis, -1, sizeof(dis));
	Q.push(p); dis[p.r][p.c] = 0;
	while (!Q.empty()) {
		int r = Q.front().r;int c = Q.front().c;Q.pop();
		for (int i = 0; i < 8; i++) {
			int nr = r + mov[i][1];int nc = c + mov[i][0];
			if (nr >= 1 && nc >= 1 && nr <= 8 && nc <= 8 && dis[nr][nc] == -1) {
				p.r = nr; p.c = nc; Q.push(p);
				dis[nr][nc] = dis[r][c] + 1;
			}
		}
	}
	/*for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << dis[i][j];
		cout << endl;
	}*/
	cout << dis[endr][endc] << endl;
}