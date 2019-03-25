#include<stdio.h>
int prime_check[10010];
int tcn, n, k;
int main() {
	prime_check[1] = 1;
	for (int i = 2; i <= 10000; i++) {
		if (prime_check[i] == 0) {
			for (int j = i * 2; j <= 10000; j += i)
				prime_check[j] = 1;
		}
	}
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		scanf("%d", &n);
		for (int i = n / 2; i >= 2; i--) {
			if (prime_check[i] == 0) {
				k = n - i;
				if (prime_check[k] == 0) {
					printf("%d %d\n", i, k);
					break;
				}
			}
		}
	}
}