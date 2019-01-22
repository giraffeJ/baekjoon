#include<stdio.h>
int i, j, k, n, m, a[2000001], x, y, z, ry, rz;
int find(int node) {
	if (a[node] == node) {
		return node;
	}
	else {
		a[node] = find(a[node]);
		return a[node];
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		a[i] = i;
	}
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		if (x == 0) {
			ry = find(y);
			rz = find(z);
			a[ry] = rz;
		}
		else {
			ry = find(y);
			rz = find(z);
			if (ry == rz) printf("YES\n");
			else printf("NO\n");
		}
	}
	scanf("%d %d", &n, &m);
}