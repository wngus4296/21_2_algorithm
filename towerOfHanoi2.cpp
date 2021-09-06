#include <iostream> 
using namespace std;

int cnt = 0; // 이동 횟수에 이용.

void Hanoi(int n, char from, char temp, char to)
// n : 원반개수, from : 원래 위치, temp : 임시 장소, to :목적지
{
	// cnt = pow(2, n) - 1;
	// 가장 밑에 있는 원반을 제외한 모든 원반은 from -> temp, temp -> to로 옮겨진다.

	if (n == 1) {
		cout << "#" << ++cnt << ".디스크 1개를 " << from << "지점에서 " << to << "로 옮긴다." << endl;
	}
	else {
		Hanoi(n - 1, from, to, temp); // 맨 밑을 제외한 나머지 원반을 from에서 temp로 옮긴다.
		Hanoi(1, from, temp, to); // 맨 밑 원반을 from에서 to로 옮긴다.
		Hanoi(n - 1, temp, from, to); // 나머지 원반을 temp에서 to로 옮긴다.
	}
}


void main()
{
	int n; //원반의 수

	cout << "원반의 갯수를 입력하세요 : ";
	cin >> n;

	Hanoi(n, 'A', 'B', 'C');    // n개의 원반을 'A'에서 'C'로 이동

	cout << "전체 원반 이동 수(원반수 : " << n << ") = " << cnt << endl;
}