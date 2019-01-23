#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int i, j, k, n, m, vi[150001], seq, c[150001], x, y, rt, siz;
vector<int> a[150001];
struct list {
	int x;
	int y;
} node[150001];
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int max(int a, int b) {
	if (a < b) return b;
	else return a;
}
bool comp(list a, list b) {
	if (a.x < b.x) return true;
	else if (a.x == b.x) {
		if (a.y < b.y) return true;
		else return false;
	}
	else return false;
}
int dfs(int pos, int past) {
	int i, j, cnt, smin, temp;
	c[pos] = 1;
	vi[pos] = seq++;
	cnt = 0;
	smin = vi[pos];
	for (i = 0; i < a[pos].size(); i++) {
		if (c[a[pos][i]] == 0) {
			cnt++;
			j = a[pos][i];
			temp = dfs(j, pos);
			if (temp > vi[pos]) {
				node[++siz].x = min(pos, a[pos][i]);
				node[siz].y = max(pos, a[pos][i]);
			}
			if (temp < smin) smin = temp;
		}
		if (a[pos][i] != past && vi[a[pos][i]] < smin) {
			smin = vi[a[pos][i]];
		}
	}
	return smin;
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
			dfs(i, 0);
		}
	}
	sort(node + 1, node + siz + 1, comp);
	printf("%d\n", siz);
	for (i = 1; i <= siz; i++) {
		printf("%d %d\n", node[i].x, node[i].y);
	}
	printf("\n");
	scanf("%d %d", &n, &m);
}