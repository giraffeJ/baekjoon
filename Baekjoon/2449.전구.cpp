#include<stdio.h>
int i, j, k, n, m, l, x, y, g, min, x1, x2, x3, x4, add, res; //��� �� ���� �� ã�� ����ó�� ���� �ű⿡ d[i][j]=d[i+1][j-1] + A �� �߰�.
int d[303][303][30], c[303][303][30], a[1001]; //d[i][j][k]=i��°���� j��°������ k��� ������ ���Ͻ�Ű�� ����� ��
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
			if (a[i] == a[j]) { //�� ���� ���� ��쿡�� ���ʰ����� �����Ѵ�.
				min = 2100000000;
				for (k = 1; k <= m; k++) {
					if (d[i + 1][j - 1][k] < min)
						min = d[i + 1][j - 1][k];
				}
				for (k = 1; k <= m; k++) {
					if (k == a[i])
						d[i][j][k] = d[i + 1][j - 1][k];
					else {
						if (d[i + 1][j - 1][a[i]] == min) //���⿡�� min���� ���� �� �ִ� ������ ��������� ���� �����ؼ� �������� �ȳ�����.
							d[i][j][k] = min + 1;
						else
							d[i][j][k] = min + 2;
					}
				}
			}
			for (k = 1; k <= m; k++) {
				for (g = i; g < j; g++)
					d[i][j][k] = fmin(d[i][j][k], d[i][g][k] + d[g + 1][j][k]); //�� �κ��� �߰��� �������鼭 ���� ã�� �κ�.
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