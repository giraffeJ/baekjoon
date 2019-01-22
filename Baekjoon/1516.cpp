#include<stdio.h>
#include<vector>
using namespace std;
int i, j, k, n, m, x, y, r, f, q[100001], bt[6000], cnt[6000], d[6000], c[6000];
vector <int> a[6001];
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &bt[i]);
		while (1) {
			scanf("%d", &x);
			if (x == -1) break;
			a[x].push_back(i);
			cnt[i]++;
		}
	}
	r = f = 0;
	for (i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			q[++r] = i;
			d[i] = bt[i];
			c[i] = 1;
		}
	}
	while (r > f) {
		x = q[++f];
		for (i = 0; i < a[x].size(); i++) {
			if (c[a[x][i]] == 0 || c[a[x][i]] == 1 && d[a[x][i]] < d[x] + bt[a[x][i]]) {
				c[a[x][i]] = 1;
				d[a[x][i]] = d[x] + bt[a[x][i]];
				q[++r] = a[x][i];
			}
		}
	}
	for (i = 1; i <= n; i++) {
		printf("%d\n", d[i]);
	}
	scanf("%d", &n);
}