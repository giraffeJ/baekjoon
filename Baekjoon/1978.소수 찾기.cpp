#include<stdio.h>
int prime_check[1010], n, k, res;
int main() {
	prime_check[1] = 1;
	for (int i = 2; i <= 1010; i++) {
		if (prime_check[i] == 0) {
			for (int j = i + i; j <= 1010; j += i) {
				prime_check[j] = 1;
			}
		}
	}
	scanf("%d", &n);	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		if (prime_check[k] == 0) res++;
	}
	printf("%d\n", res);
}