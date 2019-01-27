#include<stdio.h>
int i, j, k, n, m, d[201][201][5];
int main() {
	scanf("%d %d", &n, &m);
	d[0][1][1] = d[1][0][4] = 1;
	for (j = 1; j <= m; j++) {
		d[1][j][0] = 1;
		d[1][j][4] = 1;
	}
	for (i = 2; i <= n; i++) {
		d[i][1][0] = 1;
		d[i][1][1] = 1;
		for (j = 2; j <= m; j++) {
			d[i][j][1] = d[i - 1][j][1] + d[i - 1][j][2];
			d[i][j][2] = d[i - 1][j][4];
			d[i][j][3] = d[i][j - 1][1];
			d[i][j][4] = d[i][j - 1][3] + d[i][j - 1][4];
			d[i][j][0] = d[i][j][1] + d[i][j][2] + d[i][j][3] + d[i][j][4];
		}
	}
	printf("%d\n", d[n][m][0]);
	scanf("%d %d", &n, &m);
}