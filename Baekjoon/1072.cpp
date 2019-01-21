#include<stdio.h>
long long int xx, yy, s, e, m;
double x, y, n, k, t;
double a, b, c, d;
int main() {
	scanf("%lld %lld", &xx, &yy);
	x = xx;
	y = yy;
	n = y * 100 / x;
	if (n >= 99) {
		printf("-1\n");
	}
	else {
		s = 1;
		e = xx;
		while (1) {
			m = (s + e) / 2;
			k = m;
			t = (y + k) / (x + k) * 100;
			if ((int)t == (int)n)
				s = m + 1;
			else
				e = m;
			if (s == e) break;
		}
		k = s;
		t = (y + k) / (x + k) * 100;
		if ((int)t == (int)n) printf("-1\n");
		else printf("%lld\n", s);
	}
	scanf("%lfd %lfd", &x, &y);
}