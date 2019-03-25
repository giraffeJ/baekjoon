#include<stdio.h>
int prime_check[250010], prime_count[250010], cnt, n;
int main() {
	prime_check[1] = 1;
	for (int i = 2; i <= 250000; i++) {
		if (prime_check[i] == 0) {
			cnt++;
			for (int j = i * 2; j <= 250000; j+=i) {
				prime_check[j] = 1;
			}
		}
		prime_count[i] = cnt;
	}
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		printf("%d\n", prime_count[n * 2] - prime_count[n]);
	}
	return 0;
}