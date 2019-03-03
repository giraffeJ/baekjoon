#include<stdio.h>
int n, i, sum;
char a[101];
int main() {
	scanf("%d", &n);
	scanf("%s", &a);
	for (i = 0; i < n; i++) {
		sum += (a[i] - 48);
	}
	printf("%d\n", sum);
	scanf("%d", &n);
}