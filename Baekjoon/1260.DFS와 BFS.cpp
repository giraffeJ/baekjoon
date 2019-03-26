#include<stdio.h>
int adj[1010][1010], c[1010], q[1000010];
int n, m, start, x, y;
void dfs(int pos) {
	c[pos] = 1;
	printf("%d ", pos);
	for (int i = 1; i <= n; i++) {
		if (adj[pos][i] == 1 && c[i]==0) {
			dfs(i);
		}
	}
}
void init() {
	for (int i = 1; i <= n; i++) c[i] = 0;
}
void bfs(int start) {
	int r = 0, f = 0, pos;
	q[++r] = start;
	c[start] = 1;
	while (r > f) {
		pos = q[++f];
		printf("%d ", pos);
		for (int i = 1; i <= n; i++) {
			if (adj[pos][i] == 1 && c[i] == 0) {
				c[i] = 1;
				q[++r] = i;
			}
		}
	}
}
int main() {
	scanf("%d %d %d", &n, &m, &start);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		adj[x][y] = adj[y][x] = 1;
	}
	dfs(start);
	init();
	printf("\n");
	bfs(start);
}