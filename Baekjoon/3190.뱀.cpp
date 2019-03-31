#include<stdio.h>
int n, m;
int map[110][110], dir_change[110][3];
void get_apple() {
	int m, x, y;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		map[x][y] = -1;
	}
}
void get_route() {
	char dir;
	int time;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %c", &time, &dir);
		dir_change[i][1] = time;
		if (dir == 'D') dir_change[i][2] = 2;
		if (dir == 'L') dir_change[i][2] = 1;
	}
}
int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };
int dir_convert[3][5] = { {0, 0, 0, 0, 0}, {0, 4, 1, 2, 3}, {0, 2, 3, 4, 1} };
void moving_snake() {
	int time, x = 1, y = 1, nx, ny, dir = 2, length = 1, ind = 1;
	for(time=1; ; time++){
		nx = x + dx[dir];
		ny = y + dy[dir];
		if (nx<1 || nx>n || ny<1 || ny>n || map[nx][ny]>0 && time-map[nx][ny]<=length) 
			break;
		if (map[nx][ny] == -1)
			length++;
		map[nx][ny] = time;
		x = nx;
		y = ny;
		if (ind <= m && time == dir_change[ind][1])
			dir = dir_convert[dir_change[ind++][2]][dir];
	}
	printf("%d\n", time);
}
int main() {
	scanf("%d", &n);
	get_apple();
	get_route();
	moving_snake();
}