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
	/* 이 곳에 알맞은 내용을 추가하시오. */
	/* 입력 데이타는 L[]에 들어 있으면, 전체 원소 개수는 SIZE이다. */
	for (int i = 1; i < SIZE; i++) {
		int temp = L[i]; // i번째 데이터 임시 저장
		int j = i;
		while (L[j - 1] > temp) { // 비교할 값이 더 작은 경우 앞으로 가야함 
			if (j <= 0) break; // 인덱스 0인 경우 앞 원소가 없다. 즉, temp가 가장 작은 원소
			L[j] = L[j - 1]; // 앞에 있던 원소를 뒤로 보냄 (자리 변경)
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
