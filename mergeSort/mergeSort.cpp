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

	while (i <= mid && j <= right) { // �� ���̶� �� ������ ������ ����
		if (L[i] <= L[j]) { // ���� �� ���ο� �迭�� �ֱ� (�� ���� �� �ְ� �ε��� �ø���)
			sortedArray[k++] = L[i++];
		}
		else {
			sortedArray[k++] = L[j++];
		}
	}

	if (i > mid) { // �������� ���� ��� ������ ó��
		for (int s = j; s <= right; s++) {
			sortedArray[k++] = L[s];
		}
	}
	else { // ������ ���� ��� ������ ó�� 
		for (int s = i; s <= mid; s++) {
			sortedArray[k++] = L[s];
		}
	}

	for (int s = left; s <= right; s++) { // merge�� �κ� �ٽ� ���� �迭 L�� �־��ֱ�
		L[s] = sortedArray[s];
	}
}

void merge_sort(int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2; // �߰� �ε����� ���� ����
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
