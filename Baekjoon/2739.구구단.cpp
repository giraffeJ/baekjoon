#include<stdio.h>
int i, n;
int main() {
	scanf("%d", &n);
	for (i = 1; i <= 9; i++) {
		printf("%d * %d = %d\n", n, i, n*i);
	}
}