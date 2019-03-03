#include<stdio.h>
int tcn, tc, n, i, a[1001], cnt;
double avg, cnt_avg;
int main() {
	scanf("%d", &tcn);
	for (tc = 1; tc <= tcn; tc++) {
		scanf("%d", &n);
		avg = cnt = 0;
		for (i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			avg += a[i];
		}
		avg /= (double)n;
		for (i = 1; i <= n; i++) {
			if (a[i] > avg)
				cnt++;
		}
		cnt_avg = (double)cnt / (double)n;
		cnt_avg *= 100;
		printf("%.3lf%%\n", cnt_avg);
	}
}