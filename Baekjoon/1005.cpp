#include<stdio.h>
int i, j, n, m, tcn, d[2001], a[2001][2001], cost[2001], x, y, dt;
int find(int x) {
	if (a[x][0] == 0) {
		return d[x];
	}
	else {
		int max = -2100000000;
		for (int i = 1; i <= a[x][0]; i++) {
			if (cost[a[x][i]] == -1) cost[a[x][i]]=find(a[x][i]);
			if (cost[a[x][i]] > max) {
				max = cost[a[x][i]];
			}
		}
		return max+d[x];
	}
}
int main() {
	scanf("%d", &tcn);
	for (i = 1; i <= tcn; i++) {
		scanf("%d %d", &n, &m);
		for (j = 1; j <= n; j++) {
			scanf("%d", &d[j]);
			cost[j] = -1;
		}
		for (j = 1; j <= m; j++) {
			scanf("%d %d", &x, &y);
			a[y][++a[y][0]] = x;
		}
		scanf("%d", &dt);
		printf("%d\n", find(dt));
	}
	scanf("%d", &tcn);
}