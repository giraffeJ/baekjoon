#include<stdio.h>
#include<vector> //기본적으로 확장 유클리드 호제법을 사용한다. 추가적으로 사탕 봉지 갯수가 양수가 되기 위해서는 약간의 수학적 지식이 필요한데, 맨 아래를 참고.
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
/*확장 유클리드 호제법 연습하기 위한 문제.

K * x + 1 = C * y
Cy - Kx = 1

gcd(C, K) = g 일 떄
Cx + Ky = g 인 x, y는 구할 수 있음.

따라서 gcd(C, K)=1인지 보고
Cx + Ky  = 1 인 x, y를 구하면 되는데,
문제는 이 문제에서 x가 무조건 양수여야 한다는 것이다.

Ax + By = C
인 x, y를 구할 때
A(x+t) + By =/= C
Ax + At + By - At = C

By-At  가 B의 배수이면 된다.
따라서 A,B의 최소공배수를 더하고 빼면 된다.
A = ag, B = bg일 때
최소공배수는 abg이므로
Ax + abg + By - abg = C  에서

A(x+b) + B(y-a) = C 이므로
x에 b를 더하고 y에 a를 빼주면서 답을 찾아가면 된다.

이 문제에서 C와 K는 서로소 이므로,
Cx + Ky = 1 에서 x가 음수라면, K씩 더해주면 된다.*/