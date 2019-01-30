#include<stdio.h>
int i, j, k, n, m, l, x, y, g, min, x1, x2, x3, x4, add, res; //행렬 곱 연산 수 찾기 문제처럼 구함 거기에 d[i][j]=d[i+1][j-1] + A 도 추가.
int d[303][303][30], c[303][303][30], a[1001]; //d[i][j][k]=i번째부터 j번째까지를 k라는 색으로 통일시키는 경우의 수
int fmin(int a, int b) {
	if (a < b) return a;
	else return b;
}
int main() {
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		for (j = 1; j <= m; j++)
			d[i][i][j] = 1;
		d[i][i][a[i]] = 0;
	}
	for (l = 2; l <= n; l++) {
		j = l - 1;
		for (i = 1; i <= n - l + 1; i++) {
			j++;
			for (k = 1; k <= m; k++)
				d[i][j][k] = 2100000000;
			if (a[i] == a[j]) { //양 끝이 같은 경우에만 안쪽값에서 참조한다.
				min = 2100000000;
				for (k = 1; k <= m; k++) {
					if (d[i + 1][j - 1][k] < min)
						min = d[i + 1][j - 1][k];
				}
				for (k = 1; k <= m; k++) {
					if (k == a[i])
						d[i][j][k] = d[i + 1][j - 1][k];
					else {
						if (d[i + 1][j - 1][a[i]] == min) //여기에서 min값을 가질 수 있는 색깔이 여러개라는 것을 간과해서 마지막에 안나왔음.
							d[i][j][k] = min + 1;
						else
							d[i][j][k] = min + 2;
					}
				}
			}
			for (k = 1; k <= m; k++) {
				for (g = i; g < j; g++)
					d[i][j][k] = fmin(d[i][j][k], d[i][g][k] + d[g + 1][j][k]); //이 부분이 중간을 나눠가면서 값을 찾는 부분.
			}
		}
	}
	res = 2100000000;
	for (k = 1; k <= m; k++) {
		if (d[1][n][k] < res) res = d[1][n][k];
	}
	printf("%d\n", res);
	scanf("%d", &n);
}