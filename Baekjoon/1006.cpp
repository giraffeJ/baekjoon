#include<stdio.h>
int tcn, n, i, j, k, m, d[4][10010], a[3][10010], cnt1, cnt2, temp1, temp2, res, ch;
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int findres(int start, int code) {
	int j;
	int k = 0;
	for (j = start; j <= n; j++) {
		d[1][j] = d[2][j] = d[3][j - 1] + 1;
		if (j != 2 || code != 1) 
			if (a[1][j] + a[1][j - 1] <= m) d[1][j] = min(d[2][j - 1] + 1, d[1][j]);
		if (j != 2 || code != 2) 
			if (a[2][j] + a[2][j - 1] <= m) d[2][j] = min(d[1][j - 1] + 1, d[2][j]);
		d[3][j] = min(min(d[3][j - 1] + 2, d[1][j]+1), d[2][j]+1);
		if(j!=2 || code==0)
			if (a[1][j] + a[1][j - 1] <= m && a[2][j] + a[2][j - 1] <= m) d[3][j] = min(d[3][j], d[3][j - 2] + 2);
		if (code==3 && j == n) k = 1;
		if (a[1][j] + a[2][j] <= m) d[3][j] = min(d[3][j], d[3][j - 1] + 1 - k);
	}
	return d[3][n];
}
int main() {
	scanf("%d", &tcn);
	for (i = 1; i <= tcn; i++) {
		scanf("%d %d", &n, &m);
		for (j = 1; j <= 2; j++) {
			for (k = 1; k <= n; k++) {
				scanf("%d", &a[j][k]);
			}
		}
		res = 2100000000;
		d[1][0] = d[2][0] = d[3][0] = 0;
		d[1][1] = d[2][1] = 1;
		d[3][1] = 2;
		if (a[1][1] + a[2][1] <= m) d[3][1] = 1;
		res = min(res, findres(2, 0));
		if (a[1][1] + a[1][n] <= m) {
			temp1 = a[1][n];
			a[1][n] = 0;
			d[3][1] = 2;
			res = min(res, findres(2, 1));
			if (a[2][1] + a[2][n] <= m) {
				temp2 = a[2][n];
				a[2][n] = 0;
				a[1][n] = temp1;
				res = min(res, findres(2, 2));
				a[1][n] = 0;
				d[1][2] = d[2][2] = d[3][1] + 1;
				d[3][2] = d[3][1] + 2;
				if (a[1][2] + a[2][2] <= m) d[3][2] = d[3][1] + 1;
				res = min(res, findres(3, 3));
			}
		}
		else if (a[2][1] + a[2][n] <= m) {
			temp2 = a[2][n];
			a[2][n] = 0;
			d[3][1] = 2;
			res = min(res, findres(2, 2));
		}
		printf("%d\n", res);
	}
	scanf("%d", &tcn);
}