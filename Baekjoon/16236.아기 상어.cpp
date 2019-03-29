#include<stdio.h>
int n, bs_x, bs_y, bs_nx, bs_ny, bs_size, time, dis, cnt;
int a[30][30], q[2][100001];
int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };
int find_food(int bs_x, int bs_y, int bs_size) {
	int r, f, d[30][30], c[30][30], x, y, nx, ny, mi;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) c[i][j] = 0;
	}
	r = f = 0;
	q[0][++r] = bs_x;
	q[1][r] = bs_y;
	d[bs_x][bs_y] = 0;
	c[bs_x][bs_y] = 1;
	while (r > f) {
		x = q[0][++f];
		y = q[1][f];
		for (int i = 1; i <= 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
				if (c[nx][ny] == 0 && a[nx][ny] <= bs_size) {
					c[nx][ny] = 1;
					d[nx][ny] = d[x][y] + 1;
					q[0][++r] = nx;
					q[1][r] = ny;
				}
			}
		}
	}
	mi = 9999;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] > 0 && a[i][j] < bs_size && c[i][j] == 1 && d[i][j] < mi) {
				mi = d[i][j];
				bs_nx = i;
				bs_ny = j;
			}
		}
	}
	if (mi == 9999) return -1;
	return mi;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 9) {
				bs_x = i;
				bs_y = j;
				a[i][j] = 0;
			}
		}
	}
	time = 0;
	bs_size = 2;
	cnt = 0;
	while (1) {
		dis = find_food(bs_x, bs_y, bs_size);
		if (dis == -1) break;
		time += dis;
		cnt++;
		if (cnt == bs_size) {
			bs_size++;
			cnt = 0;
		}
		bs_x = bs_nx;
		bs_y = bs_ny;
		a[bs_x][bs_y] = 0;
	}
	printf("%d\n", time);
	return 0;
}