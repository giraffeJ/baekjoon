#include<stdio.h>
#include<vector>
using namespace std;
int i, j, k, n, m, x, y, res;
vector<int> a[1001], b[1001];
void check(int start) {
	int i, j, c[1001], r, f, q[10001];
	for (i = 1; i <= n; i++) c[i] = 0;
	r = f = 0;
	q[++r] = start;
	c[start] = 1;
	c[0] = 1;
	while (r > f) {
		x = q[++f];
		for (i = 0; i < a[x].size(); i++) {
			if (c[a[x][i]] == 0) {
				c[a[x][i]] = 1;
				c[0]++;
				q[++r] = a[x][i];
			}
		}
	}
	r = f = 0;
	q[++r] = start;
	while (r > f) {
		x = q[++f];
		for (i = 0; i < b[x].size(); i++) {
			if (c[b[x][i]] == 0) {
				c[b[x][i]] = 1;
				c[0]++;
				q[++r] = b[x][i];
			}
		}
	}
	if (c[0] == n) res++;
}
int main() {
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		a[y].push_back(x);
		b[x].push_back(y);
	}
	res = 0;
	for (i = 1; i <= n; i++) {
		check(i);
	}
	printf("%d\n", res);
	scanf("%d", &n);
}
