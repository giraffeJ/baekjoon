#include<stdio.h>
int tcn, i, j, n, m, val, a, b;
double x, y, z;
int main() {
	scanf("%d", &tcn);
	for (i = 1; i <= tcn; i++) {
		scanf("%d %d", &n, &m);
		a = m;
		b = n;
		x = 1;
		for (j = 1; j <= n; j++) {
			x = x * a / b;
			a--;
			b--;
		}
		printf("%.0lf\n", x);
	}
	scanf("%d", &tcn);
}
/* //파스칼의 삼각형으로 구함.
#include<stdio.h>
int i, j, n, d[40][30], x, y;
int main() {
scanf("%d", &n);
d[0][0] = 1;
for (i = 1; i <= 30; i++) {
d[i][0] = 1;
for (j = 1; j <= 30; j++) {
d[i][j] = d[i - 1][j] + d[i - 1][j - 1];
}
}
for (i = 1; i <= n; i++) {
scanf("%d %d", &x, &y);
printf("%d\n", d[y][x]);
}
scanf("%d %d", &x, &y);
}
*/