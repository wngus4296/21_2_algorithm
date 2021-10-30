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

void merge(int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	int sortedArray[SIZE];

	while (i <= mid && j <= right) { // 한 쪽이라도 다 소진될 때까지 정렬
		if (L[i] <= L[j]) { // 작은 값 새로운 배열에 넣기 (더 작은 값 넣고 인덱스 올리기)
			sortedArray[k++] = L[i++];
		}
		else {
			sortedArray[k++] = L[j++];
		}
	}

	if (i > mid) { // 오른쪽이 남은 경우 나머지 처리
		for (int s = j; s <= right; s++) {
			sortedArray[k++] = L[s];
		}
	}
	else { // 왼쪽이 남은 경우 나머지 처리 
		for (int s = i; s <= mid; s++) {
			sortedArray[k++] = L[s];
		}
	}

	for (int s = left; s <= right; s++) { // merge한 부분 다시 원래 배열 L에 넣어주기
		L[s] = sortedArray[s];
	}
}

void merge_sort(int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2; // 중간 인덱스로 기준 설정
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid, right);
	}
}

void main() {
	cout << "Input Data : ";
	print_data();

	/* sort the elements of array L[] in ascending order */
	merge_sort(0, SIZE - 1);

	cout << "\n\nSorted Data : ";
	print_data();
}
