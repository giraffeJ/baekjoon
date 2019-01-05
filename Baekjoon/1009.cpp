#include<stdio.h>
int tcn, i, j, a, b, c;
int main() {
	scanf("%d", &tcn);
	for (i = 1; i <= tcn; i++) {
		scanf("%d %d", &a, &b);
		a = a % 10;
		c = a;
		for (j = 2; j <= b; j++) {
			c = (c * a) % 10;
		}
		if (c == 0) c = 10;
		printf("%d\n", c);
	}
	scanf("%d", &tcn);
}