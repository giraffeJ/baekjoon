#include<stdio.h>
typedef long long int lli;
lli a[1000010];
lli res, n, b, c;
int main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	scanf("%lld %lld", &b, &c);
	res = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= b) res++;
		else {
			a[i] = a[i] - b + c - 1;
			res += (a[i] / c);
			res++;
		}
	}
	printf("%lld\n", res);
}