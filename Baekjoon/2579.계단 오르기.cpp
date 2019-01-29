#include<stdio.h>
int i, j, k, n, m, a[1001], d[1001];
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	d[1] = a[1];
	d[2] = a[1] + a[2];
	for (i = 3; i <= n; i++) {
		d[i] = max(d[i - 2] + a[i], d[i - 3] + a[i - 1] + a[i]);
	}
	printf("%d\n", d[n]);
	scanf("%d", &n);
}