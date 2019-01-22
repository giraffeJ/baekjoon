#include<stdio.h>
int ind[5000001], i, j, n, m, k, x, y, z;
void update(int pos, int val) {
	while (1) {
		ind[pos] += val;
		pos /= 2;
		if (pos == 0) break;
	}
}
int find(int pos, int val) {
	if (pos >= m + 1) {
		update(pos, -1);
		return pos - m;
	}
	else {
		if (ind[pos * 2] >= val) {
			return find(pos * 2, val);
		}
		else {
			return find(pos * 2 + 1, val - ind[pos * 2]);
		}
	}
}
int main() {
	scanf("%d", &n);
	m = 1048575;
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &x, &y);
		if (x == 2) {
			scanf("%d", &z);
			update(y + m, z);
		}
		else {
			k = find(1, y);
			printf("%d\n", k);
		}
	}
	scanf("%d", &n);
}