#include<stdio.h>
#include<algorithm>
typedef long long int lli;
using namespace std;
lli i, j, k, n, m, l, stack[100030], top = -1, trash;
struct Point {
	lli x;
	lli y;
	bool operator <(const Point &a) const {
		return y == a.y ? x < a.x : y < a.y;
	}
	Point operator -(const Point &a) const {
		return{ x - a.x, y - a.y };
	}
	bool operator ==(const Point &a) const {
		return (x == a.x && y == a.y);
	}
} a[100030], start;
lli ccw(Point a, Point b, Point c) {
	lli x = (a.x*b.y + b.x*c.y + c.x*a.y) - (a.y*b.x + b.y*c.x + c.y*a.x);
	return x < 0 ? -1 : x>0;
}
lli dst(Point a, Point b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
bool compare(const Point &a, const Point &b) {
	if (ccw(start, a, b) == 0) {
		return dst(start, a) < dst(start, b);
	}
	return ccw(start, a, b) > 0;
}
void push(lli k) {
	stack[++top] = k;
}
lli pop() {
	return stack[top--];
}
int main() {
	scanf("%lld", &n);
	start.y = 50000;
	for (i = 1; i <= n; i++) {
		scanf("%lld %lld", &a[i].x, &a[i].y);
		if (a[i] < start) {
			start = a[i];
			l = i;
		}
	}
	a[l] = a[1];
	a[1] = start;
	a[n + 1] = start;
	sort(a + 2, a + n + 1, compare);
	push(1);
	push(2);
	for (i = 3; i <= n + 1; i++) {
		while (top >= 1 && ccw(a[stack[top - 1]], a[stack[top]], a[i]) <= 0) {
			trash = pop();
		}
		push(i);
	}
	printf("%lld\n", top);
	scanf("%lld", &n);
}