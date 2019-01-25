#include<stdio.h>
long long int i, j, k, n, m, tm, a[30], fac, tfac, cnt, sum, c[30];
int main() {
	scanf("%lld", &n);
	scanf("%lld", &k);
	if (k == 1) {
		scanf("%lld", &m);
		fac = 1;
		for (i = 1; i <= n; i++) {
			fac *= i;
		}
		tm = m;
		for (i = 1; i <= n; i++) {
			tfac = fac / (n - i + 1);
			cnt = 1;
			sum = tfac;
			while (sum < tm) {
				sum += tfac;
				cnt++;
			}
			sum -= tfac;
			tm -= sum;
			for (j = 1; j <= n; j++) {
				if (c[j] == 0) {
					cnt--;
					if (cnt == 0) {
						printf("%lld ", j);
						c[j] = 1;
						break;
					}
				}
			}
			fac /= (n - i + 1);
		}
		printf("\n");
	}
	else {
		for (i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		fac = 1;
		for (i = 1; i <= n; i++) {
			fac *= i;
		}
		tm = 0;
		for (i = 1; i <= n; i++) {
			tfac = fac / (n - i + 1);
			cnt = 0;
			for (j = 1; j <= n; j++) {
				if (j == a[i]) break;
				if (c[j] == 0) {
					cnt++;
				}
			}
			c[a[i]] = 1;
			tm += (cnt*tfac);
			fac /= (n - i + 1);
		}
		printf("%lld\n", tm + 1);
	}
	scanf("%lld", &n);
}