#include<stdio.h>
long long int i, j, k, n, m;
long long sum, cc, ar;
long long int x, y, x1, y1, x2, y2;
long long int a[10030][4];
int ccw(long long int ax, long long int ay, long long int bx, long long int by, long long int cx, long long int cy) {
	long long int x = (ax*by + bx * cy + cx * ay) - (ay*bx + by * cx + cy * ax);
	if (x < 0) return -1;
	else if (x == 0) return 0;
	else return 1;
}
long long int abs(long long int a) {
	if (a < 0) return a * (-1);
	else return a;
}
long long int area(long long int a, long long int b, long long int c, long long int d, long long int e, long long int f) {
	long long int x = (a*d + c * f + e * b) - (c*b + e * d + a * f);
	return abs(x);
}
int main() {
	scanf("%lld", &n);
	for (i = 1; i <= n; i++) {
		scanf("%lld %lld", &a[i][1], &a[i][2]);
	}
	//x = a[1][1];
	//y = a[1][2];
	x = y = 0;
	a[n + 1][1] = a[1][1];
	a[n + 1][2] = a[1][2];
	for (i = 1; i <= n; i++) {
		x1 = a[i][1];
		y1 = a[i][2];
		x2 = a[i + 1][1];
		y2 = a[i + 1][2];
		cc = ccw(x, y, x1, y1, x2, y2);
		ar = area(x, y, x1, y1, x2, y2);
		sum = sum + (cc * ar);
	}
	if (sum < 0) sum *= -1;
	sum *= 5;
	k = sum % 10;
	sum /= 10;
	printf("%lld.%lld\n", sum, k);
	scanf("%lld", &n);
}