#include<stdio.h>
int max(int a, int b) {
	return a > b ? a : b;
}
int a, b;
int reverse(int a) {
	int re = 0;
	for (int i = 1; i <= 3; i++) {
		re = re * 10 + a % 10;
		a /= 10;
	}
	return re;
}
int main() {
	scanf("%d %d", &a, &b);
	printf("%d\n", max(reverse(a), reverse(b)));
}