#include<stdio.h>
struct doc {
	int pri;
	int num;
};
doc q[10010];
int r, f, i, j, tcn, n, m, k;
int main() {
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		scanf("%d %d", &n, &m);
		m++; //to make 1-base
		r = f = 0;
		for (i = 1; i <= n; i++) {
			scanf("%d", &k);
			q[++r].pri = k;
			q[r].num = i;
		}
		for (i = 1; i <= n; ) {
			k = q[f + 1].pri;
			for (j = f + 2; j <= r; j++) {
				if (q[j].pri > k) break;
			}
			if (j == r + 1) {
				if (q[f + 1].num == m) printf("%d\n", i);
				i++;
				f++;
			}
			else {
				q[++r] = q[f + 1];
				f++;
			}
		}
	}
}