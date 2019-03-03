#include<stdio.h>
int a, b, c;
int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a < b ? a : b;
}
int main() {
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", a + b + c - max(a, max(b, c)) - min(a, min(b, c)));
}