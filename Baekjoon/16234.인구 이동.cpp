#include<stdio.h>
int n, L, R, map[60][60], res, union_map[60][60], q[2][1000001], sum[3000], cnt[3000], union_number, sw;
void get_input() {
	scanf("%d %d %d", &n, &L, &R);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == map[1][1]) cnt++;
		}
	}
	if (cnt == n * n) {
		res = -1;
	}
}
void clear_map(int a[][60]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) a[i][j] = 0;
	}
}
int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };
void bfs(int sx, int sy, int un) {
	int r, f, x, y, nx, ny, dif;
	r = f = 0;
	q[0][++r] = sx;
	q[1][r] = sy;
	union_map[sx][sy] = un;
	sum[un] += map[sx][sy];
	cnt[un]++;
	while (r > f) {
		x = q[0][++f];
		y = q[1][f];
		for (int i = 1; i <= 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx == 0 || nx == n + 1 || ny == 0 || ny == n + 1 || union_map[nx][ny]!=0) continue;
			dif = map[x][y] - map[nx][ny];
			if (dif < 0) dif *= -1;
			if (dif >= L && dif <= R) {
				q[0][++r] = nx;
				q[1][r] = ny;
				union_map[nx][ny] = un;
				cnt[un]++;
				sum[un] += map[nx][ny];
			}
		}
	}
}
void make_union() {
	union_number = 1;
	clear_map(union_map);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (union_map[i][j] == 0) {
				sum[union_number] = 0;
				cnt[union_number] = 0;
				bfs(i, j, union_number++);
			}				
		}
	}
}
void calc_avg() {
	for (int i = 1; i < union_number; i++) {
		sum[i] = sum[i] / cnt[i];
	}
}
void move_population() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] != sum[union_map[i][j]]) cnt++;
			map[i][j] = sum[union_map[i][j]];
		}
	}
	if (cnt == 0) sw = 1;
}
int main() {
	get_input();
	if (res == -1) {
		printf("0\n");
		return 0;
	}
	while (1) {
		make_union();
		calc_avg();
		move_population();
		if (sw == 1) break;
		res++;
	}
	printf("%d\n", res);
}