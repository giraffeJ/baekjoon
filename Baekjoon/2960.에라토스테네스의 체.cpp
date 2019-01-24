#include<stdio.h>
int i, j, k, n, m, a[10001], cnt;
int main() {
	scanf("%d %d", &n, &m);
	for (i = 2; i <= n; i++) {
		a[i] = i;
	}
	cnt = 0;
	for (i = 2; i <= n; i++) {
		if (a[i] != 0) {
			for (j = i; j <= n; j += i) {
				if (a[j] != 0) {
					a[j] = 0;
					cnt++;
					if (cnt == m) {
						printf("%d\n", j);
						break;
					}
				}
			}
		}
		if (cnt == m) break;
	}
	scanf("%d %d", &n, &m);
}