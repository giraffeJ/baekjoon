#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long int lli;
struct Point {
	lli x;
	lli y;
	bool operator < (const Point &a) const {
		return y == a.y ? x < a.x : y < a.y;
	}
	bool operator <= (const Point &a) const {
		return x == a.x ? y <= a.x : x <= a.x;
	}
	Point operator - (const Point &a) const {
		return{ x - a.x, y - a.y };
	}
	bool operator == (const Point &a) const {
		return (x == a.x && y == a.y);
	}
};
Point bl[110], wh[110], pmin;
Point chb[110], chw[110];
lli chbn, chwn;
lli i, j, k, n, m, tcn, tc, l, stack[110], top = -1, trash, x, cnt, linecheck, sw;
void push(lli k) {
	stack[++top] = k;
}
lli pop() {
	return stack[top--];
}
lli ccw(Point a, Point b, Point c) {
	lli x = (a.x*b.y + b.x*c.y + c.x*a.y) - (a.y*b.x + b.y*c.x + c.y*a.x);
	return x < 0 ? -1 : x>0;
}
lli dst(Point a, Point b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
bool compare(Point a, Point b) {
	if (ccw(pmin, a, b) == 0) {
		return dst(pmin, a) < dst(pmin, b);
	}
	return ccw(pmin, a, b) > 0;
}
int inside(Point a, Point b, Point c) {
	if (a <= b && b <= c || c <= b && b <= a) return 1;
	else return 0;
}
int cross(Point a, Point b, Point c, Point d) {
	lli w1, w2, w3, w4;
	w1 = ccw(a, b, c);
	w2 = ccw(a, b, d);
	w3 = ccw(c, d, a);
	w4 = ccw(c, d, b);
	if (w1*w2*w3*w4 != 0) {
		if (w1*w2 < 0 && w3*w4 < 0) return 1;
	}
	if (w1 == 0 && inside(a, c, b) || w2 == 0 && inside(a, d, b) || w3 == 0 && inside(c, a, d) || w4 == 0 && inside(c, b, d)) return 1;
	return 0;
}
int main() {
	scanf("%lld", &tcn);
	for (tc = 1; tc <= tcn; tc++) {
		scanf("%lld %lld", &n, &m);
		sw = 1;
		//검은 점 convex hull 구하기.
		pmin.y = pmin.x = 30000;
		for (i = 1; i <= n; i++) {
			scanf("%lld %lld", &bl[i].x, &bl[i].y);
			if (bl[i] < pmin) {
				pmin = bl[i];
				l = i;
			}
		}
		bl[l] = bl[1];
		bl[1] = pmin;
		sort(bl + 2, bl + n + 1, compare);
		push(1);
		if (n >= 2) push(2);
		for (i = 3; i <= n; i++) {
			while (top > 1 && ccw(bl[stack[top - 1]], bl[stack[top]], bl[i]) <= 0)
				trash = pop();
			push(i);
		}
		chbn = 0;
		chb[++chbn] = bl[1];
		while (top != -1) {
			x = pop();
			chb[++chbn] = bl[x];
		}
		//흰 점 convex hull 구하기
		pmin.y = pmin.x = 30000;
		for (i = 1; i <= m; i++) {
			scanf("%lld %lld", &wh[i].x, &wh[i].y);
			if (wh[i] < pmin) {
				pmin = wh[i];
				l = i;
			}
		}
		wh[l] = wh[1];
		wh[1] = pmin;
		sort(wh + 2, wh + m + 1, compare);
		push(1);
		if (m >= 2) push(2);
		for (i = 3; i <= m; i++) {
			while (top > 1 && ccw(wh[stack[top - 1]], wh[stack[top]], wh[i]) <= 0)
				trash = pop();
			push(i);
		}
		chwn = 0;
		chw[++chwn] = wh[1];
		while (top != -1) {
			x = pop();
			chw[++chwn] = wh[x];
		}
		//겹치는지 여부 조사.
		Point Lp = { 20000, 0 };
		linecheck = 0;
		for (i = 1; i < chbn; i++) {
			cnt = 0;
			Lp.y = chb[i].y + 1;
			for (j = 1; j < chwn; j++) {
				cnt += cross(chb[i], Lp, chw[j], chw[j + 1]); //즈어 멀리 있는 점이랑 연결한 선분이랑 교차점 개수 누적.
				linecheck = cross(chb[i], chb[i + 1], chw[j], chw[j + 1]); //선분 간의 교차 여부 조사.
				if (linecheck == 1) break;
			}
			if (linecheck == 1) break;
			if (cnt % 2 == 1) break;
		}
		if (i != chbn) {
			sw = 0;
		}
		for (i = 1; i < chwn; i++) {
			cnt = 0;
			Lp.y = chw[i].y + 1;
			for (j = 1; j < chbn; j++) {
				cnt += cross(chw[i], Lp, chb[j], chb[j + 1]); //즈어 멀리 있는 점이랑 연결한 선분이랑 교차점 개수 누적.
			}
			if (cnt % 2 == 1) break;
		}
		if (i != chwn) {
			sw = 0;
		}
		if (sw == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	scanf("%d", &tcn);
}