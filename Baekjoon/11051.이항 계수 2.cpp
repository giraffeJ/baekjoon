#include<stdio.h>
int i, j, k, n, m, d[1020][1020];
int main() {
	scanf("%d %d", &n, &m);
	k = 1;
	d[0][0] = 1;
	d[1][0] = 1;
	d[1][1] = 1;
	for (i = 2; i <= n; i++) {
		d[i][0] = 1;
		for (j = 1; j <= i; j++) {
			d[i][j] = (d[i - 1][j - 1] + d[i - 1][j]) % 10007;
		}
	}
	printf("%d\n", d[n][m]);
	scanf("%d %d", &n, &m);
}