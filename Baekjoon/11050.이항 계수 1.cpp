#include<stdio.h>
int i, j, k, n, m;
int main() {
	scanf("%d %d", &n, &m);
	k = 1;
	for (i = 1; i <= m; i++) {
		k *= n;
		n--;
	}
	for (i = 1; i <= m; i++) {
		k /= i;
	}
	printf("%d\n", k);
	scanf("%d %d", &n, &m);
}