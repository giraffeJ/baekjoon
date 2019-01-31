#include<stdio.h>
int n, ax, ay, bx, by, cx, cy;
int ccw(int ax, int ay, int bx, int by, int cx, int cy) {
	int x = (ax*by + bx * cy + cx * ay) - (ay*bx + by * cx + cy * ax);
	if (x < 0) return -1;
	else if (x == 0) return 0;
	else return 1;
}
int main() {
	scanf("%d %d", &ax, &ay);
	scanf("%d %d", &bx, &by);
	scanf("%d %d", &cx, &cy);
	printf("%d\n", ccw(ax, ay, bx, by, cx, cy));
	scanf("%d", &n);
}