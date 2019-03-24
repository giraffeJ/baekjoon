#include<stdio.h>
#include<algorithm>
using namespace std;
int a[500010], count_[10000], n, count_max, count_max_val, max_val=-5000, min_val=5000, avg_int, cmv_n;
double avg_;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		count_[a[i] + 4000]++;
		if (count_[a[i] + 4000] > count_max) {
			count_max = count_[a[i] + 4000];
			count_max_val = a[i];
		}
		if (a[i] < min_val) min_val = a[i];
		if (a[i] > max_val) max_val = a[i];
		avg_ += a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 0; i <= 8000; i++) {
		if (count_[i] == count_max) {
			count_max_val = i - 4000;
			cmv_n++;
			if (cmv_n == 2) break;
		}
	}
	avg_ /= n;
	if (avg_ < 0) avg_ -= 0.5;
	else avg_ += 0.5;
	avg_int = avg_;
	printf("%d\n%d\n%d\n%d\n", avg_int, a[(n + 1) / 2], count_max_val, max_val - min_val);
	return 0;
}