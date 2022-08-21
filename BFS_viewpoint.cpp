#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge {
	int to, cost;
};

vector<edge>trip[100001];
queue<edge>Q;
int visited[100001];
long long sum[100001];

int main() {
	int viewpoint, bridge, HP;
	cin >> viewpoint >> bridge >> HP;

	for (int i = 0; i < bridge; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		//단방향
		trip[from].push_back({ to,cost });
	}

	// 1번에서 출발
	Q.push({ 1,0 });
	visited[1] = 1;
	// sum[i] = i번 노드에 갈 때 소모되는 체력 합
	sum[1] = 0;

	// BFS
	while (!Q.empty()) {
		edge now = Q.front();
		Q.pop();

		for (int i = 0; i < trip[now.to].size(); i++) {
			edge next = trip[now.to][i];
			if (visited[next.to] == 1) {
				continue;
			}
			sum[next.to] = sum[now.to] + next.cost;
			visited[next.to] = 1;
			Q.push({ next.to,next.cost });
		}
	}

	// 소모 체력 합이 HP보다 낮은 경우 세기
	int cnt = 0;
	for (int i = 1; i <= viewpoint; i++) {
		if (sum[i] == 0) {
			continue;
		}
		else if (sum[i] > HP) {
			continue;
		}
		else {
			cnt++;
		}
	}

	cout << cnt;
}