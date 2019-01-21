#include<stdio.h>
long long int i, j, n, m, a, b, c;
int main() {
	scanf("%lld", &n);
	if (n == 1) printf("1\n");
	else if (n == 2) printf("1\n");
	else {
		a = 1;
		b = 1;
		for (i = 3; i <= n; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		printf("%lld\n", c);
	}
	scanf("%lld", &n);
}