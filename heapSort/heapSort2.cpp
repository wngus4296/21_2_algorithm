#include <iostream>
using namespace std;

#define SWAP(x, y, t) (t=x, x=y, y=t)

double L[15] = { 10, 4, 0, 1, -2, 12, 28, 66, 9, 3, 5, 7, 6, 21, 11 };

void print_data(double L[], int n)
{
	for (int i = 0; i < n; i++)
		cout << " " << L[i];
	cout << endl;
}

void Max_heap(double L[], int root, int n)
{
	double rootData = L[root];
	int child = root * 2 + 1; // ���� �ڽ�

	while (child <= n - 1) { // �ڽ� ��尡 ������
		if (child < n - 1 && L[child] < L[child + 1]) { // �ڽ��� �� ����� && ������ �ڽ��� ���� �ڽĺ��� ũ�ٸ�
			child = child + 1; // ū �ڽ� ����
		}
		if (rootData > L[child]) break; // �θ� ũ�ٸ� �Ѿ
		else { // ū ���� �ø���
			L[(child - 1) / 2] = L[child]; // �θ� �ڽ� �� �־���
			child = child * 2 + 1;
		}
	}
	L[(child - 1) / 2] = rootData;
}

void HeapSort(double L[], int n)
{
	int i, temp;

	// �ִ� ���� ���� ����
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
		Max_heap(L, i, n);

	// ���� ����
	// ���� ū ��(0��° ����)�� ������(n-1��°)���� �ű�� �������� �ٽ� heap����
	for (i = n - 1; i > 0; i--)
	{
		//�� ���� L[0],L[i] ��ȯ
		SWAP(L[0], L[i], temp);
		Max_heap(L, 0, i);
	}
}

void main()
{
	// ó�� ���¸� ������
	cout << "Input Data : ";
	print_data(L, 15);

	/* sort the elements of array L[] in ascending order */
	HeapSort(L, 15);

	// ���ĵ� ����� ������
	cout << "\nSorted Data : ";
	print_data(L, 15);

}
