#include <iostream>
#include <queue>
using namespace std;

struct pt {
	int y, x;
};

int map[101][101];

int main() {
	int height, width;
	cin >> height >> width;

	pt seed1, seed2;
	cin >> seed1.y >> seed1.x >> seed2.y >> seed2.x;

	queue<pt>Q;
	Q.push({ seed1.y,seed1.x });
	Q.push({ seed2.y,seed2.x });
	map[seed1.y][seed1.x] = 1;
	map[seed2.y][seed2.x] = 1;

	int ans = 0;

	while (!Q.empty()) {
		pt now = Q.front();
		Q.pop();

		int dirY[4] = { -1,0,1,0 };
		int dirX[4] = { 0,1,0,-1 };
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dirY[i];
			int nx = now.x + dirX[i];

			if (ny < 0 || nx < 0 || ny >= height || nx >= width) {
				continue;
			}
			if (map[ny][nx] != 0) {
				continue;
			}

			map[ny][nx] = map[now.y][now.x] + 1;
			ans = map[ny][nx];
			Q.push({ ny,nx });
		}
	}

	cout << ans;

}