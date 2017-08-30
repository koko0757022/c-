#define _CRT_SECURE_NO_WARNINGS
#define BUCKETS 10
#define DIGITS 4


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


typedef int element;
typedef struct QueueNode {
	element item;
	struct QueueNode *link;
}QueueNode;

typedef struct {
	QueueNode *front, *rear;
}QueueType;

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType *q) {
	q->front = q->rear = NULL;
}

int is_empty(QueueType *q) {
	return (q->front == NULL);
}

void enqueue(QueueType *q, element item) {
	QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		error("메모리 할당 불가");
	else {
		temp->item = item;
		temp->link = NULL;
		if (is_empty(q)) {
			q->front = temp;
			q->rear = temp;
		}
		else {
			q->rear->link = temp;
			q->rear = temp;
		}
	}
}
element dequeue(QueueType *q) {
	QueueNode *temp = q->front;
	element item;

	if (is_empty(q))
		error("큐가 비어있습니다.");
	else {
		item = temp->item;
		q->front = q->front->link;
		if (q->front == NULL)
			q->rear = NULL;
		free(temp); //해제 해주기 필수!!!
		return item;
	}
}
element peek(QueueType *q) {
	if (is_empty(q))
		error("큐가 비어 있습니다.");
	else {
		return q->front->item;
	}
}
void radix_sort(int list[], int n) {

	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];

	for (b = 0; b < BUCKETS; b++)
		init(&queues[b]);

	for (d = 0; d < DIGITS; d++) {
		for (i = 0; i < n; i++)
			enqueue(&queues[(list[i] / factor) % 10], list[i]);

		for (b = i = 0; b < BUCKETS; b++) {
			while (!is_empty(&queues[b]))
				list[i++] = dequeue(&queues[b]);
		}

		factor *= 10;
	}
}

int main(void) {
	int count;
	int arr[100];

	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		scanf("%d", &arr[i]);
	}
	radix_sort(arr, 10);

	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}