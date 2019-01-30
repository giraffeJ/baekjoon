#include<stdio.h>
int i, j, k, n, m, l, res, x, d[70000][20], a[20][20];
int tsp(int state, int fin) {
	int i, x, prev_state, mini = 2100000000;
	if (state - 1 == (1 << fin)) {
		if (d[state][fin] == 0) return 2100000000;
		return d[state][fin];
	}
	else if (d[state][fin] != 0) {
		return d[state][fin];
	}
	else {
		prev_state = state - (1 << fin);
		for (i = 1; i < n; i++) {
			if (a[i][fin] != 0 && i != fin && (state&(1 << i)) == (1 << i)) {
				x = tsp(prev_state, i);
				x = x + a[i][fin];
				if (x < mini) mini = x;
			}
		}
		d[state][fin] = mini;
		return mini;
	}
}
int main() {
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			d[(1 << i) | (1 << j)][j] = a[i][j];
		}
	}
	res = 2100000000;
	for (i = 1; i < n; i++) {
		if (a[i][0] != 0) {
			x = tsp((1 << n) - 1, i);
			x = x + a[i][0];
			if (x < res) res = x;
		}
	}
	printf("%d\n", res);
	scanf("%d", &n);
}