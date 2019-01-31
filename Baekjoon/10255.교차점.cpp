#include<stdio.h>
int i, j, k, n, m, tc, tcn, x;
struct Point {
	int x;
	int y;
	Point operator -(const Point &a) const {
		return{ x - a.x, y - a.y };
	}
	bool operator <(const Point &a) const {
		return x == a.x ? y < a.y : x < a.x;
	}
	bool operator ==(const Point &a) const {
		return (x == a.x && y == a.y);
	}
};
Point a[6], s, e;
Point min(Point a, Point b) { return a < b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
Point max(Point a, Point b) { return a < b ? b : a; }
int max(int a, int b) { return a > b ? a : b; }
int ccw(Point a, Point b, Point c) {
	int x = (a.x*b.y + b.x*c.y + c.x*a.y) - (a.y*b.x + b.y*c.x + c.y*a.x);
	return x < 0 ? -1 : x>0;
}
int inside(Point a, Point b, Point c) {
	if (b.x >= min(a.x, c.x) && b.x <= max(a.x, c.x) && b.y >= min(a.y, c.y) && b.y <= max(a.y, c.y)) return 1;
	else return 0;
}
int howmuch(Point a, Point b, Point c, Point d) {
	int w1, w2, w3, w4;
	w1 = ccw(a, b, c);
	w2 = ccw(a, b, d);
	if (w1 == 0 && w2 == 0) { //한 직선 위에 있는 경우.
		if (max(a, b) < min(c, d) || max(c, d) < min(a, b)) return 0;
		if (max(a, b) == min(c, d) || max(c, d) == min(a, b)) return 1;
		return 15;
	}
	w3 = ccw(c, d, a);
	w4 = ccw(c, d, b);
	if (w1*w2*w3*w4 != 0 && w1*w2 < 0 && w3*w4 < 0) return 1;
	else if (w1 == 0 && inside(a, c, b) || w2 == 0 && inside(a, d, b) || w3 == 0 && inside(c, a, d) || w4 == 0 && inside(c, b, d)) return 1;
	return 0;
}
int main() {
	scanf("%d", &tcn);
	for (tc = 1; tc <= tcn; tc++) {
		scanf("%d %d %d %d", &a[1].x, &a[1].y, &a[3].x, &a[3].y);
		scanf("%d %d %d %d", &s.x, &s.y, &e.x, &e.y);
		a[2].x = a[5].x = a[1].x;
		a[2].y = a[3].y;
		a[4].x = a[3].x;
		a[4].y = a[5].y = a[1].y;
		x = 0;
		for (i = 1; i <= 4; i++)
			x += howmuch(a[i], a[i + 1], s, e);
		for (i = 1; i <= 4; i++)
			if (ccw(s, e, a[i]) == 0 && inside(s, a[i], e)) x--;
		if (x >= 10) printf("4\n");
		else printf("%d\n", x);
	}
	scanf("%d", &tcn);
}