#include<stdio.h>
int a[510][510], n, m, res;
int max(int a, int b) {
	return a > b ? a : b;
}
int shape_a(int x, int y) {
	int re = 0;
	if (y + 3 <= m) re = max(a[x][y] + a[x][y + 1] + a[x][y + 2] + a[x][y + 3], re);
	if (x + 3 <= n) re = max(a[x][y] + a[x + 1][y] + a[x + 2][y] + a[x + 3][y], re);
	return re;
}
int shape_b(int x, int y) {
	int re = 0;
	if (x + 1 <= n && y + 1 <= m) re = a[x][y] + a[x + 1][y] + a[x][y + 1] + a[x + 1][y + 1];
	return re;
}
int shape_c(int x, int y) {
	int re = 0;
	if (x + 2 <= n && y + 1 <= m) re = max(a[x][y] + a[x + 1][y] + a[x + 2][y] + a[x + 2][y + 1], re);
	if (x + 2 <= n && y - 1 >= 1) re = max(a[x][y] + a[x + 1][y] + a[x + 2][y] + a[x + 2][y - 1], re);
	if (x + 1 <= n && y + 2 <= m) re = max(a[x][y] + a[x + 1][y] + a[x][y + 1] + a[x][y + 2], re);
	if (x + 1 <= n && y + 2 <= m) re = max(a[x][y] + a[x][y + 1] + a[x][y + 2] + a[x + 1][y + 2], re);
	if (x + 2 <= n && y + 1 <= m) re = max(a[x][y] + a[x][y + 1] + a[x + 1][y + 1] + a[x + 2][y + 1], re);
	if (x + 2 <= n && y + 1 <= m) re = max(a[x][y] + a[x][y + 1] + a[x + 1][y] + a[x + 2][y], re);
	if (x + 1 <= n && y + 2 <= m) re = max(a[x][y] + a[x + 1][y] + a[x + 1][y + 1] + a[x + 1][y + 2], re);
	if (x - 1 >= 1 && y + 2 <= m) re = max(a[x][y] + a[x][y + 1] + a[x][y + 2] + a[x - 1][y + 2], re);
	return re;
}
int shape_d(int x, int y) {
	int re = 0;
	if (x + 2 <= n && y + 1 <= m) re = max(a[x][y] + a[x + 1][y] + a[x + 1][y + 1] + a[x + 2][y + 1], re);
	if (x + 2 <= n && y - 1 >= 1) re = max(a[x][y] + a[x + 1][y] + a[x + 1][y - 1] + a[x + 2][y - 1], re);
	if (x - 1 >= 1 && y + 2 <= m) re = max(a[x][y] + a[x][y + 1] + a[x - 1][y + 1] + a[x - 1][y + 2], re);
	if (x + 1 <= n && y + 2 <= m) re = max(a[x][y] + a[x][y + 1] + a[x + 1][y + 1] + a[x + 1][y + 2], re);
	return re;
}
int shape_e(int x, int y) {
	int re = 0;
	if (x - 1 >= 1 && y + 2 <= m) re = max(a[x][y] + a[x][y + 1] + a[x][y + 2] + a[x - 1][y + 1], re);
	if (x + 1 <= n && y + 2 <= m) re = max(a[x][y] + a[x][y + 1] + a[x][y + 2] + a[x + 1][y + 1], re);
	if (x + 2 <= n && y - 1 >= 1) re = max(a[x][y] + a[x + 1][y] + a[x + 2][y] + a[x + 1][y - 1], re);
	if (x + 2 <= n && y + 1 <= m) re = max(a[x][y] + a[x + 1][y] + a[x + 2][y] + a[x + 1][y + 1], re);
	return re;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	res = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			res = max(res, shape_a(i, j));
			res = max(res, shape_b(i, j));
			res = max(res, shape_c(i, j));
			res = max(res, shape_d(i, j));
			res = max(res, shape_e(i, j));
		}
	}
	printf("%d\n", res);
	return 0;
}