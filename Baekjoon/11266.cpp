#include<stdio.h>
#include<vector>
using namespace std;
int i, j, k, n, m, vi[20001], seq, c[20001], check[20001], x, y, rt;
vector<int> a[20001];
int dfs(int pos) {
	int i, j, cnt, min, temp;
	c[pos] = 1;
	vi[pos] = seq++;
	cnt = 0;
	min = 2100000000;
	for (i = 0; i < a[pos].size(); i++) {
		if (c[a[pos][i]] == 0) {
			cnt++;
			j = a[pos][i];
			temp = dfs(j);
			if (pos != rt && temp >= vi[pos])
				check[pos] = 1;
			if (temp < min) min = temp;
		}
		if (vi[a[pos][i]] < min) {
			min = vi[a[pos][i]];
		}
	}
	if (pos == rt) {
		if (cnt >= 2) {
			check[pos] = 1;
			check[0]++;
		}
	}
	return min;
}
int main() {
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	seq = 1;
	for (i = 1; i <= n; i++) {
		if (c[i] == 0) {
			rt = i;
			dfs(i);
		}
	}
	int cnt = 0;
	for (i = 1; i <= n; i++) {
		if (check[i] == 1) cnt++;
	}
	printf("%d\n", cnt);
	for (i = 1; i <= n; i++) {
		if (check[i] == 1) {
			printf("%d ", i);
		}
	}
	printf("\n");
	scanf("%d %d", &n, &m);
}