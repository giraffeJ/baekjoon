#include<stdio.h>
int a[10010], n, k;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		a[k]++;
	}
	for (int i = 1; i <= 10000; i++) {
		for (int j = 1; j <= a[i]; j++) {
			printf("%d\n", i);
		}
	}
	return 0;
}