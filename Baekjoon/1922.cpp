#include<stdio.h>
#include<algorithm>
using namespace std;
int i, j, n, m, root[2001], c[2001], sum, cnt, px, py;
int find(int node) {
	if (node == root[node]) {
		return node;
	}
	else {
		root[node] = find(root[node]);
		return root[node];
	}
}
struct list {
	int x;
	int y;
	int val;
} arr[200001];
bool comp(list a, list b) {
	if (a.val < b.val) return true;
	else return false;
}
int main() {
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		root[i] = i;
	}
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &arr[i].x, &arr[i].y, &arr[i].val);
	}
	sort(arr + 1, arr + m + 1, comp);
	sum = arr[1].val;
	cnt = 1;
	c[arr[1].x] = c[arr[1].y] = 1;
	root[arr[1].x] = arr[1].y;
	for (i = 2; i <= m; i++) {
		px = find(arr[i].x);
		py = find(arr[i].y);
		if (px != py) {
			if (c[arr[i].x] == 0 && c[arr[i].y] == 1)
				root[arr[i].x] = py;
			else if (c[arr[i].x] == 1 && c[arr[i].y] == 0)
				root[arr[i].y] = px;
			else if (c[arr[i].x] == 0 && c[arr[i].y] == 0)
				root[arr[i].x] = arr[i].y;
			else
				root[px] = py;
			c[arr[i].x] = c[arr[i].y] = 1;
			sum += arr[i].val;
			cnt++;
		}
		if (cnt == n - 1) break;
	}
	printf("%d\n", sum);
	scanf("%d %d", &n, &m);
}