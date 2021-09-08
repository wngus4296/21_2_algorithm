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
	/* 입력 데이타는 L[]에 들어 있으면, 전체 원소 개수는 SIZE이다. */
	for (int k = 0; k < SIZE; k++) { // array L을 순회한다. (기준값)
		for (int s = 0; s < SIZE; s++) { // 모든 원소와 비교한다. (비교값)
			if (L[k] < L[s]) { // 기준값보다 비교값이 클 경우 자리를 바꿔준다.
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
