#include<stdio.h>
int i, j, k, n, m, max, a[1010][1010], ver[1010][1010], hor[1010][1010], sq[1010][1010];
char t[1010];
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int main() {
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%s", &t);
		for (j = 1; j <= m; j++) {
			a[i][j] = t[j - 1] - 48;
			if (a[i][j] == 0) {
				ver[i][j] = 0;
				hor[i][j] = 0;
			}
			else {
				ver[i][j] = ver[i - 1][j] + 1;
				hor[i][j] = hor[i][j - 1] + 1;
			}
		}
	}
	max = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (a[i][j] == 1) {
				sq[i][j] = min(min(sq[i - 1][j - 1], hor[i][j - 1]), ver[i - 1][j]) + 1;
				if (sq[i][j] > max) max = sq[i][j];
			}
		}
	}
	printf("%d\n", max*max);
	scanf("%d", &n);
}