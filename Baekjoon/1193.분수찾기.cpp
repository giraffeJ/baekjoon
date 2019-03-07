#include<stdio.h>
int i, j, n, m;
int main() {
	scanf("%d", &n);
	m = 0;
	for (i = 1; ; i++) {
		m += i;
		if (n <= m) {
			m -= i;
			n -= m;
			if (i % 2 == 1) printf("%d/%d\n", i + 1 - n, n);
			else if (i % 2 == 0) printf("%d/%d\n", n, i + 1 - n);
			break;
		}
	}
	scanf("%d", &n);
}