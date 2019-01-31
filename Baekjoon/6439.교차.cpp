#include<stdio.h>
int i, j, k, n, m, tcn;
int sx, sy, ex, ey, x1, x2, x3, x4, y1, y2, y3, y4;
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
	return 0;
}
int ccw(int ax, int ay, int bx, int by, int cx, int cy) {
	int x = (ax*by + bx * cy + cx * ay) - (ay*bx + by * cx + cy * ax);
	return x < 0 ? -1 : x>0;
}
int cross(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy) {
	int w1, w2, w3, w4;
	w1 = ccw(ax, ay, cx, cy, bx, by);
	w2 = ccw(ax, ay, dx, dy, bx, by);
	w3 = ccw(cx, cy, ax, ay, dx, dy);
	w4 = ccw(cx, cy, bx, by, dx, dy);
	if (w1*w2*w3*w4 != 0) {
		if (w1*w2 < 0 && w3*w4 < 0)
			return 1;
	}
	else {
		if (w1 == 0 && inside(ax, ay, cx, cy, bx, by) || w2 == 0 && inside(ax, ay, dx, dy, bx, by) || w3 == 0 && inside(cx, cy, ax, ay, dx, dy) || w4 == 0 && inside(cx, cy, bx, by, dx, dy)) return 1;
	}
	return 0;
}
int main() {
	scanf("%d", &tcn);
	for (i = 1; i <= tcn; i++) {
		scanf("%d %d %d %d %d %d %d %d", &sx, &sy, &ex, &ey, &x1, &y1, &x3, &y3);
		x2 = x1;
		y2 = y3;
		x4 = x3;
		y4 = y1;
		if (cross(sx, sy, ex, ey, x1, y1, x2, y2)) printf("T\n");
		else if (cross(sx, sy, ex, ey, x2, y2, x3, y3)) printf("T\n");
		else if (cross(sx, sy, ex, ey, x3, y3, x4, y4)) printf("T\n");
		else if (cross(sx, sy, ex, ey, x4, y4, x1, y1)) printf("T\n");
		else if (inside(x1, y1, sx, sy, x3, y3)) printf("T\n");
		else if (inside(x1, y1, ex, ey, x3, y3)) printf("T\n");
		else printf("F\n");
	}
	scanf("%d", &tcn);
}