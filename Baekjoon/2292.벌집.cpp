#include<stdio.h>
int i, k, n;
int main() {
	scanf("%d", &n);
	k = 1;
	for (i = 1; i <= 18258; i++) {
		if (n <= k) {
			printf("%d\n", i);
			break;
		}
		k += (i * 6);
	}
}