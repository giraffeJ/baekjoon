#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int i, j, k, n, m, siz, temp, x, y, sum, res;
int a[201], b[201], d[20030];
int main() {
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sum = 0;
	for (i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		sum += b[i];
	}
	for (i = 1; i <= sum; i++) {
		d[i] = -1;
	}
	d[b[1]] = a[1];
	for (i = 2; i <= n; i++) {
		for (j = sum; j >= 0; j--) {
			if (j - b[i] >= 0 && d[j - b[i]] != -1) {
				d[j] = max(d[j - b[i]] + a[i], d[j]);
				if (d[j] > 10000000) d[j] = 10000000;
			}
		}
	}
	res = 2100000000;
	for (i = 0; i <= sum; i++) {
		if (d[i] >= m) {
			res = i;
			break;
		}
	}
	printf("%d\n", res);
	scanf("%d %d", &n, &m);
}