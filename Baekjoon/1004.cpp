#include<stdio.h>
#include<math.h>
int tcn, i, j, px, py, rx, ry, m, cnt, x, y, r, check;
double dis1, dis2;
int main() {
	scanf("%d", &tcn);
	for (i = 1; i <= tcn; i++) {
		scanf("%d %d %d %d", &px, &py, &rx, &ry);
		scanf("%d", &m);
		cnt = 0;
		for (j = 1; j <= m; j++) {
			scanf("%d %d %d", &x, &y, &r);
			dis1 = sqrt((x - px)*(x - px) + (y - py)*(y - py));
			dis2 = sqrt((x - rx)*(x - rx) + (y - ry)*(y - ry));
			check = 0;
			if (dis1 < r) check = !check;
			if (dis2 < r) check = !check;
			if (check == 1) cnt++;
		}
		printf("%d\n", cnt);
	}
	scanf("%d %d", &i, &j);
}