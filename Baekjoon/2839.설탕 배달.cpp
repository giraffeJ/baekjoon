#include<stdio.h>
int a, b, n;
int main() {
	scanf("%d", &n);
	a = n / 5;
	b = n % 5;
	while (b % 3 != 0 && a > 0) {
		a -= 1;
		b += 5;
	}
	if (b % 3 == 0) {
		printf("%d\n", a + (b / 3));
	}
	else {
		printf("-1\n");
	}
	scanf("%d", &n);
}