#include<stdio.h>
#include<math.h>
int x, x2, y, y2, r1, r2, n, t1, t2;
double dis;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d %d %d %d", &x, &y, &r1, &x2, &y2, &r2);
		if (x == x2 && y == y2) {
			if (r1 == r2) {
				printf("-1\n");
			}
			else {
				printf("0\n");
			}
		}
		else {
			t1 = x - x2;
			t1 = t1 * t1;
			t2 = y - y2;
			t2 = t2 * t2;
			dis = sqrt(t1+t2);
			if (dis > r1 + r2 || dis<r1 || dis<r2) {
				printf("0\n");
			}
			else if (dis == r1 + r2) {
				printf("1\n");
			}
			else if (dis < r1 + r2) {
				printf("2\n");
			}
		}
	}
	scanf("%d %d", &n, &r1);
}