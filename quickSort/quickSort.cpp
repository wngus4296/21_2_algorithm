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
		do { i = i + 1; } while(L[i] < temp); // ���ذ����� ũ�ų� ���� ���Ҹ� ã�´�.
		do { j = j - 1; } while(j >= from && L[j] > temp); // ���ذ����� �۰ų� ���� ���Ҹ� ã�´�.
		// while�� �� ������ ���ذ��� �ּڰ��� ��� �ε����� from���� �۾����� �����Ѵ�.
		if (i < j) { // do-while���� ������ i�� ���ʿ� ���� ���(ū ���� ���ʿ� ���� ���) �ڸ� �ٲ��ش�.
			int t = L[i];
			L[i] = L[j];
			L[j] = t;
		}
	}while (j > i); // i�� j �� �� 1�� ������Ű�鼭 i�� ���ʿ� �ִ� ���� ��� ����

	// ���ذ��̶� �߰����� �ٲ��ش�. (���⼭ �߰����� ���ذ����� ũ�⶧��)
	int t = L[i];
	L[i] = L[to];
	L[to] = t;

	return i; // �߰� �ε��� �� ������.
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
