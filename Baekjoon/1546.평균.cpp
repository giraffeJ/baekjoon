#include<stdio.h>
int i;
double n, k, avg, m = -1;
double max(double a, double b) {
	return a > b ? a : b;
}
int main() {
	scanf("%lf", &n);
	for (i = 1; i <= n; i++) {
		scanf("%lf", &k);
		m = max(m, k);
		avg += k;
	}
	avg /= n;
	avg *= 100;
	avg /= m;
	printf("%lf\n", avg);
	scanf("%lf", &n);
}