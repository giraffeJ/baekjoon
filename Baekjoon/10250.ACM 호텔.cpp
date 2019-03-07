#include<stdio.h>
int tcn, h, w, n, q, r;
int main() {
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		scanf("%d %d %d", &h, &w, &n);
		q = n / h;
		r = n % h;
		if (r == 0) { r = h; q--; }
		if (q < 9) printf("%d0%d\n", r, q + 1);
		else printf("%d%d\n", r, q + 1);
	}
}