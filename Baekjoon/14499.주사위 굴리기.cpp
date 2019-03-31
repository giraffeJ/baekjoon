#include<stdio.h>
int map[30][30], moves[1010];
int n, m, sx, sy, move;
int dice_status[7] = { 0, 0, 0, 0, 0, 0, 0 }; // 0, 위 아래 왼쪽 오른쪽 앞 뒤
void get_map() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}
int dir_convert[5] = { 0, 2, 4, 1, 3 };
void get_move_sequence() {
	for(int i=1; i<=move; i++){
		scanf("%d", &moves[i]);
		moves[i] = dir_convert[moves[i]];
	}
}
int roll_convert[5][7] = { {0, 0, 0, 0, 0, 0, 0}, {0, 5, 6, 3, 4, 2, 1}, {0, 3, 4, 2, 1, 5, 6}, {0, 6, 5, 3, 4, 1, 2}, {0, 4, 3, 1, 2, 5, 6} };
void roll(int dir, int nx, int ny) {
	int temp[7];
	for (int i = 1; i <= 6; i++)
		temp[i] = dice_status[roll_convert[dir][i]];
	for (int i = 1; i <= 6; i++)
		dice_status[i] = temp[i];
	if (map[nx][ny] == 0) {
		map[nx][ny] = dice_status[2];
	}
	else if (map[nx][ny] > 0) {
		dice_status[2] = map[nx][ny];
		map[nx][ny] = 0;
	}
}
int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };
void rolling() {
	int x = sx, y = sy, dir, nx, ny;
	for (int i = 1; i <= move; i++) {
		dir = moves[i];
		nx = x + dx[dir];
		ny = y + dy[dir];
		if (nx<1 || nx>n || ny<1 || ny>n) continue;
		roll(dir, nx, ny);
		printf("%d\n", dice_status[1]);
		x = nx;
		y = ny;
	}
}
int main() {
	scanf("%d %d %d %d %d", &n, &m, &sx, &sy, &move);
	sx++;
	sy++;
	get_map();
	get_move_sequence();
	rolling();
}