#include<stdio.h>
int i, j, n;
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n - i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}
}