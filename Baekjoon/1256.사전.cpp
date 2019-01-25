#include<stdio.h>
long long int i, j, k, n, m, l, siz, cnt, s, cn, cm, a[1001], d[250][250];
int main() {
	scanf("%lld %lld %lld", &n, &m, &l);
	siz = n + m;
	d[0][0] = 1;
	for (i = 1; i <= siz; i++) {
		d[i][0] = 1;
		for (j = 1; j <= i; j++) {
			d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
			if (d[i][j] > 1000000000) d[i][j] = 2100000000;
		}
	}
	if (l > d[siz][n]) printf("-1");
	else {
		for (i = 1; i <= siz; i++) {
			if (n == 0) {
				a[i] = 1;
				m--;
			}
			else if (m == 0) {
				a[i] = 0;
				n--;
			}
			else {
				if (d[n + m - 1][m] >= l) {
					a[i] = 0;
					n--;
				}
				else {
					a[i] = 1;
					l -= d[n + m - 1][m];
					m--;
				}
			}
		}
		for (i = 1; i <= siz; i++) {
			if (a[i] == 1) printf("z");
			else printf("a");
		}
		printf("\n");
	}
	scanf("%lld %lld %lld", &n, &m, &l);
}