#include<stdio.h>
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int i, n, dmin[5][5], dmax[5][5], x, y, z;
int main() {
	scanf("%d", &n);
	scanf("%d %d %d", &x, &y, &z);
	dmin[1][1] = dmax[1][1] = x;
	dmin[1][2] = dmax[1][2] = y;
	dmin[1][3] = dmax[1][3] = z;
	for (i = 1; i < n; i++) {
		scanf("%d %d %d", &x, &y, &z);
		dmin[2][1] = min(dmin[1][1], dmin[1][2]) + x;
		dmin[2][2] = min(dmin[1][1], min(dmin[1][2], dmin[1][3])) + y;
		dmin[2][3] = min(dmin[1][2], dmin[1][3]) + z;
		dmax[2][1] = max(dmax[1][1], dmax[1][2]) + x;
		dmax[2][2] = max(dmax[1][1], max(dmax[1][2], dmax[1][3])) + y;
		dmax[2][3] = max(dmax[1][2], dmax[1][3]) + z;		
		dmin[1][1] = dmin[2][1];
		dmin[1][2] = dmin[2][2];
		dmin[1][3] = dmin[2][3];
		dmax[1][1] = dmax[2][1];
		dmax[1][2] = dmax[2][2];
		dmax[1][3] = dmax[2][3];
	}
	printf("%d %d", max(dmax[1][1], max(dmax[1][2], dmax[1][3])), min(dmin[1][1], min(dmin[1][2], dmin[1][3])));
	scanf("%d", &n);
}