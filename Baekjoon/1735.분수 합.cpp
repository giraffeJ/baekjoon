#include<math.h>
#include<stdio.h>
int a, b, c, d, e, f;
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int gcn(int a, int b) {
	int c;
	if (a < b) {
		c = a;
		a = b;
		b = c;
	}
	while (1) {
		if (a%b == 0) break;
		c = a % b;
		a = b;
		b = c;
	}
	return b;
}
int main() {
	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);
	e = gcn(a, b);
	a = a / e;
	b = b / e;
	f = gcn(c, d);
	c = c / f;
	d = d / f;
	e = a * d + b * c;
	f = b * d;
	a = gcn(e, f);
	e = e / a;
	f = f / a;
	printf("%d %d\n", e, f);
	scanf("%d %d", &a, &b);
}