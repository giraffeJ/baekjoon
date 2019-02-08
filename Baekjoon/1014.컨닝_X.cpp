#include<stdio.h>
int tcn, i, j, n, m, k, a[20][20], c[20][20], d[20][20][3], res, tc;
char temp;
int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	scanf("%d\n", &tcn);
	for (tc = 1; tc <= tcn; tc++) {
		scanf("%d %d", &n, &m);
		for (i = 1; i <= n; i++) {
			scanf("\n");
			for (j = 1; j <= m; j++) {
				scanf("%c", &temp);
				if (temp == '.') a[j][k] = 0;
				else if (temp == 'x') a[j][k] = 1;
				d[j][k][1] = d[j][k][2] = 0;
			}
		}
		res = -2100000000;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				d[i][j][1] = max(max(d[i][j - 1][2], d[i - 1][j - 1][2]), max(max(d[i - 1][j][1], d[i - 1][j][2]), d[i - 1][j + 1][2])) + 1;
				d[i][j][2] = max(max(d[i][j][1] - 1, d[i][j - 1][1]), max(d[i - 1][j - 1][1], d[i - 1][j + 1][1]));
				res = max(res, max(d[i][j][2], d[i][j][1]));				
			}
		}
		
		printf("%d\n", res);
	}
	scanf("%d", &tcn);
}



/*
void cheat(int x, int y, int cnt) {
if (x == n && y == m + 1) {
if (cnt > res) {
res = cnt;
}
}
else if (y == m + 1) {
cheat(x + 1, 1, cnt);
}
else {
if ((n - x)*m + (m - y + 1) * 2 / 3 + cnt >= res) {
if (c[x][y - 1] == 1 || c[x - 1][y - 1] == 1 || a[x][y] == 1 || c[x - 1][y + 1] == 1) {
cheat(x, y + 1, cnt);
}
else {
c[x][y] = 1;
cheat(x, y + 1, cnt + 1);
c[x][y] = 0;
cheat(x, y + 1, cnt);
}
}
}
}*/ //DP로 다시 풀어야 함..