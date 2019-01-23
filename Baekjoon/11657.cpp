#include<stdio.h>
#include<vector> //벨만 포드 알고리즘으로 푸는 문제.
using namespace std;
int i, j, k, n, m, x, y, z, d[1001];
struct list {
	int x;
	int y;
	int dst;
}a[10001];
int main() {
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		a[i].x = x;
		a[i].y = y;
		a[i].dst = z;
	}
	for (i = 1; i <= n; i++) {
		d[i] = 2100000000;
	}
	d[1] = 0;
	for (i = 1; i <n; i++) {
		for (j = 1; j <= m; j++) {
			if (d[a[j].x] != 2100000000 && d[a[j].y] > d[a[j].x] + a[j].dst) {
				d[a[j].y] = d[a[j].x] + a[j].dst;
			}
		}
	}
	for (j = 1; j <= m; j++) {
		if (d[a[j].x] != 2100000000 && d[a[j].y] > d[a[j].x] + a[j].dst) {
			break;
		}
	}
	if (j == m + 1) {
		for (i = 2; i <= n; i++) {
			if (d[i] == 2100000000) printf("-1\n");
			else printf("%d\n", d[i]);
		}
	}
	else
		printf("-1\n");
	scanf("%d", &n);
}