#include<stdio.h>
int a, b, c, d, n, m, i, j;
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &m);
		a = 1;
		b = 0;
		for (j = 1; j <= m; j++) {
			c = a + b;
			a = b;
			b = c;
		}
		printf("%d %d\n", a, b);		
	}
}