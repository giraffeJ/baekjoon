#include<stdio.h>
int n, m, i, j, x1, x2, y1, y2, s, e, t, pos, dir;
long long int d[4][300010], k2, k3;
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1 += 100000;
		x2 += 100000;
		d[1][x1] = d[1][x1] + y2 - y1;
		d[1][x2 + 1] = d[1][x2 + 1] + y1 - y2;

		s = min(x1 + y2, x2 + y1);
		e = max(x1 + y2, x2 + y1);
		d[2][x1 + y1 + 1] += 1;
		d[2][s + 1] -= 1;
		d[2][e + 1] -= 1;
		d[2][x2 + y2 + 1] += 1;

		s = min(x1 - y1, x2 - y2);
		e = max(x1 - y1, x2 - y2);
		d[3][x1 - y2 + 1] += 1;
		d[3][s + 1] -= 1;
		d[3][e + 1] -= 1;
		d[3][x2 - y1 + 1] += 1;
	}
	k2 = 0;
	k3 = 0;
	for (i = 1; i <= 300000; i++) {
		d[1][i] = d[1][i - 1] + d[1][i];
		k2 += d[2][i];
		d[2][i] = d[2][i - 1] + k2;
		k3 += d[3][i];
		d[3][i] = d[3][i - 1] + k3;
	}
	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		scanf("%d %d", &pos, &dir);
		if (dir == 1) printf("%lld\n", d[dir][pos + 100000] * d[dir][pos + 100000]);
		else printf("%lld\n", d[dir][pos + 100000] * d[dir][pos + 100000] * 2);

	}
	scanf("%d", &n);
}