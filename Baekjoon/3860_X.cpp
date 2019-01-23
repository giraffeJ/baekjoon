#include<stdio.h> 
int i, j, k, n, m, x, y, z, v, w, res;
int a[40][40], h[40][40][6], q[3][1000001];
int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int explore(int sx, int sy) {
	int d[40][40], c[40][40], r, f, nx, ny, tx, ty, ad, sw = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			c[i][j] = 0;
			d[i][j] = -1;
		}
	}
	r = f = 0;
	q[0][++r] = sx;
	q[1][r] = sy;
	c[sx][sy] = 1;
	d[sx][sy] = 0;
	while (r > f) {
		x = q[0][++f];
		y = q[1][f];
		if (x != n || y != m) {
			if (d[1][1] < -10) {
				sw = 1;
				break;
			}
			for (i = 1; i <= 4; i++) {
				nx = x + dx[i];
				ny = y + dy[i];
				if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
					if (a[nx][ny] != 1) {
						ad = 1;
						if (a[nx][ny] == 2) {
							tx = nx;
							ty = ny;
							nx = h[tx][ty][1];
							ny = h[tx][ty][2];
							ad += h[tx][ty][3];
						}
						if (c[nx][ny] == 0 || c[nx][ny] == 1 && d[nx][ny] > d[x][y] + ad) {
							q[0][++r] = nx;
							q[1][r] = ny;
							c[nx][ny] = 1;
							d[nx][ny] = d[x][y] + ad;
						}
					}
				}
			}
		}
		if (sw == 1) break;
	}
	if (sw == 1) return -2100000000;
	if (c[n][m] == 0) return 2100000000;
	else return d[n][m];
}
int main() {
	while (1) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				a[i][j] = 0;
				h[i][j][0] = h[i][j][1] = h[i][j][2] = h[i][j][3] = 0;
			}
		}
		scanf("%d", &k);
		for (i = 1; i <= k; i++) {
			scanf("%d %d", &x, &y);
			a[x + 1][y + 1] = 1;
		}
		scanf("%d", &k);
		for (i = 1; i <= k; i++) {
			scanf("%d %d %d %d %d", &x, &y, &z, &w, &v);
			h[x + 1][y + 1][1] = z + 1;
			h[x + 1][y + 1][2] = w + 1;
			h[x + 1][y + 1][3] = v;
			a[x + 1][y + 1] = 2;
		}
		res = explore(1, 1);
		if (res == -2100000000) printf("Never\n");
		else if (res == 2100000000) printf("Impossible\n");
		else printf("%d\n", res);
	}

}