#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void) {
	int count;
	int arr[10001] = { 0, };
	int temp;

	scanf("%d", &count);

	for (int i = 1; i <= count; i++) {
		scanf("%d", &temp);
		arr[temp]++;
	}

	for (int i = 1; i <= 10000; i++) {
		for (int j = 1; j <= arr[i]; j++) {
			printf("%d\n", i);
		}
	}
	return 0;
}