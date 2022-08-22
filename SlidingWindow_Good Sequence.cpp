#include <iostream>
using namespace std;

int main() {
	string number;
	cin >> number;
	int leng = (number.length()) / 2;
	int ans = 0;

	// 투 포인터, sliding window?

	for (int window = 1; window <= leng; window++) {
		int left = 0;
		int right = left + window;
		int sum_left = 0;
		int sum_right = 0;
		for (int i = 0; i < window; i++) {
			sum_left += (int)(number[i] - '0');
			sum_right += (int)(number[i + window] - '0');

			while (right <= leng) {
				if (sum_left != sum_right) {
					sum_left -= number[left] - '0';
					left++;
					sum_left += number[right] - '0';
					sum_right -= number[right] - '0';
					right++;
					sum_right += number[right + window - 1] - '0';
				}
				else {
					ans = window;
					sum_left -= number[left] - '0';
					left++;
					sum_left += number[right] - '0';
					sum_right -= number[right] - '0';
					right++;
					sum_right += number[right + window - 1] - '0';
				}
			}
		}
	}
	if (number.length() % 2 == 0) {
		cout << ans;
	}
	else {
		cout << ans - 1;
	}
}