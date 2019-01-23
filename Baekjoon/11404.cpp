#include<stdio.h>
#define MAX 2100000000; //플로이드 워셜 알고리즘으로 푸는 문제.
int i, j, k, n, m, a[201][201], d[201][201], x, y, z;
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int main() {
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			d[i][j] = MAX;
		}
	}
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		d[x][y] = min(d[x][y], z);
	}
	for (i = 1; i <= n; i++) {
		d[i][i] = 0;
	}
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			if (d[i][k] != 2100000000) {
				for (j = 1; j <= n; j++) {
					if (d[k][j] != 2100000000)
						d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (d[i][j] == 2100000000) printf("0 ");
			else printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	scanf("%d", &n);
}