#include<stdio.h>
#define MAX 1000000000000000
long long int i, j, k, n, m, sum, a[101], comb[101][101], cr, cal, ck;
double x, b[101];
int main() {
	scanf("%lld", &m);
	n = -999;
	sum = 0;
	for (i = 1; i <= m; i++) {
		scanf("%lld", &a[i]);
		if (a[i] > n) n = a[i];
		sum = sum + a[i];
	}
	scanf("%lld", &k);
	if (k > n) printf("0.0\n");
	else if (k == 1 || m == 1) printf("1.0\n");
	else {
		comb[0][0] = 1;
		for (i = 1; i <= n; i++) {
			comb[i][0] = 1;
			for (j = 1; j <= i; j++) {
				comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
			}
		}
		b[0] = sum + 1;
		for (i = 1; i <= k; i++) {
			b[i] = b[i - 1] - 1;
		}
		cr = 1;
		x = 0;
		for (i = 1; i <= m; i++) {
			x += comb[a[i]][k];
			if (x > MAX) x /= b[cr++];
		}
		ck = k;
		while (1) {
			x *= ck;
			ck--;
			if (x > MAX) x /= b[cr++];
			if (ck == 0) break;
		}
		for (; cr <= k; cr++) {
			x /= b[cr];
		}
		printf("%.15lf\n", x);
	}
	scanf("%lld", &m);
}