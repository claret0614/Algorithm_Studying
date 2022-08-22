#include <iostream>
#include <queue>
using namespace std;

struct pt {
	int y, x;
};

int dirY[8] = { 3,2,-2,-3,-3,-2,2,3 };
int dirX[8] = { 2,3,3,2,-2,-3,-3,-2 };

int main() {
	int h, w;
	cin >> h >> w;

	int ry, rx, by, bx;
	cin >> ry >> rx >> by >> bx;

	int n;
	cin >> n;

	int map[101][101] = { 0, };
	for (int i = 0; i < n; i++) {
		int row, col;
		cin >> row >> col;
		// 쫄의 위치에는 1로 기록
		map[row][col] = 1;
	}

	queue<pt>Q;
	Q.push({ ry, rx });
	map[ry][rx] = 1;
	// 파란색 장기말의 위치에는 -1로 기록
	map[by][bx] = -1;
	int flag = 0;

	while (!Q.empty()) {
		pt now = Q.front();
		Q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = dirY[i] + now.y;
			int nx = dirX[i] + now.x;

			// 장기판 범위를 벗어나면 무시
			if (ny < 0 || nx < 0 || ny >= h || nx >= w) {
				continue;
			}
			// 지점에 무언가 있거나, 이미 지나온 지점이라면 무시
			if (map[ny][nx] > 0) {
				continue;
			}
			// 지점에 파란색 차가 있다면 flag = 1;
			if (map[ny][nx] == -1) {
				flag = 1;
			}
			map[ny][nx] = map[now.y][now.x] + 1;
			Q.push({ ny,nx });
		}
	}

	// flag == 1 (파란색 차를 잡음)이면 출력
	if (flag == 1) {
		cout << map[by][bx] - 1;
	}
	// flag == 0 (파란색 차를 잡지 못함)이면 -1 출력
	else {
		cout << -1;
	}
}