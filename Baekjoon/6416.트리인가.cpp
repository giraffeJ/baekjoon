#include<stdio.h>
#include<vector>
using namespace std;
int i, j, k, n, m, x, y, tcn, sw, root, c[100030], p[100030], vi[100030], q[100030], r, f;
int max(int a, int b) {
	return a > b ? a : b;
}
vector<int> node;
vector<int> adj[100030];
int main() {
	tcn = 0;
	while (1) {
		tcn++;
		scanf("%d %d", &x, &y);
		if (x == -1 && y == -1) break;
		sw = 0;
		for (i = 1; i <= n; i++) {
			c[i] = p[i] = vi[i] = 0;
			adj[i].clear();
		}
		node.clear();
		n = -999;
		while (1) {
			if (x == 0 && y == 0) break;
			if (c[x] == 0) node.push_back(x);
			c[x] = 1;
			if (c[y] == 0) node.push_back(y);
			c[y] = 1;
			p[y]++;
			adj[x].push_back(y);
			if (p[y] >= 2) sw = 1;
			n = max(max(x, y), n);
			scanf("%d %d", &x, &y);
		}
		if (sw == 0) {
			r = f = 0;
			for (i = 0; i < node.size(); i++) {
				if (p[node[i]] == 0) {
					q[++r] = node[i];
				}
			}
			if (r == 0 || r >= 2) {
				sw = 1;
			}
			else {
				vi[q[f + 1]] = 1;
				while (r > f) {
					x = q[++f];
					for (i = 0; i < adj[x].size(); i++) {
						if (vi[adj[x][i]] == 1) {
							sw = 1;
							break;
						}
						else {
							q[++r] = adj[x][i];
							vi[adj[x][i]] = 1;
						}
					}
				}
				for (i = 0; i < node.size(); i++) {
					if (vi[node[i]] == 0) break;
				}
				if (i != node.size()) sw = 1;
			}
		}
		if (sw == 1 && node.size() != 0) {
			printf("Case %d is not a tree.\n", tcn);
		}
		else
			printf("Case %d is a tree.\n", tcn);
	}
}