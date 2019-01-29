#include<stdio.h>
long long int i, j, k, n, m, a[1001], d[1001][1001][4], x, y;
long long int min(long long int a, long long int b) {
	if (a < b) return a;
	else return b;
}
int main() {
	scanf("%lld", &n);
	for (i = 1; i <= n; i++) {
		scanf("%lld %lld", &x, &y);
		d[i][i + 1][1] = d[i][i][1] = d[i][i][2] = x;
		d[i][i + 1][2] = d[i + 1][i + 1][1] = d[i + 1][i + 1][2] = y;
		d[i][i + 1][3] = 0;
	}
	for (i = 3; i <= n + 1; i++) {
		for (j = 1; j <= n + 2 - i; j++) {
			x = j;
			y = j + i - 1;
			d[x][y][3] = 21000000000;
			for (k = x + 1; k < y; k++) {
				d[x][y][3] = min(d[x][y][3], d[x][k][3] + d[k][y][3] + d[x][k][1] * d[x][k][2] * d[k][y][2]);
			}
			d[x][y][1] = d[x][x][1];
			d[x][y][2] = d[y][y][2];
		}
	}
	printf("%lld\n", d[1][n + 1][3]);
	scanf("%lld", &n);
}