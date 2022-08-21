#include <iostream>
using namespace std;

int n, m;
int path[6];
int DAT[7];
void tree(int level) {
	if (m == 2) {
		for (int i = 0; i < n; i++) {
			if (path[i] > path[i + 1]) {
				continue;
			}
		}
	}

	if (level == n) {
		for (int i = 0; i < n; i++) {
			cout << path[i] << " ";
		}
		cout << '\n';
		return;
	}

	if (m == 1) {
		for (int i = 1; i <= 6; i++) {
			path[level] = i;
			tree(level + 1);

			path[level] = 0;
		}
	}
	else if (m == 2) {
		for (int i = 1; i <= 6; i++) {
			if (level > 0) {
				if (path[level - 1] > i)
					continue;
			}
			path[level] = i;
			DAT[i] = 1;
			tree(level + 1);

			path[level] = 0;
			DAT[i] = 0;
		}
	}
	else if (m == 3) {
		for (int i = 1; i <= 6; i++) {
			if (DAT[i] == 1)
				continue;
			path[level] = i;
			DAT[i] = 1;
			tree(level + 1);

			path[level] = 0;
			DAT[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	tree(0);
}
