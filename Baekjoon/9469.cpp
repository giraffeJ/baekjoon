#include<stdio.h>
int tcn, n, i;
double d, a, b, f;
int main() {
	scanf("%d", &tcn);
	for (i = 1; i <= tcn; i++) {
		scanf("%d %lf %lf %lf %lf", &n, &d, &a, &b, &f);
		printf("%d %.2lf\n", n, (d / (a + b))*f);
	}
	scanf("%d ", &i);
}