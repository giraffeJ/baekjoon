#include<stdio.h>
#include<math.h>
int tcn, i, j, n, a[30][3], choice[30];
long long int sum, sumx, sumy;
double min(double a, double b) {
	if (a < b) return a;
	else return b;
}
double calc() {
	int i, key=1;
	sumx = sumy = 0;
	double total;
	for (i = 1; i <= n; i++) {
		if (choice[i] == 0) key = 1;
		else if (choice[i] == 1) key = -1;
		sumx = sumx + a[i][1] * key;
		sumy = sumy + a[i][2] * key;
	}
	sum = sumx * sumx + sumy * sumy;
	total = sqrt(sum);
	return total;
}
double findsol(int pos, int cnt) {
	double val1, val2;
	if (pos == n + 1) 
		return calc();
	if (cnt == n / 2) 
		return findsol(pos + 1, cnt);
	else {
		if (n - pos + 1 == (n / 2) - cnt) {
			choice[pos] = 1;
			val1 = findsol(pos + 1, cnt + 1);
			choice[pos] = 0;
			return val1;
		}
		else {
			choice[pos] = 1;
			val1 = findsol(pos + 1, cnt + 1);
			choice[pos] = 0;
			val2 = findsol(pos + 1, cnt);
			return min(val1, val2);
		}
	}
}
int main() {
	scanf("%d", &tcn);
	for (i = 1; i <= tcn; i++) {
		scanf("%d", &n);
		for (j = 1; j <= n; j++) {
			scanf("%d %d", &a[j][1], &a[j][2]);
		}
		printf("%lf\n", findsol(1, 0));
	}
	scanf("%d", &tcn);
}