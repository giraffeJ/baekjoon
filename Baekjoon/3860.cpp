#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int i, j, k, n, m, x, y, z, nx, ny, siz;
int a[40][40], d[40][40];
int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
struct list {
	int fx;
	int fy;
	int tx;
	int ty;
	int val;
} temp;
vector<list> adj;
int main() {
	while (1) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				a[i][j] = 0;
			}
		}
		scanf("%d", &k);
		for (i = 1; i <= k; i++) {
			scanf("%d %d", &x, &y);
			a[x + 1][y + 1] = 1;
		}
		scanf("%d", &k);
		for (i = 1; i <= k; i++) {
			scanf("%d %d %d %d %d", &temp.fx, &temp.fy, &temp.tx, &temp.ty, &temp.val);
			temp.fx++;
			temp.fy++;
			temp.tx++;
			temp.ty++;
			a[temp.fx][temp.fy] = 2;
			adj.push_back(temp);
		}
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				if (a[i][j] == 0 && (i!=n || j!=m)) {
					for (k = 1; k <= 4; k++) {
						nx = i + dx[k];
						ny = j + dy[k];
						if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] != 1)
							adj.push_back({ i, j, nx, ny, 1 });
					}
				}
				d[i][j] = 2100000000;
			}
		}
		d[1][1] = 0;
		siz = adj.size();
		for (i = 1; i < n*m; i++) {
			for (j = 0; j < siz; j++) {
				x = adj[j].fx;
				y = adj[j].fy;
				nx = adj[j].tx;
				ny = adj[j].ty;
				if (d[x][y] != 2100000000 && d[nx][ny]>d[x][y] + adj[j].val) {
					d[nx][ny] = d[x][y] + adj[j].val;
				}
				/*if (d[adj[j].fx][adj[j].fy] != 2100000000 && d[adj[j].tx][adj[j].ty]>d[adj[j].fx][adj[j].fy] + adj[j].val) {
					d[adj[j].tx][adj[j].ty] = d[adj[j].fx][adj[j].fy] + adj[j].val;
				}*/
			}
		}
		for (j = 0; j < adj.size(); j++) {
			if (d[adj[j].fx][adj[j].fy] != 2100000000) {
				if (d[adj[j].tx][adj[j].ty] > d[adj[j].fx][adj[j].fy] + adj[j].val) {
					break;
				}
			}
		}
		if (j < adj.size()) {
			printf("AAAAAAAA : Never\n");
		}
		else if (d[n][m] == 2100000000) {
			printf("AAAAAAAA : Impossible\n");
		}
		else printf("AAAAAAAA : %d\n", d[n][m]);
		adj.clear();
	}
}


/*
#include<stdio.h> //BFS로 함. 웜홀처리 개쓰레기.. 조건이 너무 많다. 그냥 벨만 포드로 하는게 100배는 단순하다.. 결국엔 시간초과 나서 포기^^ 씌바꺼^^
int i, j, k, n, m, x, y, z, v, w, res;
int a[40][40], h[40][40][6], q[3][1000001];
int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int explore(int sx, int sy) {
	int d[40][40], c[40][40], hc[40][40], r, f, nx, ny, tx, ty, ad, sw = 0, sw2, sw3, te1, te2;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			c[i][j] = 0;
			d[i][j] = -1;
		}
	}
	r = f = 0;
	q[0][++r] = sx;
	q[1][r] = sy;
	c[sx][sy] = 1;
	d[sx][sy] = 0;
	while (r > f) {
		x = q[0][++f];
		y = q[1][f];
		if (x != n || y != m) {
			if (d[1][1] < -10) {
				sw = 1;
				break;
			}
			for (i = 1; i <= 4; i++) {
				nx = x + dx[i];
				ny = y + dy[i];
				if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
					if (a[nx][ny] != 1) {
						ad = 1;
						sw2 = 0;
						if (a[nx][ny] == 2) {
							for (te1 = 1; te1 <= n; te1++) {
								for (te2 = 1; te2 <= m; te2++) {
									hc[te1][te2] = 0;
								}
							}
							hc[nx][ny] = 1;
							sw3 = 0;
							while (1) {
								tx = nx;
								ty = ny;
								nx = h[tx][ty][1];
								ny = h[tx][ty][2];
								ad += h[tx][ty][3];
								if (hc[nx][ny] != 0) {
									if (hc[nx][ny] > hc[tx][ty] + h[tx][ty][3]) sw = 1;
									sw2 = 1;
									break;
								}
								hc[nx][ny] = hc[tx][ty] + h[tx][ty][3];
								if (a[nx][ny] != 2) break;
							}
							if (sw == 1) break;
						}
						if (sw2 == 0) {
							if (c[nx][ny] == 0 || c[nx][ny] == 1 && d[nx][ny] > d[x][y] + ad) {
								q[0][++r] = nx;
								q[1][r] = ny;
								c[nx][ny] = 1;
								d[nx][ny] = d[x][y] + ad;
							}
						}
					}
				}
			}
		}
		if (sw == 1) break;
	}
	if (sw == 1) return -2100000000;
	if (c[n][m] == 0) return 2100000000;
	else return d[n][m];
}
int main() {
	while (1) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				a[i][j] = 0;
				h[i][j][0] = h[i][j][1] = h[i][j][2] = h[i][j][3] = 0;
			}
		}
		scanf("%d", &k);
		for (i = 1; i <= k; i++) {
			scanf("%d %d", &x, &y);
			a[x + 1][y + 1] = 1;
		}
		scanf("%d", &k);
		for (i = 1; i <= k; i++) {
			scanf("%d %d %d %d %d", &x, &y, &z, &w, &v);
			h[x + 1][y + 1][1] = z + 1;
			h[x + 1][y + 1][2] = w + 1;
			h[x + 1][y + 1][3] = v;
			a[x + 1][y + 1] = 2;
		}
		res = explore(1, 1);
		if (res == -2100000000) printf("AAAAAAAAAAAA : Never\n");
		else if (res == 2100000000) printf("AAAAAAAAAAAA : Impossible\n");
		else printf("AAAAAAAAAAAA : %d\n", res);
	}

}*/ 