#include<stdio.h>
int n, m, k, res = -1;
int map[10][10], backup[10][10], virus[20][3];
int q[3][10001], c[10][10];

int max(int a, int b) {
	return a > b ? a : b;
}
void get_map() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				virus[++k][1] = i;
				virus[k][2] = j;
			}
		}
	}
}
int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };
void bfs() {
	int r, f, x, y, nx, ny;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			c[i][j] = 0;
		}
	}
	r = f = 0;
	for (int i = 1; i <= k; i++) {
		q[0][++r] = virus[i][1];
		q[1][r] = virus[i][2];
		c[virus[i][1]][virus[i][2]] = 1;
	}
	while (r > f) {
		x = q[0][++f];
		y = q[1][f];
		for (int i = 1; i <= 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx<1 || nx>n || ny<1 || ny>m) continue;
			if (map[nx][ny] == 0 && c[nx][ny] == 0) {
				c[nx][ny] = 1;
				q[0][++r] = nx;
				q[1][r] = ny;
			}
		}
	}
}
int count() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (c[i][j] == 0 && map[i][j] == 0) cnt++;
		}
	}
	return cnt;
}
void find_max_safe_area() {
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= m; b++) {
			if (map[a][b] != 0) continue;
			map[a][b] = 1;
			for (int c = 1; c <= n; c++) {
				for (int d = 1; d <= m; d++) {
					if (map[c][d] != 0 || a * 10 + b < c * 10 + d) continue;
					map[c][d] = 1;
					for (int e = 1; e <= n; e++) {
						for (int f = 1; f <= m; f++) {
							if (map[1][2] + map[2][1] + map[4][6] == 3) {
								f = f;
							}
							if (map[e][f] != 0 || c * 10 + d < e * 10 + f) continue;
							map[e][f] = 1;
							bfs();
							res = max(res, count());
							map[e][f] = 0;
						}
					}
					map[c][d] = 0;
				}
			}
			map[a][b] = 0;
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	get_map();
	find_max_safe_area();
	printf("%d\n", res);
}