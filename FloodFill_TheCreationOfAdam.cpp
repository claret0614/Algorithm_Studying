#include <iostream>
#include <queue>
using namespace std;

string picture[8];
int visited[8][9];
int dirY[4] = { -1,0,1,0 };
int dirX[4] = { 0,1,0,-1 };

struct pt {
	int y, x;
};

queue<pt>Q2;

// (0,8)의 사람에서 출발하여,
// 이 사람이 있는 최대 위치(#이 끝나고 _이 시작되는 좌표)를 Q2에 넣어주는 bfs
void bfs1() {
	queue<pt>Q1;
	Q1.push({ 0,8 });

	while (!Q1.empty()) {
		pt now = Q1.front();
		Q1.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dirY[i];
			int nx = now.x + dirX[i];

			if (ny < 0 || nx < 0 || ny >= 8 || nx >= 9) {
				continue;
			}
			if (visited[ny][nx] != 0) {
				continue;
			}
			if (picture[ny][nx] == '_') {
				visited[ny][nx] = 1;
				// 사람 1을 한 칸 벗어난 지점을 Q2의 시작점으로 넣는다.
				Q2.push({ ny,nx });
				continue;
			}

			Q1.push({ ny,nx });
			visited[ny][nx] = visited[now.y][now.x] + 1;
		}
	}
}

// (0,8)의 사람을 막 벗어난 위치(_)로부터
// (7,0)에 위치한 사람(#)을 만날 때까지 진행되는 bfs
void bfs2() {
	while (!Q2.empty()) {
		pt now = Q2.front();
		Q2.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dirY[i];
			int nx = now.x + dirX[i];

			if (ny < 0 || nx < 0 || ny >= 8 || nx >= 9) {
				continue;
			}
			if (visited[ny][nx] != 0) {
				continue;
			}
			if (picture[ny][nx] == '#') {
				cout << visited[now.y][now.x];
				return;
			}

			Q2.push({ ny,nx });
			visited[ny][nx] = visited[now.y][now.x] + 1;
		}
	}
}

int main() {
	for (int i = 0; i < 8; i++) {
		cin >> picture[i];
	}

	bfs1();
	bfs2();
}