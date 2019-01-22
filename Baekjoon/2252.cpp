#include<stdio.h>
int i, j, n, m, x, y, a[32020][1001], d[32020], q[40000], r, f;
int main() {
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		a[x][++a[x][0]] = y;
		d[y]++;
	}
	for (i = 1; i <= n; i++) {
		if (d[i] == 0) {
			q[++r] = i;
		}
	}
	while (r > f) {
		x = q[++f];
		printf("%d ", x);
		for (i = 1; i <= a[x][0]; i++) {
			d[a[x][i]]--;
			if (d[a[x][i]] == 0) q[++r] = a[x][i];
		}
	}
	scanf("%d", &n);
}