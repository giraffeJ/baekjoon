#include<stdio.h>
int tcn, i, j, n, m, val, a, b;
double x, y, z;
int main() {
	scanf("%d", &tcn);
	for (i = 1; i <= tcn; i++) {
		scanf("%d %d", &n, &m);
		a = m;
		b = n;
		x = 1;
		for (j = 1; j <= n; j++) {
			x = x * a / b;
			a--;
			b--;
		}
		printf("%.0lf\n", x);
	}
	scanf("%d", &tcn);
}