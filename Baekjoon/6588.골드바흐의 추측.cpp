#include<stdio.h>
int i, j, k, n, m, a[1000030], b[100001], c[1000030];
int main() {
	for (i = 2; i <= 1000000; i++) {
		a[i] = 1;
	}
	for (i = 2; i <= 1000000; i++) {
		if (a[i] != 0) {
			a[0]++;
			b[a[0]] = i;
			for (j = i + i; j <= 1000000; j += i) {
				a[j] = 0;
			}
		}
	}
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		if (c[n] != 0) {
			printf("%d = %d + %d\n", n, c[n], n - c[n]);
		}
		for (i = 1; i <= a[0]; i++) {
			if (b[i] > n / 2) break;
			if (a[n - b[i]] == 1) {
				printf("%d = %d + %d\n", n, b[i], n - b[i]);
				c[n] = b[i];
				break;
			}
		}
		if (b[i] > n / 2) printf("Goldbach's conjecture is wrong.\n");
	}
	scanf("%d", &n);
}