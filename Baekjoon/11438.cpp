#include<stdio.h>
#include<vector>
using namespace std;
int i, j, k, n, m, c[100030], x, y, pos, r, f, lx, ly, pox, poy, q[100030], root[100030][40], level[100030];
vector<int> a[100030];
int main() {
	scanf("%d", &n);
	c[1] = -1;
	for (i = 1; i < n; i++) {
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	r = f = 0;
	q[++r] = 1;
	root[1][0] = 1;
	level[1] = 1;
	c[1] = 1;
	while (r>f) {
		x = q[++f];
		for (i = 0; i <a[x].size(); i++) {
			if (c[a[x][i]] == 0) {
				c[a[x][i]] = 1;
				q[++r] = a[x][i];
				root[a[x][i]][0] = x;
				level[a[x][i]] = level[x] + 1;
			}
		}
	}
	for (j = 1; j <= 20; j++) {
		for (i = 1; i <= n; i++) {
			root[i][j] = root[root[i][j - 1]][j - 1]; //2^0, 2^1, 2^2, 2^3번째 조상을 구한다.
		}
	}
	scanf("%d", &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		lx = level[x];
		ly = level[y];
		pox = x;
		poy = y;
		if (lx > ly) {
			pos = x;
			while (1) {
				j = 0;
				while (level[root[pos][j]] >= ly) {
					j++;
				}
				j--;
				pos = root[pos][j];
				if (level[pos] == ly) break;
			}
			lx = level[pos];
			pox = pos;
		}
		if (lx < ly) {
			pos = y;
			while (1) {
				j = 0;
				while (level[root[pos][j]] >= lx) {
					j++;
				}
				j--;
				pos = root[pos][j];
				if (level[pos] == lx) break;
			}
			ly = level[pos];
			poy = pos;
		}
		while (1) {
			if (pox == poy) break;
			j = 1;
			while (root[pox][j] != root[poy][j]) {
				j++;
			}
			j--;
			pox = root[pox][j];
			poy = root[poy][j];
		}
		printf("%d\n", pox);
	}
	scanf("%d", &n);
}