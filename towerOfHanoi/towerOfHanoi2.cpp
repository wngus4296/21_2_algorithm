#include <iostream> 
using namespace std;

int cnt = 0; // �̵� Ƚ���� �̿�.

void Hanoi(int n, char from, char temp, char to)
// n : ���ݰ���, from : ���� ��ġ, temp : �ӽ� ���, to :������
{
	// cnt = pow(2, n) - 1;
	// ���� �ؿ� �ִ� ������ ������ ��� ������ from -> temp, temp -> to�� �Ű�����.

	if (n == 1) {
		cout << "#" << ++cnt << ".��ũ 1���� " << from << "�������� " << to << "�� �ű��." << endl;
	}
	else {
		Hanoi(n - 1, from, to, temp); // �� ���� ������ ������ ������ from���� temp�� �ű��.
		Hanoi(1, from, temp, to); // �� �� ������ from���� to�� �ű��.
		Hanoi(n - 1, temp, from, to); // ������ ������ temp���� to�� �ű��.
	}
}


void main()
{
	int n; //������ ��

	cout << "������ ������ �Է��ϼ��� : ";
	cin >> n;

	Hanoi(n, 'A', 'B', 'C');    // n���� ������ 'A'���� 'C'�� �̵�

	cout << "��ü ���� �̵� ��(���ݼ� : " << n << ") = " << cnt << endl;
}