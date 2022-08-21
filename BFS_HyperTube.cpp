#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int Node, HEdge, HNode;
	cin >> Node >> HEdge >> HNode;

	vector<int>tube[200000];

	for (int i = 1; i <= HNode; i++) {
		for (int j = 0; j < HEdge; j++) {
			int to;
			cin >> to;
			tube[i + Node].push_back(to);
			//하이퍼 노드의 노드 번호는 기본 역 노드 번호 이후부터 개수만큼 할당
			tube[to].push_back(i + Node);
		}
	}

	int visited[200000] = { 0, };
	queue<int>Q;

	visited[1] = 1;
	Q.push(1);
	int cnt = 0;

	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();

		// 방문하는 역의 수 출력하기(경로의 전체 노드 수 - 거쳐온 하이퍼튜브 노드 수)
		// 하이퍼튜브를 카운트하되, 최소 환승 경로에 있는 하이퍼 튜브만
		// 최소 환승의 경우를 세면서, 그 경로의 하이퍼 튜브를 카운트

		for (int i = 0; i < tube[now].size(); i++) {
			int next = tube[now][i];
			if (visited[next] >= 1) {
				continue;
			}

			visited[next] = visited[now] + 1;
			Q.push(next);

		}
	}

	if (visited[Node] == 0) {
		cout << "-1";
	}
	else {
		cout << visited[Node] / 2 + 1;
	}
}