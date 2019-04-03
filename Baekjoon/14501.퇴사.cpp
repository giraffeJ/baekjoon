#include<stdio.h>
int n, t[25], p[25], d[25];
int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &t[i], &p[i]);
	}
	for (int i = 1; i <= n; i++) {
		d[i] = max(d[i - 1], d[i]);
		if (i + t[i] - 1 <= n) d[i + t[i] - 1] = max(d[i + t[i] - 1], d[i - 1] + p[i]);
	}
	printf("%d\n", d[n]);
}