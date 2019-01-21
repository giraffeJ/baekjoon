#include<stdio.h>
int i, j, n, m, a[100030], sum, len, res;
int main() {
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sum = 0;
	len = 0;
	res = 2100000000;
	j = 1;
	for (i = 1; i <= n; i++) {
		sum += a[i];
		len++;
		if (sum >= m) {
			while (sum >= m) {
				if (len < res) res = len;
				sum -= a[j];
				j++;
				len--;
			}
		}
	}
	if (res == 2100000000) printf("0\n");
	else printf("%d\n", res);
	scanf("%d %d", &n, &m);
}