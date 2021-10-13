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

void sort()
{
	for (int i = SIZE - 1; i > 0; i--) {
		int maxIndex = 0; // ù��° ����
		for (int j = 1; j <= i; j++) {
			if (L[maxIndex] < L[j]) {
				maxIndex = j; // maxIndex�� ���� ū ���� �ִ� ���� index�� �ٲ��ֱ�
			}
			int temp = L[maxIndex]; // �ڸ� �ٲ�
			L[maxIndex] = L[i];
			L[i] = temp;
		}
	}
}

void main()
{
	cout << "Input Data : ";
	print_data();

	/* sort the elements of array L[] in ascending order */
	sort();

	cout << "\n\nSorted Data : ";
	print_data();

}
