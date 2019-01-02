#include<stdio.h>
int k, n, cnt, i;
int main() {
	scanf("%d", &n);
	k = 64;
	cnt = 0;
	for (i = 1; i <= 7; i++) {
		if (n >= k) {
			n -= k;
			cnt++;
		}
		k /= 2;
		if (n == 0) break;
	}
	printf("%d\n", cnt);
	//scanf("%d", &n);
}