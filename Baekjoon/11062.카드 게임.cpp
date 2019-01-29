#include<stdio.h>
int i, j, k, n, m, l, tcn, tc, x1, x2, d[1010][1010], a[1010], sum[1010];
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int main() {
	scanf("%d", &tcn);
	for (tc = 1; tc <= tcn; tc++) {
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			d[i][i] = a[i];
			sum[i] = sum[i - 1] + a[i];
		}
		for (l = 2; l <= n; l++) {
			j = l;
			for (i = 1; i <= n - l + 1; i++) {
				x1 = sum[j] - sum[i - 1] - d[i + 1][j];
				x2 = sum[j] - sum[i - 1] - d[i][j - 1];
				d[i][j] = max(x1, x2);
				j++;
			}
		}/*
		 for (i = 1; i <= n; i++) {
		 for (j = 1; j <= n; j++) {
		 printf("%2d", d[i][j]);
		 }
		 printf("\n");
		 }*/
		printf("%d\n", d[1][n]);
	}
	scanf("%d", &tcn);
}