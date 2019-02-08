#include<stdio.h>
int i, j, a[20001], sum, cnt, n, m;
int main() {
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	j = 1;
	sum = 0;
	for (i = 1; i <= n; i++) {
		if (sum < m) sum += a[i];
		while (sum > m) {
			sum -= a[j++];
			if (j >= i) break;
		}
		if (sum == m) {
			cnt++;
			sum -= a[j++];
		}
	}
	printf("%d\n", cnt);
	scanf("%d %d", &n, &m);
}