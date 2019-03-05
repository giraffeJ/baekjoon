#include<stdio.h>
int nc[10], i, a, b, c, n;
int main() {
	scanf("%d %d %d", &a, &b, &c);
	n = a * b*c;
	while (n > 0) {
		nc[n % 10]++;
		n /= 10;
	}
	for (i = 0; i <= 9; i++) {
		printf("%d\n", nc[i]);
	}
	scanf("%d", &n);
}