#include<stdio.h>
int i, j, k, n, m, a[501][501], d[501][501];
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	d[1][1] = a[1][1];
	for (i = 2; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + a[i][j];
		}
	}
	m = d[n][1];
	for (i = 2; i <= n; i++) {
		m = max(m, d[n][i]);
	}
	printf("%d\n", m);
	scanf("%d", &n);
}