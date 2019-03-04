#include<stdio.h>
int a[10001], i;
void sn(int val) {
	int temp;
	while (1) {
		temp = val;
		while (val > 0) {
			temp += val % 10;
			val /= 10;
		}
		if (temp > 10000) break;
		a[temp] = 1;
		val = temp;
	}
}
int main() {
	for (i = 1; i <= 10000; i++) {
		if (a[i] == 0) {
			printf("%d\n", i);
			sn(i);
		}
	}
	scanf("%d", &i);
}