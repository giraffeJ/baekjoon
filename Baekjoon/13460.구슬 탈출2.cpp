#include<stdio.h>
int answer_route[11];
int n, m, res, map[11][11];
int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };
int opposite[5] = { 0, 3, 4, 1, 2 };
struct pos {
	int x;
	int y;
	bool operator == (const pos &a) {		return (x == a.x && y == a.y);	}
	bool operator != (const pos &a) { return (x != a.x || y != a.y); }
	pos operator + (const pos &a) {		return { x + a.x, y + a.y };	}
	pos operator - (const pos &a) { return { x - a.x, y - a.y }; }
} red, blue, hole;
int min_(int a, int b) {
	return a < b ? a : b;
}
void get_map() {
	char temp;
	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 1; j <= m; j++) {
			scanf("%c", &temp);
			if (temp == '#') map[i][j] = -1;
			else if (temp == 'R') {
				map[i][j] = 1;
				red = { i, j };
			}
			else if (temp == 'B') {
				map[i][j] = 2;
				blue = { i, j };
			}
			else if (temp == 'O') {
				hole = { i, j };
				map[i][j] = 3;
			}
		}
	}
}
int find_answer_route(int seq, pos red, pos blue, int d) {
	if (seq == 11) return 999;
	pos next_red[5], next_blue[5], dir;
	int red_stop, blue_stop, min_seq=999;
	for (int i = 1; i <= 4; i++) {
		if (i == opposite[d]) continue;
		dir = { dx[i], dy[i] };
		next_red[i] = red;
		next_blue[i] = blue;
		red_stop = blue_stop = 0;
		while (red_stop+blue_stop<2) {
			if(!red_stop) next_red[i] = next_red[i] + dir;
			if(!blue_stop) next_blue[i] = next_blue[i] + dir;
			if (next_red[i] == hole) red_stop = 1;
			else if (map[next_red[i].x][next_red[i].y] == -1 || blue_stop == 1 && next_red[i] == next_blue[i]) {
				next_red[i] = next_red[i] - dir;
				red_stop = 1;
			}
			if (next_blue[i] == hole) blue_stop = 1;
			else if (map[next_blue[i].x][next_blue[i].y] == -1 || red_stop == 1 && next_blue[i] == next_red[i]) {
				next_blue[i] = next_blue[i] - dir;
				blue_stop = 1;
				if (red_stop==0 && (map[next_red[i].x][next_red[i].y] == -1 || blue_stop == 1 && next_red[i] == next_blue[i])) {
					next_red[i] = next_red[i] - dir;
					red_stop = 1;
				}
			}
		}
		if (next_red[i] == hole && next_blue[i] != hole) {
			return seq;
		}
	}
	for (int i = 1; i <= 4; i++) {
		if (next_blue[i] != hole && i!=opposite[d] && (next_red[i]!=red || next_blue[i]!=blue)) {
			min_seq = min_(min_seq, find_answer_route(seq + 1, next_red[i], next_blue[i], i));
		}
	}
	return min_seq;
}
int main() {
	scanf("%d %d", &n, &m);
	get_map();
	res = find_answer_route(1, red, blue, 0);
	if (res == 999) res = -1;
	printf("%d\n", res);
}