#include<stdio.h>
int n, m, k, i;
int main() {
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &k);
		if (k < m) {
			printf("%d ", k);
		}
	}
}