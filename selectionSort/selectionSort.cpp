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
		int maxIndex = 0; // 첫번째 원소
		for (int j = 1; j <= i; j++) {
			if (L[maxIndex] < L[j]) {
				maxIndex = j; // maxIndex값 가장 큰 값이 있는 곳의 index로 바꿔주기
			}
			int temp = L[maxIndex]; // 자리 바꿈
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
