#include<stdio.h>
#include<math.h>
int x, x2, y, y2, r1, r2, n, t1, t2;
double dis;
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d %d %d %d", &x, &y, &r1, &x2, &y2, &r2);
		if (x == x2 && y == y2) {
			if (r1 == r2) printf("-1\n");
			else printf("0\n");
		}
		else {
			dis = sqrt((x - x2)*(x - x2) + (y - y2)*(y - y2));
			if (dis == r1 + r2 || dis==abs(r1-r2)) printf("1\n");
			else if (dis>=max(r1,r2) && dis < r1 + r2 || dis<=max(r1,r2) && dis>abs(r1-r2)) printf("2\n");
			else printf("0\n");
		}
	}
	scanf("%d %d", &n, &r1);
}