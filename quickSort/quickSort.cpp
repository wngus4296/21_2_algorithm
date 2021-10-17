#include <iostream>
using namespace std;

const int SIZE = 15;
int L[SIZE] = { 10, 4, 7, 1, -2, 12, 28, 66, 9, 3, 5, 7, 6, 21, 11 };


void print_data()
{
	for (int i = 0; i < SIZE; i++)
		cout << " " << L[i] << " ";
	cout << endl;
}

int partition(int from, int to) {
	int temp = L[to];
	int i = from - 1;
	int j = to;
	do {
		do { i = i + 1; } while(L[i] < temp); // 기준값보다 크거나 같은 원소를 찾는다.
		do { j = j - 1; } while(j >= from && L[j] > temp); // 기준값보다 작거나 같은 원소를 찾는다.
		// while의 앞 조건은 기준값이 최솟값인 경우 인덱스가 from보다 작아짐을 방지한다.
		if (i < j) { // do-while문이 끝나고 i가 왼쪽에 있을 경우(큰 값이 왼쪽에 있을 경우) 자리 바꿔준다.
			int t = L[i];
			L[i] = L[j];
			L[j] = t;
		}
	}while (j > i); // i와 j 둘 다 1씩 증가시키면서 i가 왼쪽에 있는 동안 계속 진행

	// 기준값이랑 중간값을 바꿔준다. (여기서 중간값이 기준값보다 크기때문)
	int t = L[i];
	L[i] = L[to];
	L[to] = t;

	return i; // 중간 인덱스 값 보낸다.
}

void quick_sort(int from, int to)
{
	int i;

	if (from < to) {
		i = partition(from, to);
		quick_sort(from, i - 1);
		quick_sort(i + 1, to);
	}
}

void main()
{
	cout << "Input Data : ";
	print_data();

	/* sort the elements of array L[] in ascending order */
	quick_sort(0, SIZE - 1);

	cout << "\n\nSorted Data : ";
	print_data();

}
