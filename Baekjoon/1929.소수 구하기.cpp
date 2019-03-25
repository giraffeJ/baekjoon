#include<stdio.h>
int prime_check[1000010], n, m;
int main() {
	prime_check[1] = 1;
	scanf("%d %d", &m, &n);
	for (int i = 2; i <= n; i++) {
		if (prime_check[i] == 0) {
			if (i >= m) printf("%d\n", i);
			for (int j = i * 2; j <= n; j += i) {
				prime_check[j] = 1;
			}
		}
	}
	return 0;
}