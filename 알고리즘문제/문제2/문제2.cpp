#include <iostream>
#include <string>

using namespace std;

int main() {
	int input;
	int cnt = 1;
	int maxNum = 1;
	int maxCount = 1;

	cin >> input;

	while (1) {
		if (input <= maxNum) {
			break;
		}

		maxCount += 1;
		maxNum += maxCount;
		cnt++;
	}
	//cout << cnt << endl;
	//cout << maxNum << endl;
	if (cnt % 2 == 1) {
		int i = maxNum - input;
		cout << (1 + i) << "/" << (cnt - i) << endl;
	}

	else if (cnt % 2 == 0) {
		int i = maxNum - input;
		cout << (cnt - i) << "/" << (1 + i) << endl;
	}
}
