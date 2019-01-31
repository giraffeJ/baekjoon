#include<stdio.h>
#include<vector>
using namespace std;
int i, j, k, n, m, r, f, x;
int i1x, i1y, i2x, i2y, j1x, j1y, j2x, j2y;
int w1, w2, w3, w4; // w1: i1->j1->i2 | w2: i1->j2->i2 | w3: j1->i1->j2 | w4: j1->i2->j2
int a[4000][6];
int c[4000], q[1000001], res[4000], rmax, cnt;
vector<int> adj[4000];
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int inside(int ax, int ay, int bx, int by, int cx, int cy) {
	if (bx >= min(ax, cx) && bx <= max(ax, cx) && by >= min(ay, cy) && by <= max(ay, cy)) return 1;
	else return 0;
}
int ccw(int ax, int ay, int bx, int by, int cx, int cy) {
	int x = (ax*by + bx * cy + cx * ay) - (ay*bx + by * cx + cy * ax);
	if (x < 0) return -1;
	else if (x == 0) return 0;
	else return 1;
}
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d %d %d %d", &a[i][1], &a[i][2], &a[i][3], &a[i][4]);
	}
	for (i = 1; i <= n; i++) {
		i1x = a[i][1];
		i2x = a[i][3];
		i1y = a[i][2];
		i2y = a[i][4];
		for (j = i + 1; j <= n; j++) {
			j1x = a[j][1];
			j2x = a[j][3];
			j1y = a[j][2];
			j2y = a[j][4];
			w1 = ccw(i1x, i1y, j1x, j1y, i2x, i2y);
			w2 = ccw(i1x, i1y, j2x, j2y, i2x, i2y);
			w3 = ccw(j1x, j1y, i1x, i1y, j2x, j2y);
			w4 = ccw(j1x, j1y, i2x, i2y, j2x, j2y);
			if (w1*w2*w3*w4 != 0) {
				if (w1*w2 < 0 && w3*w4 < 0) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
			else {
				if (w1 == 0 && inside(i1x, i1y, j1x, j1y, i2x, i2y) || w2 == 0 && inside(i1x, i1y, j2x, j2y, i2x, i2y) || w3 == 0 && inside(j1x, j1y, i1x, i1y, j2x, j2y) || w4 == 0 && inside(j1x, j1y, i2x, i2y, j2x, j2y)) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
	}
	cnt = 0;
	for (i = 1; i <= n; i++) {
		if (c[i] == 0) {
			cnt++;
			r = f = 0;
			q[++r] = i;
			c[i] = cnt;
			while (r > f) {
				x = q[++f];
				for (j = 0; j < adj[x].size(); j++) {
					if (c[adj[x][j]] == 0) {
						q[++r] = adj[x][j];
						c[adj[x][j]] = cnt;
					}
				}
			}
		}
	}
	for (i = 1; i <= n; i++) {
		res[c[i]]++;
	}
	rmax = -99;
	for (i = 1; i <= cnt; i++) {
		if (res[i] > rmax) rmax = res[i];
	}
	printf("%d\n%d\n", cnt, rmax);
	scanf("%d", &n);
}