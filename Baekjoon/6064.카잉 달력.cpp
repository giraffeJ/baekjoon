#include<stdio.h>
int tcn, n, m, x, y, max, q;
int main() {
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		scanf("%d %d %d %d", &m, &n, &x, &y);
		max = n * m;
		while (1) {
			if (x < y) {
				q = (y - x) / m;
				x += m * q;
				if (x < y) x += m;
			}
			else if(y < x){
				q = (x - y) / n;
				y += n * q;
				if (y < x) y += n;
			}
			if (x == y) {
				printf("%d\n", y);
				break;
			}
			if (x > max || y > max) {
				printf("-1\n");
				break;
			}
		}
	}
}