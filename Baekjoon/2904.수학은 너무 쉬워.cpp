#include<stdio.h>
int i, j, k, n, m, temp[201], sum, cnt, gcd[100001];
int a[1000030], d[201][100001];
int abs(int x) {
	if (x < 0) return x * (-1);
	else return x;
}
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &d[i][0]);
		if (d[i][0] > m) m = d[i][0];
		temp[i] = d[i][0];
	}
	for (i = 2; i <= m; i++) {
		a[i] = 1;
	}
	for (i = 2; i <= m; i++) {
		if (a[i] == 1) {
			d[0][++k] = i;
			for (j = i; j <= m; j += i) {
				a[j] = 0;
			}
			sum = 0;
			for (j = 1; j <= n; j++) {
				sum += temp[j];
				while (temp[j] % i == 0) {
					d[j][k]++;
					temp[j] /= i;
					if (temp[j] == 1) break;
				}
			}
			if (sum == n) break;
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= k; j++) {
			d[n + 1][j] += d[i][j];
		}
	}
	sum = 1;
	for (i = 1; i <= k; i++) {
		gcd[i] = d[n + 1][i] / n;
		for (j = 1; j <= gcd[i]; j++) {
			sum *= d[0][i];

		}
	}
	cnt = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= k; j++) {
			if (d[i][j] < gcd[j]) {
				cnt += gcd[j] - d[i][j];
			}
		}
	}
	printf("%d %d\n", sum, cnt);
	scanf("%d", &n);
}