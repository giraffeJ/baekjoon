#include<stdio.h>
int i, j, k, n, m, a[4000030], b[500001], sum, cnt;
int main() {
	for (i = 2; i <= 4000000; i++) {
		a[i] = 1;
	}
	for (i = 2; i <= 4000000; i++) {
		if (a[i] == 1) {
			b[++a[0]] = i;
			for (j = i + i; j <= 4000000; j += i) {
				a[j] = 0;
			}
		}
	}
	scanf("%d", &n);
	sum = 0;
	j = 1;
	for (i = 1; i <= a[0]; i++) {
		sum += b[i];
		while (sum > n) {
			sum -= b[j++];
		}
		if (sum == n) {
			cnt++;
			sum -= b[j++];
		}
	}
	printf("%d\n", cnt);
	scanf("%d", &n);
}