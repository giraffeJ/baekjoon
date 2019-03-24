#include<stdio.h>
int a[10], n;
int main() {
	scanf("%d", &n);
	while (n > 0) {
		a[n % 10]++;
		n /= 10;
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= a[i]; j++) {
			printf("%d", i);
		}
	}
}