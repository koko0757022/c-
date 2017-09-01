#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int max(int x, int y) {
	return (x > y ? x : y);

}
int main(void) {
	int arr[301] = { 0, };
	int check[301] = { 0, };
	int num;

	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= 3 && i <= num; i++) {

		if (i != 3) {
			check[i] = arr[i] + arr[i - 1];
		}
		else {
			check[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
		}
	}

	for (int i = 4; i <= num; i++) {
		check[i] = max(arr[i] + check[i - 2], arr[i] + arr[i] + check[i - 3]);
	}
	printf("%d\n", check[num]);
	return 0;
}