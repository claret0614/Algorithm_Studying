#include <iostream>
#include <vector>
using namespace std;

vector<int>winner[100001];
int visitedUp[100001];
vector<int>loser[100001];
int visitedDown[100001];

int up = 1;
int down = 1;

void dfs_up(int target) {
	for (int i = 0; i < winner[target].size(); i++) {
		int next = winner[target][i];
		if (visitedUp[next] == 1) {
			continue;
		}
		up++;
		visitedUp[next] = 1;
		dfs_up(next);
	}
}

void dfs_down(int target) {
	for (int i = 0; i < loser[target].size(); i++) {
		int next = loser[target][i];
		if (visitedDown[next] == 1) {
			continue;
		}
		down++;
		visitedDown[next] = 1;
		dfs_down(next);
	}
}

int main() {
	int n, m, x;
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		winner[b].push_back(a);
		loser[a].push_back(b);
	}

	dfs_up(x);
	dfs_down(x);

	cout << up << "\n" << n - down + 1;
}