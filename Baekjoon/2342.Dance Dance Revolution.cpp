#include<stdio.h>
int i, j, k, n, m, x, y, l, res;
int d[100030][5][5];
int step[25][2] = { { 0, 0 },{ 0, 1 },{ 0, 2 },{ 0, 3 },{ 0, 4 },{ 1, 0 },{ 1, 2 },{ 1, 3 },{ 1, 4 },{ 2, 0 },{ 2, 1 },{ 2, 3 },{ 2, 4 },{ 3, 0 },{ 3, 1 },{ 3, 2 },{ 3, 4 },{ 4, 0 },{ 4, 1 },{ 4, 2 },{ 4, 3 } };
int energy[5][5] = { { 0, 2, 2, 2, 2 },{ 2, 1, 3, 4, 3 },{ 2, 3, 1, 3, 4 },{ 2, 4, 3, 1, 3 },{ 2, 3, 4, 3, 1 } };
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int main() {
	l = 0;
	d[0][0][0] = 1;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		for (i = 0; i <= 20; i++) {
			x = step[i][0];
			y = step[i][1];
			if (d[l][x][y] != 0) {
				if (x == n || y == n) {
					if (d[l + 1][x][y] == 0) d[l + 1][x][y] = 2100000000;
					d[l + 1][x][y] = min(d[l + 1][x][y], d[l][x][y] + 1);
				}
				else {
					if (d[l + 1][n][y] == 0) d[l + 1][n][y] = 2100000000;
					d[l + 1][n][y] = min(d[l + 1][n][y], d[l][x][y] + energy[x][n]);
					if (d[l + 1][x][n] == 0) d[l + 1][x][n] = 2100000000;
					d[l + 1][x][n] = min(d[l + 1][x][n], d[l][x][y] + energy[y][n]);
				}
			}
		}
		l++;
	}
	res = 2100000000;
	for (i = 0; i <= 20; i++) {
		x = step[i][0];
		y = step[i][1];
		if (d[l][x][y] != 0) {
			if (d[l][x][y] < res) res = d[l][x][y];
		}
	}
	printf("%d\n", res - 1);
	scanf("%d", &n);
}