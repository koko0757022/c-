#include <iostream>
#include <string>

using namespace std;

int main() {
	int input;
	int cnt = 1;
	int maxNum = 1;
	int maxCount = 0;

	cin >> input;
	while (1) {
		if (input <= maxNum) {
			break;
		}

		maxCount += 6;
		maxNum += maxCount;
		cnt++;
	}
	cout << cnt << endl;
}
