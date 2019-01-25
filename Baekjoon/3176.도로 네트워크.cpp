#include<stdio.h>
#include<vector>
using namespace std;
int i, j, k, n, m, x, y, z, root[100030][20], amin[100030][20], amax[100030][20], c[100030], level[100030];
int fmin(int a, int b) {
	if (a < b) return a;
	else return b;
}
int fmax(int a, int b) {
	if (a > b) return a;
	else return b;
}
struct list {
	int dst;
	int val;
};
vector<list> a[100030];
void maketree(int pos) {
	int i;
	for (i = 0; i < a[pos].size(); i++) {
		if (c[a[pos][i].dst] == 0) {
			root[a[pos][i].dst][0] = pos;
			level[a[pos][i].dst] = level[pos] + 1;
			amin[a[pos][i].dst][0] = a[pos][i].val;
			amax[a[pos][i].dst][0] = a[pos][i].val;
			c[a[pos][i].dst] = 1;
			maketree(a[pos][i].dst);
		}
	}
}
void rootset() {
	int i, k;
	for (k = 1; k <= 19; k++) {
		for (i = 1; i <= n; i++) {
			root[i][k] = root[root[i][k - 1]][k - 1];
			amin[i][k] = fmin(amin[root[i][k - 1]][k - 1], amin[i][k - 1]);
			amax[i][k] = fmax(amax[root[i][k - 1]][k - 1], amax[i][k - 1]);
		}
	}
}
void findminmax(int x, int y) {
	int k, rmin = 2100000000, rmax = -2100000000;
	if (level[x] != level[y]) {
		if (level[x] < level[y]) {
			for (k = 19; k >= 0; k--) {
				if (level[root[y][k]] > level[x]) {
					rmin = fmin(rmin, amin[y][k]);
					rmax = fmax(rmax, amax[y][k]);
					y = root[y][k];
				}
			}
			rmin = fmin(rmin, amin[y][0]);
			rmax = fmax(rmax, amax[y][0]);
			y = root[y][0];

		}
		else if (level[x] > level[y]) {
			for (k = 19; k >= 0; k--) {
				if (level[root[x][k]] > level[y]) {
					rmin = fmin(rmin, amin[x][k]);
					rmax = fmax(rmax, amax[x][k]);
					x = root[x][k];
				}
			}
			rmin = fmin(rmin, amin[x][0]);
			rmax = fmax(rmax, amax[x][0]);
			x = root[x][0];
		}
	}
	if (x == y) {
		printf("%d %d\n", rmin, rmax);
	}
	else {
		for (k = 19; k >= 0; k--) {
			if (root[x][k] != root[y][k]) {
				rmin = fmin(rmin, fmin(amin[y][k], amin[x][k]));
				rmax = fmax(rmax, fmax(amax[y][k], amax[x][k]));
				y = root[y][k];
				x = root[x][k];
			}
		}
		rmin = fmin(rmin, fmin(amin[y][0], amin[x][0]));
		rmax = fmax(rmax, fmax(amax[y][0], amax[x][0]));
		printf("%d %d\n", rmin, rmax);
	}
}
int main() {
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		scanf("%d %d %d", &x, &y, &z);
		a[x].push_back({ y, z });
		a[y].push_back({ x, z });
	}
	root[1][0] = 1;
	c[1] = 1;
	level[1] = 0;
	amin[1][0] = amax[1][0] = 0;
	maketree(1);
	rootset();
	scanf("%d", &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		findminmax(x, y);
	}
	scanf("%d", &n);
}



/* //트리로 구성하고 모든 노드 간 경로가 루트를 거친다고 착각하여 만든 풀이.. asshole.
#include<algorithm>
#include<vector>
using namespace std;
int i, j, k, n, m, root[150001], cnt[150001], r, f, q[1500001], mx, rt, x, y, z;
int min(int a, int b) {
if (a < b) return a;
else return b;
}
int max(int a, int b) {
if (a > b) return a;
else return b;
}
vector<int> a[150001][2];
struct list {
int min=2100000000;
int max=-2100000000;
}dis[150001];
int main() {
scanf("%d", &n);
for (i = 1; i <n; i++) {
scanf("%d %d %d", &x, &y, &z);
a[x][0].push_back(y);
a[y][0].push_back(x);
a[x][1].push_back(z);
a[y][1].push_back(z);
cnt[x]++;
cnt[y]++;
}
mx = -2100000000;
for (i = 1; i <= n; i++) {
if (cnt[i] > mx) {
mx = cnt[i];
rt = i;
}
}
root[rt] = rt;
r = f = 0;
q[++r] = rt;
while (r > f) {
x = q[++f];
for (i = 0; i < a[x][0].size(); i++) {
if (root[a[x][0][i]] == 0) {
root[a[x][0][i]] = x;
dis[a[x][0][i]].min = min(dis[x].min, a[x][1][i]);
dis[a[x][0][i]].max = max(dis[x].max, a[x][1][i]);
q[++r] = a[x][0][i];
}
}
}
scanf("%d", &m);
for (i = 1; i <= m; i++) {
scanf("%d %d", &x, &y);
printf("%d %d\n", min(dis[x].min, dis[y].min), max(dis[x].max, dis[y].max));
}
scanf("%d", &n);
}*/