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
	/* �Է� ����Ÿ�� L[]�� ��� ������, ��ü ���� ������ SIZE�̴�. */
	for (int k = 0; k < SIZE; k++) { // array L�� ��ȸ�Ѵ�. (���ذ�)
		for (int s = 0; s < SIZE; s++) { // ��� ���ҿ� ���Ѵ�. (�񱳰�)
			if (L[k] < L[s]) { // ���ذ����� �񱳰��� Ŭ ��� �ڸ��� �ٲ��ش�.
				int temp = L[k];
				L[k] = L[s];
				L[s] = temp;
			}
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
