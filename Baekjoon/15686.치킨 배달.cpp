#include<stdio.h>
int n, m, h, c, res=2100000000;
int min(int a, int b) {
	return a < b ? a : b;
}
struct co {
	int x;
	int y;
};
co home[110], chicken[15];
int map[60][60], distance[15][110], index[60][60], q[3][100001], chosen[15];
void get_input() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				home[++h] = { i, j };
				index[i][j] = h;
			}
			if (map[i][j] == 2) {
				chicken[++c] = { i, j };
				index[i][j] = c;
			}
		}
	}
}
int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };
void bfs(int ind) {
	int dis[60][60], ch[60][60] = { {0,} } , r, f, x, y, nx, ny;
	r = f = 0;
	q[0][++r] = chicken[ind].x;
	q[1][r] = chicken[ind].y;
	dis[chicken[ind].x][chicken[ind].y] = 0;
	while (r > f) {
		x = q[0][++f];
		y = q[1][f];
		for (int i = 1; i <= 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (ch[nx][ny] == 1 || nx==0 || nx==n+1 || ny==0 || ny==n+1) continue;
			q[0][++r] = nx;
			q[1][r] = ny;
			dis[nx][ny] = dis[x][y] + 1;
			ch[nx][ny] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 1) {
				distance[ind][index[i][j]] = dis[i][j];
			}
		}
	}

}
void get_distance() {
	for (int i = 1; i <= c; i++) {
		bfs(i);
	}
}
int calc_chicken_distance() {
	int sum = 0;
	for (int i = 1; i <= h; i++) {
		int min_ = 99999;
		for (int j = 1; j <= c; j++) {
			if (chosen[j] == 0) continue;
			min_ = min(min_, distance[j][i]);
		}
		sum += min_;
	}
	return sum;
}
void choose_chicken(int pos, int num) {
	if (pos == c + 1) {
		res = min(res, calc_chicken_distance());
		return;
	}
	choose_chicken(pos + 1, num);
	if (num == m) return;
	chosen[pos] = 1;
	choose_chicken(pos + 1, num + 1);
	chosen[pos] = 0;
}
int main() {
	get_input();
	get_distance();
	choose_chicken(1, 0);
	printf("%d\n", res);
}