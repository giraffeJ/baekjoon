#include<stdio.h>
int i, j, k, n, m, h, x, d[600001], min, cnt;
int main() {
	scanf("%d %d", &n, &h);
	for (i = 1; i <= n; i++) {
		scanf("%d", &x);
		if (i % 2 == 1) {
			d[1] += 1;
			d[x + 1] -= 1;
		}
		if (i % 2 == 0) {
			d[h - x + 1] += 1;
		}
	}
	min = 2100000000;
	for (i = 1; i <= h; i++) {
		d[i] = d[i - 1] + d[i];
		if (d[i] < min) {
			min = d[i];
		}
	}
	cnt = 0;
	for (i = 1; i <= h; i++) {
		if (d[i] == min) cnt++;
	}
	printf("%d %d\n", min, cnt);
	scanf("%d %d", &n, &h);

}