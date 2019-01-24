#include<stdio.h>
#include<vector> //�⺻������ Ȯ�� ��Ŭ���� ȣ������ ����Ѵ�. �߰������� ���� ���� ������ ����� �Ǳ� ���ؼ��� �ణ�� ������ ������ �ʿ��ѵ�, �� �Ʒ��� ����.
using namespace std;
long long int i, j, k, c, n, m, l, temp;
long long int find(long long int k2, long long int c2) {
	long long int calc[10001][5], i;
	calc[1][1] = calc[2][2] = 1;
	calc[1][2] = calc[2][1] = 0;
	calc[1][3] = k2;
	calc[2][3] = c2;
	for (i = 3; ; i++) {
		calc[i - 1][4] = calc[i - 2][3] / calc[i - 1][3];
		calc[i][3] = calc[i - 2][3] % calc[i - 1][3];
		calc[i][1] = calc[i - 2][1] - calc[i - 1][1] * calc[i - 1][4];
		calc[i][2] = calc[i - 2][2] - calc[i - 1][2] * calc[i - 1][4];
		if (calc[i][3] == 1) {
			return calc[i][2];
		}
		if (calc[i][3] == 0) {
			return -2100000000;
			break;
		}
	}
}
int main() {
	scanf("%lld", &n);
	for (i = 1; i <= n; i++) {
		scanf("%lld %lld", &k, &c);
		if (k == 1) {
			if (c == 1) printf("2\n");
			else printf("1\n");
		}
		else if (c == 1) {
			if (k == 1000000000)
				printf("IMPOSSIBLE\n");
			else
				printf("%lld\n", k + 1);
		}
		else {
			m = find(k, c);
			if (m == -2100000000) {
				printf("IMPOSSIBLE\n");
			}
			else {
				if (m < 0) {
					temp = m;
					temp *= -1;
					temp /= k;
					m = m + (temp + 1)*k;
				}
				if (m > 1000000000) {
					printf("IMPOSSIBLE\n");
				}
				else printf("%lld\n", m);
			}
		}
	}
	scanf("%lld", &n);
}
/*Ȯ�� ��Ŭ���� ȣ���� �����ϱ� ���� ����.

K * x + 1 = C * y
Cy - Kx = 1

gcd(C, K) = g �� ��
Cx + Ky = g �� x, y�� ���� �� ����.

���� gcd(C, K)=1���� ����
Cx + Ky  = 1 �� x, y�� ���ϸ� �Ǵµ�,
������ �� �������� x�� ������ ������� �Ѵٴ� ���̴�.

Ax + By = C
�� x, y�� ���� ��
A(x+t) + By =/= C
Ax + At + By - At = C

By-At  �� B�� ����̸� �ȴ�.
���� A,B�� �ּҰ������ ���ϰ� ���� �ȴ�.
A = ag, B = bg�� ��
�ּҰ������ abg�̹Ƿ�
Ax + abg + By - abg = C  ����

A(x+b) + B(y-a) = C �̹Ƿ�
x�� b�� ���ϰ� y�� a�� ���ָ鼭 ���� ã�ư��� �ȴ�.

�� �������� C�� K�� ���μ� �̹Ƿ�,
Cx + Ky = 1 ���� x�� �������, K�� �����ָ� �ȴ�.*/