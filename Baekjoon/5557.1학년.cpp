#include<stdio.h>
long long int i, j, k, n, m, ans, d[201][1001], a[201];
int main() {
	scanf("%lld", &n);
	m = 0;
	for (i = 1; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	scanf("%lld", &ans);
	d[1][a[1]] = 1;
	for (i = 2; i < n; i++) {
		for (j = 0; j <= 20; j++) {
			if (j + a[i] <= 20) d[i][j] += d[i - 1][j + a[i]];
			if (j - a[i] >= 0) d[i][j] += d[i - 1][j - a[i]];
		}
	}
	printf("%lld\n", d[n - 1][ans]);
	scanf("%lld", &n);
}