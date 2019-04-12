#include<vector>
#include<stdio.h>
using namespace std;
struct node {
	int x;
	int y;
};
vector<node> dc[30];
int n, ge[30], map[110][110];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };
void get_input() {
	int x, y, dir, gen;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d %d", &y, &x, &dir, &gen);
		ge[i] = gen;
		dc[i].push_back({ x, y });
		dc[i].push_back({ x + dx[dir], y + dy[dir] });		
	}
}
void rotate_and_add(int n) {
	int m = dc[n].size()-1;
	int x = dc[n][m].x;
	int y = dc[n][m].y;
	int dif_x, dif_y;
	for (int i = m - 1; i >= 0; i--) {
		dif_x = x - dc[n][i].x;
		dif_y = y - dc[n][i].y;
		dc[n].push_back({ x - dif_y, y + dif_x });
	}
}
void generate_dragon_curve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= ge[i]; j++) {
			rotate_and_add(i);
		}
	}
}
void draw() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < dc[i].size(); j++) {
			if (dc[i][j].x < 0 || dc[i][j].y < 0 || dc[i][j].x>100 || dc[i][j].y>100) continue;
			map[dc[i][j].x][dc[i][j].y] = 1;
		}
	}
}
int count_rectangle() {
	int count = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1] == 4)
				count++;
		}
	}
	return count;
}
int main() {
	int res;
	get_input();
	generate_dragon_curve();
	draw();
	res = count_rectangle();
	printf("%d\n", res);	
}