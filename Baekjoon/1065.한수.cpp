#include<stdio.h>
int i, k, a, b, c, n, res;
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		if (n < 100) {
			res++;
			continue;
		}
		k = i;
		a = k % 10;
		k /= 10;
		b = k % 10;
		k /= 10;
		c = a - b;
		while (k > 0) {
			a = b;
			b = k % 10;
			if (c != a - b) break;
			k /= 10;
		}
		if (k == 0) {
			res++;
		}
	}
	printf("%d\n", res);
}