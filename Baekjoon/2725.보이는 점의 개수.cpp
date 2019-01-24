#include<stdio.h>
int i, j, k, n, m, l, d[2001], a[2001], g;
int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int main() {
	scanf("%d", &n);
	m = -999;
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] > m) m = a[i];
	}
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= m; j++) {
			g = gcd(i, j);
			if (g == 1) {
				d[max(i, j)]++;
			}
		}
	}
	d[0] = 2;
	for (i = 1; i <= m; i++) {
		d[i] = d[i - 1] + d[i];
	}
	for (i = 1; i <= n; i++) {
		printf("%d\n", d[a[i]]);
	}
	scanf("%d", &n);
}