#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
	int to, cost;
};

int city;
vector<Edge>road[1001];

bool operator<(Edge a, Edge b) {
	if (a.cost < b.cost) return false;
	if (a.cost > b.cost) return true;
	return false;
}

void dijkstra(int start, int destination) {

	priority_queue<Edge>PQ;

	int visited[1001] = { 0, };
	int dist[1001];
	for (int i = 0; i <= city; i++) {
		dist[i] = 2134567890;
	}
	dist[start] = 0;

	PQ.push({ start,0 });

	while (!PQ.empty()) {
		Edge now = PQ.top();
		PQ.pop();

		if (visited[now.to] == 1) {
			continue;
		}
		visited[now.to] = 1;

		for (int i = 0; i < road[now.to].size(); i++) {
			Edge next = road[now.to][i];
			if (dist[next.to] < dist[now.to] + next.cost) {
				continue;
			}
			dist[next.to] = dist[now.to] + next.cost;
			PQ.push({ next.to,dist[next.to] });
		}
	}
	cout << dist[destination] << "\n";
}

int main() {
	int highway, year, cityA, cityB;
	cin >> city >> highway >> year >> cityA >> cityB;

	for (int i = 0; i < highway; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		//양방향
		road[from].push_back({ to,cost });
		road[to].push_back({ from,cost });
	}

	// 세금 올리기 전 첫 해 dijkstra
	dijkstra(cityA, cityB);

	for (int i = 0; i < year; i++) {
		int tax;
		cin >> tax;
		for (int j = 0; j <= city; j++) {
			for (int k = 0; k < road[j].size(); k++) {
				road[j][k].cost += tax;
			}
		}
		// 세금이 누적된 이후의 dijkstra
		dijkstra(cityA, cityB);
	}
}