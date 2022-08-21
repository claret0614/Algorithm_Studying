#include <iostream>
#include <queue>
using namespace std;

priority_queue<int>MaxHeap;
priority_queue<int, vector<int>, greater<int>>MinHeap;
int mid;

void push(int score) {
	if (mid > score) {
		MaxHeap.push(score);
	}
	else {
		MinHeap.push(score);
	}
}

int main() {
	int n;
	cin >> n;

	mid = 500;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		push(a);
		push(b);

		if (MaxHeap.size() > MinHeap.size()) {
			MinHeap.push(mid);
			mid = MaxHeap.top();
			MaxHeap.pop();
		}
		else if (MaxHeap.size() < MinHeap.size()) {
			MaxHeap.push(mid);
			mid = MinHeap.top();
			MinHeap.pop();
		}
		cout << mid << "\n";
	}
}