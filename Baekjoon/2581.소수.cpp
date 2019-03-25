#include<stdio.h>
int prime_check[10010], m, n, min_prime, sum_prime;
int main() {
	prime_check[1] = 1;
	for (int i = 2; i <= 10000; i++) {
		if (prime_check[i] == 0) {
			for (int j = i * 2; j <= 10000; j += i) {
				prime_check[j] = 1;
			}
		}
	}
	scanf("%d %d", &m, &n);
	for (int i = m; i <= n; i++) {
		if (min_prime == 0 && prime_check[i] == 0) min_prime = i;
		if (prime_check[i] == 0) sum_prime += i;
	}
	if (sum_prime == 0)
		printf("-1\n");
	else 
		printf("%d\n%d\n", sum_prime, min_prime);
}