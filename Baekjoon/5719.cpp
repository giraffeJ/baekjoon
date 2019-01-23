#include<stdio.h>
#include<vector> //거의 최단 경로 : 두 번째 최단 경로 구하기
#include<queue> //최단 경로 구해서 벡터로 부모들 저장해놓고 역추적하면서 삭제한 다음 다시 한 번 더 최단경로 구함. BFS로 함.
using namespace std;
int i, j, k, n, m, a[1001][1001], d[1001], c[1001], st, ed, x, y, z;
vector<int> p[1001];
queue<int> q;
void findshortest(int st, int ed) {
	int x, i;
	q.push(st);
	d[st] = 0;
	c[st] = 1;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (i = 0; i < n; i++) {
			if (a[x][i] != 0) {
				if (c[i] == 0 || c[i] == 1 && d[i] > d[x] + a[x][i]) {
					c[i] = 1;
					d[i] = d[x] + a[x][i];
					p[i].clear();
					p[i].push_back(x);
					q.push(i);
				}
				if (c[i] == 1 && d[i] == d[x] + a[x][i]) {
					p[i].push_back(x);
				}
			}
		}
	}
}
void deleteedge(int pos) {
	int i;
	for (i = 0; i < p[pos].size(); i++) {
		a[p[pos][i]][pos] = 0;
		deleteedge(p[pos][i]);
	}
}
int main() {
	while (1) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;
		scanf("%d %d", &st, &ed);
		for (i = 0; i < n; i++) {
			d[i] = -1;
			c[i] = 0;
			p[i].clear();
			for (j = 0; j < n; j++)
				a[i][j] = 0;
		}
		for (i = 1; i <= m; i++) {
			scanf("%d %d %d", &x, &y, &z);
			a[x][y] = z;
		}
		findshortest(st, ed);
		deleteedge(ed);
		for (i = 0; i < n; i++) {
			d[i] = -1;
			c[i] = 0;
			p[i].clear();
		}
		findshortest(st, ed);
		printf("%d\n", d[ed]);
	}
	scanf("%d", &n);

}