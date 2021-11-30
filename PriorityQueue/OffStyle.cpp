#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif


#include<stdio.h>
#define MAX_SIZE 100

int heap[MAX_SIZE];
int heapSize = 0;

void heapInit(void) {
	heapSize = 0;
}

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int leftC(int current) {
	return (current * 2 + 1);
}

int rightC(int current) {
	return (current * 2 + 2);
}

int parent(int current) {
	return ((current - 1) / 2);
}



int heapPush_min(int value) {
	if (heapSize + 1 > MAX_SIZE) {
		printf("queue is full\n");
		return 0;
	}
	heap[heapSize] = value;
	int current = heapSize;
	while (current > 0 && heap[current] < heap[parent(current)]) {
		swap(&heap[current], &heap[parent(current)]);
		current = parent(current);
	}
	heapSize = heapSize + 1;
	return 1;
}

int heapPop_minItem(int* minValue) {
	if (heapSize <= 0)
		return -1;
	*minValue = heap[0];
	heapSize = heapSize - 1;
	heap[0] = heap[heapSize];
	int current = 0;
	while (leftC(current) < heapSize) {
		int smallest;
		if (rightC(current) == heapSize) {
			smallest = leftC(current);
		}
		else {
			smallest = heap[leftC(current)] < heap[rightC(current)] ? leftC(current) : rightC(current);
		}

		if (heap[current] < heap[smallest])
			break;

		swap(&heap[current], &heap[smallest]);
		current = smallest;
	}
	return 1;
}


int heapPush_max(int value) {
	if (heapSize + 1 > MAX_SIZE) {
		printf("queue is full\n");
		return 0;
	}
	heap[heapSize] = value;
	int current = heapSize;
	while (current > 0 && heap[current] > heap[parent(current)]) {
		swap(&heap[current], &heap[parent(current)]);
		current = parent(current);
	}
	heapSize = heapSize + 1;
	return 1;
}


int heapPop_maxItem(int* minValue) {
	if (heapSize <= 0)
		return -1;
	*minValue = heap[0];
	heapSize = heapSize - 1;
	heap[0] = heap[heapSize];
	int current = 0;
	while ((current * 2 + 1) < heapSize) {
		int largest;
		if (current * 2 + 2 == heapSize) {
			largest = current * 2 + 1;
		}
		else {
			largest = heap[current * 2 + 1] > heap[current * 2 + 2] ?
				current * 2 + 1 : current * 2 + 2;
		}

		if (heap[current] > heap[largest])
			break;

		swap(&heap[current], &heap[largest]);
		current = largest;
	}
	return 1;
}



int main(int argc, char* argv[]) {
	int T, N;
	setbuf(stdin, NULL);
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	for (int testCase = 1; testCase <= T; testCase++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			int value;
			scanf("%d", &value);
			heapPush_max(value);
		}
		printf("#%d: ", testCase);

		for (int i = 0; i < N; i++) {
			int value;
			heapPop_maxItem(&value);
			printf("%d\t", value);
		}
		printf("\n");
	}
	return 0;
}