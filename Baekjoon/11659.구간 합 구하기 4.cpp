#include<stdio.h>
int i, j, k, n, m, a[100030], d[100030], x, y;
int main() {
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		d[i] = d[i - 1] + a[i];
	}
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		printf("%d\n", d[y] - d[x - 1]);
	}
	scanf("%d %d", &n, &m);
}