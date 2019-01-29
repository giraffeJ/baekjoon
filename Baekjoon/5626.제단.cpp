#include<stdio.h>
int i, j, k, n, m, l, add, sw = 0;
int d[6000][10010]; //메모리 문제 발생 가능성 있음. 메모리 토글링을 통해 d[5000][2] 가지고도 해결할 수 있음.
int a[10010];
int main() {
	scanf("%d", &n);
	m = (n + 1) / 2 - 1;
	k = m + 1;
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	l = 0;
	add = 1;
	d[0][1] = 1;
	for (j = 1; j <= n; j++) {
		if (a[j] == -1) {
			for (i = 0; i <= l; i++) {
				if (i - 1 >= 0) d[i - 1][j + 1] = (d[i - 1][j + 1] + d[i][j]) % 1000000007;
				if (i + 1 <= m) d[i + 1][j + 1] = (d[i + 1][j + 1] + d[i][j]) % 1000000007;
				d[i][j + 1] = (d[i][j + 1] + d[i][j]) % 1000000007;
			}
		}
		else {
			i = a[j];
			if (i - 1 >= 0) d[i - 1][j + 1] = (d[i - 1][j + 1] + d[i][j]) % 1000000007;
			if (i + 1 <= m) d[i + 1][j + 1] = (d[i + 1][j + 1] + d[i][j]) % 1000000007;
			d[i][j + 1] = (d[i][j + 1] + d[i][j]) % 1000000007;
		}
		if (n % 2 == 0 && j == n / 2 + 1) add = -1;
		else if (n % 2 == 0 && j == n / 2) add = 0;
		else if (n % 2 == 1 && j == k) add = -1;
		l += add;
	}
	if (a[n] > 0) d[0][n] = 0;
	printf("%d\n", d[0][n]);
	scanf("%d", &n);
}