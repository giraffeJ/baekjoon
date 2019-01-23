#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;
int i, j, k, n, m, start, x, y, z, r, f, temp, sw, c[50001], d[50001];
vector<int> a[50001][3];
struct pai {
	int x;
	int dst;
} pa, pb;
bool operator<(const pai& a, const pai& b) {
	return a.dst > b.dst;
}
priority_queue<pai> pq;
int main() {
	scanf("%d %d", &n, &m);
	scanf("%d", &start);
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		a[x][0].push_back(y);
		a[x][1].push_back(z);
	}
	for (i = 1; i <= n; i++) {
		d[i] = 2100000000;
	}
	pa.x = start;
	pa.dst = 0;
	pq.push(pa);
	sw = 0;
	for (i = 1; i <= n; i++) {
		if (pq.empty()) break;
		pb = pq.top();
		while (c[pb.x] != 0) {
			pq.pop();
			if (pq.empty()) {
				sw = 1;
				break;
			}
			pb = pq.top();
		}
		if (pq.empty()) break;
		pq.pop();
		d[pb.x] = pb.dst;
		c[pb.x] = 1;
		for (j = 0; j < a[pb.x][0].size(); j++) {
			pa.x = a[pb.x][0][j];
			if (c[pa.x] == 0 && d[pa.x]>pb.dst + a[pb.x][1][j]) {
				d[pa.x] = pa.dst = pb.dst + a[pb.x][1][j];
				pq.push(pa);
			}
		}
	}
	for (i = 1; i <= n; i++) {
		if (c[i] == 0) {
			printf("INF\n");
		}
		else {
			printf("%d\n", d[i]);
		}
	}
	scanf("%d %d", &n, &m);
} //우선순위 큐 + 다익스트라

  /*
  q.push(start);
  c[start] = 1;
  d[start] = 0;
  while (!q.empty()) {
  x=q.front();
  q.pop();
  for (i = 0; i < a[x][0].size(); i++) {
  y = a[x][0][i];
  if (c[y] == 0 || c[y] == 1 && d[y] > d[x] + a[x][1][i]) {
  c[y] = 1;
  d[y] = d[x] + a[x][1][i];
  q.push(y);
  }
  }
  }
  for (i = 1; i <= n; i++) {
  if (c[i] == 0) {
  printf("INF\n");
  }
  else {
  printf("%d\n", d[i]);
  }
  }
  scanf("%d %d", &n, &m);
  } //BFS로 구현. --> 시간초과*/

