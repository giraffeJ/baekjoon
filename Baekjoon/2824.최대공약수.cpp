#include<stdio.h>
long long int i, j, k, n, m, x, y, z, res, sw;
long long int a[2001], b[2001];
char re[101];
long long int gcd(long long int a, long long int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}
int main() {
	scanf("%lld", &n);
	for (i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	scanf("%lld", &m);
	for (i = 1; i <= m; i++) {
		scanf("%lld", &b[i]);
	}
	res = 1;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			z = gcd(a[i], b[j]);
			a[i] /= z;
			b[j] /= z;
			res = res * z;
			if (res >= 1000000000) {
				sw = 1;
				res = res % 1000000000;
			}
		}
	}
	if (sw == 1) {
		for (i = 9; i >= 1; i--) {
			re[i] = (res % 10) + 48;
			res /= 10;
		}
		for (i = 1; i <= 9; i++) {
			printf("%c", re[i]);
		}
		printf("\n");
	}
	else {
		printf("%lld\n", res);
	}
	scanf("%lld", &n);
}
/*
i = j = 1;
x = a[1];
y = b[1];
res = 1;
sw = 0;
while (1) {
z = gcd(x, y);
x /= z;
y /= z;
if (z >= 1000000000) {
sw = 1;
z %= 1000000000;
}
res = res*z;
if (res >= 1000000000) {
sw = 1;
res %= 1000000000;
}
if (i == n && j == m) break;
else if (i == n)
y *= b[++j];
else if (j == m)
x *= a[++i];
else {
if (x < y)
x *= a[++i];
else
y *= b[++j];
} // 이 방법은 x, y가 곱해지면서 overflow가 발생할 수 있음.
}*/