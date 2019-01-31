#include<stdio.h>
typedef long long int lli; //마름모 주의..
lli i, j, k, n, m, tcn, tc, sw, a[5][3], d[5][5], seq[6], c[6];
int cd() {
	lli i, di = d[seq[4]][seq[1]];
	for (i = 1; i <= 3; i++) {
		if (d[seq[i]][seq[i + 1]] != di) break;
	}
	if (d[seq[1]][seq[3]] != d[seq[2]][seq[4]]) return 0;
	if (i == 4) return 1;
	else return 0;
}
void check(int pos) {
	int i;
	if (pos == 5) {
		int ce = cd();
		if (ce == 1) {
			sw = 1;
		}
	}
	else if (sw == 0) {
		for (i = 1; i <= 4; i++) {
			if (c[i] == 0) {
				seq[pos] = i;
				c[i] = 1;
				check(pos + 1);
				c[i] = 0;
				if (sw == 1) break;
			}
		}
	}

}
lli dis(lli x1, lli y1, lli x2, lli y2) {
	return (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
}
int main() {
	scanf("%lld", &tcn);
	for (tc = 1; tc <= tcn; tc++) {
		for (i = 1; i <= 4; i++) {
			scanf("%lld %lld", &a[i][1], &a[i][2]);
		}
		for (i = 1; i <= 4; i++) {
			for (j = 1; j <= 4; j++) {
				d[i][j] = dis(a[i][1], a[i][2], a[j][1], a[j][2]);
			}
		}
		sw = 0;
		check(1);
		printf("%lld\n", sw);
	}
	scanf("%d", &n);
}