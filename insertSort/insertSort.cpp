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
	/* �� ���� �˸��� ������ �߰��Ͻÿ�. */
	/* �Է� ����Ÿ�� L[]�� ��� ������, ��ü ���� ������ SIZE�̴�. */
	for (int i = 1; i < SIZE; i++) {
		int temp = L[i]; // i��° ������ �ӽ� ����
		int j = i;
		while (L[j - 1] > temp) { // ���� ���� �� ���� ��� ������ ������ 
			if (j <= 0) break; // �ε��� 0�� ��� �� ���Ұ� ����. ��, temp�� ���� ���� ����
			L[j] = L[j - 1]; // �տ� �ִ� ���Ҹ� �ڷ� ���� (�ڸ� ����)
			j--;
		}
		L[j] = temp;
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
