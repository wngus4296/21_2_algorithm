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
	for (int j, i = 1; i <= SIZE; i++) {
		int temp = L[i]; // 임시 장소에 비교할 값 저장
		for (j = i; j > 0; j--) { // 맨 끝 부터 비교
			if (L[j - 1] > temp) { // 만약 앞 원소보다 비교값이 작으면
				L[j] = L[j - 1]; // 앞 원소를 뒤로 보냄
			}
			else break;
		}
		L[j] = temp; // 비교값 자리 세팅
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
