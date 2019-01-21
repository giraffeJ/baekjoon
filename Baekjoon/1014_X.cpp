#include<stdio.h>
int tcn, i, j, n, m, k, a[20][20], c[20][20], res;
char temp;
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
}
int main() {
	scanf("%d\n", &tcn);
	for (i = 1; i <= tcn; i++) {
		scanf("%d %d", &n, &m);
		for (j = 1; j <= n; j++) {
			scanf("\n");
			for (k = 1; k <= m; k++) {
				scanf("%c", &temp);
				if (temp == '.') a[j][k] = 0;
				else if (temp == 'x') a[j][k] = 1;
			}
		}
		res = -2100000000;
		cheat(1, 1, 0);
		printf("%d\n", res);
	}
	scanf("%d", &tcn);
}