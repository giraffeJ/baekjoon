#include<stdio.h>
int a[60][60], c[60][60], tcn, n, m, i, j, k, x, y;
int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };
void bfs(int sx, int sy) {
	int q[2][3001], r, f, x, y, i;
	r = f = 0;
	q[0][++r] = sx;
	q[1][r] = sy;
	c[sx][sy] = 1;
	while (r > f) {
		x = q[0][++f];
		y = q[1][f];
		for (i = 1; i <= 4; i++) {
			if (a[x + dx[i]][y + dy[i]] == 1 && c[x + dx[i]][y + dy[i]] == 0) {
				q[0][++r] = x + dx[i];
				q[1][r] = y + dy[i];
				c[x + dx[i]][y + dy[i]] = 1;
			}
		}
	}
}
int baechu() {
	int i, j, cnt=0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (a[i][j] == 1 && c[i][j] == 0) {
				cnt++;
				bfs(i, j);
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			c[i][j] = 0;
			a[i][j] = 0;
		}
	}
	return cnt;
}
int main() {
	scanf("%d", &tcn);
	for (i = 1; i <= tcn; i++) {
		scanf("%d %d %d", &n, &m, &k);
		for (j = 1; j <= k; j++) {
			scanf("%d %d", &x, &y);
			a[x][y] = 1;
		}
		printf("%d\n", baechu());
	}
	scanf("%d", &tcn);
}