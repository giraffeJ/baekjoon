#include<stdio.h>
int dir_map[5][5] = { {0, 0, 0, 0, 0}, {0, 1, 2, 3, 4}, {0, 2, 3, 4, 1}, {0, 3, 4, 1, 2}, {0, 4, 1, 2, 3} };
int cctv_type[6][5] = { {0, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 1, 1, 0, 0}, {0, 1, 1, 0, 1}, {0, 1, 1, 1, 1} };
int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };
struct cctv {
	int x;
	int y;
	int type;
	int dir;
} cctvs[20];
int n, m, c, map[20][20], res=2100000000;
void get_map() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				cctvs[++c] = { i, j, map[i][j], 0 };
			}
		}
	}
}
int min(int a, int b) {
	return a < b ? a : b;
}
int calc_area() {
	int check[20][20] = { 0, }, x, y, nx, ny, dir;
	for (int i = 1; i <= c; i++) {
		x = cctvs[i].x;
		y = cctvs[i].y;
		for (int j = 1; j <= 4; j++) {
			if (cctv_type[cctvs[i].type][j] == 1) {
				dir = dir_map[cctvs[i].dir][j];
				nx = x + dx[dir];
				ny = y + dy[dir];
				while (1) {
					if (nx > n || nx == 0 || ny > m || ny == 0) break;
					if (map[nx][ny] == 6) break;
					check[nx][ny] = 1;
					nx += dx[dir];
					ny += dy[dir];
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0 && check[i][j] != 1) cnt++;
		}
	}
	return cnt;
}
void place_cctv(int ind) {
	if (ind == c + 1) {
		res = min(res, calc_area());
		return;
	}
	cctvs[ind].dir = 1;
	place_cctv(ind + 1);
	if (cctvs[ind].type == 5) return;
	cctvs[ind].dir = 2;
	place_cctv(ind + 1);
	if (cctvs[ind].type == 2) return;
	cctvs[ind].dir = 3;
	place_cctv(ind + 1);
	cctvs[ind].dir = 4;
	place_cctv(ind + 1);
	return;
}
int main() {
	get_map();
	place_cctv(1);
	printf("%d\n", res);
	return 0;
}