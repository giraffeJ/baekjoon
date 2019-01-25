#include<stdio.h>
#include<vector>
using namespace std;
int i, j, k, n, m, a[2001][2001], d[2001][2001], x, y;
vector<int> lg[2001][2001];
int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	d[1][1] = k;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (i != 1 || j != 1) {
				if (a[i][j - 1] == 1) x = (d[i][j - 1] + 1) / 2;
				else x = d[i][j - 1] / 2;
				if (a[i - 1][j] == 0) y = (d[i - 1][j] + 1) / 2;
				else y = d[i - 1][j] / 2;
				d[i][j] = x + y;
			}
		}
	}
	x = y = 1;
	while (1) {
		if (d[x][y] % 2 == 1 && a[x][y] == 1 || d[x][y] % 2 == 0 && a[x][y] == 0)
			y++;
		else if (d[x][y] % 2 == 1 && a[x][y] == 0 || d[x][y] % 2 == 0 && a[x][y] == 1)
			x++;
		if (x == n + 1 || y == m + 1) break;
	}
	printf("%d %d\n", x, y);
	scanf("%d", &n);
}