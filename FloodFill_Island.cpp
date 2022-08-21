#include <iostream>
#include <queue>
using namespace std;

int n, m;
int MAP[101][101];
int visited[101][101];
int dirY[4] = { -1,0,1,0 };
int dirX[4] = { 0,1,0,-1 };
struct pt {
	int y, x;
};

void bfs(int y, int x) {
	queue<pt>Q;
	Q.push({ y,x });
	visited[y][x] = 1;

	while (!Q.empty()) {
		pt now = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = dirY[i] + now.y;
			int nx = dirX[i] + now.x;

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
				continue;
			}
			if (MAP[ny][nx] == 0) {
				continue;
			}
			if (visited[ny][nx] == 1) {
				continue;
			}

			visited[ny][nx] = 1;
			Q.push({ ny,nx });
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (MAP[i][j] == 0) {
				continue;
			}
			if (visited[i][j] == 1) {
				continue;
			}
			// MAP에서 1을 만나면 그것을 시작점으로 bfs를 돌림 (1이 있는 곳만 따라감)
			bfs(i, j);
			// 1로 이어진 한 덩어리를 찾은 후에는 덩어리 개수 카운트
			ans++;
		}
	}
	cout << ans;
}