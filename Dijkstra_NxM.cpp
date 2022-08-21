#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[101][101];
int dist[101][101];
int check[101][101];
int dirY[4] = { -1,0,1,0 };
int dirX[4] = { 0,1,0,-1 };

struct pt {
	int from, to, cost;
};

bool operator<(pt A, pt B) {
	if (A.cost < B.cost)return false;
	if (A.cost > B.cost)return true;
	return false;
}

void dijkstra() {
	priority_queue<pt>PQ;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dist[i][j] = 2134567890;
		}
	}

	PQ.push({ 1,1,map[1][1] });
	dist[1][1] = map[1][1];

	while (!PQ.empty()) {
		pt now = PQ.top();
		PQ.pop();

		if (check[now.from][now.to] == 1) {
			continue;
		}
		check[now.from][now.to] = 1;

		for (int i = 0; i < 4; i++) {
			int ny = now.from + dirY[i];
			int nx = now.to + dirX[i];

			if (ny < 1 || nx < 1 || ny > n || nx > m) {
				continue;
			}
			if (check[ny][nx] == 1) {
				continue;
			}
			if (dist[ny][nx] <= dist[now.from][now.to] + map[ny][nx]) {
				continue;
			}

			dist[ny][nx] = dist[now.from][now.to] + map[ny][nx];
			PQ.push({ ny,nx,dist[ny][nx] });
		}
	}

	cout << dist[n][m];
}

int main() {
	cin >> n >> m;

	// 시작점이 (1,1)인 것에 주의
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	dijkstra();
}