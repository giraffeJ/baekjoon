#include<stdio.h>
int n, m, sx, sy, sd;
int map[60][60], clean[60][60];
void get_map() {
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &sx, &sy, &sd);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}
int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };
int left_dir[5] = { 0, 4, 1, 2, 3 };
void cleaning() {
	int x = sx + 1, y = sy + 1, dir = sd + 1, sw = 0;
	while (1) {
		clean[x][y] = 1;
		sw = 0;
		for (int i = 1; i <= 4; i++) {
			dir = left_dir[dir];
			if (map[x + dx[dir]][y + dy[dir]] == 1 || clean[x + dx[dir]][y + dy[dir]] == 1) continue;
			x = x + dx[dir];
			y = y + dy[dir];
			sw = 1;
			break;
		}
		if (sw == 0) {
			if (map[x - dx[dir]][y - dy[dir]] == 1) break;
			x = x - dx[dir];
			y = y - dy[dir];
			continue;
		}
	}
}
int count_cleaned_area() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cnt += clean[i][j];
		}
	}
	return cnt;
}
int main() {
	get_map();
	cleaning();
	printf("%d\n", count_cleaned_area());
}