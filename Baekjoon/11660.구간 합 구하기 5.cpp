#include<stdio.h>
int i, j, k, n, m, a[1200][1200], b[1200][1200], d[1200][1200], x1, x2, y1, y2;
int main() {
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			b[i][j] = b[i][j - 1] + a[i][j];
			d[i][j] = d[i - 1][j] + b[i][j];
		}
	}
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", d[x2][y2] - d[x1 - 1][y2] - d[x2][y1 - 1] + d[x1 - 1][y1 - 1]);
	}
	scanf("%d %d", &n, &m);
}