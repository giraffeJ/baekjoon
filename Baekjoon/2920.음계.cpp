#include<stdio.h>
int i, k, k2, sw, res;
char ntc[4][15] = { "", "ascending", "descending", "mixed" };
int main(){
	scanf("%d", &k);
	if (k == 1) res = 1;
	else if (k == 8) res = 2;
	else res = 3;
	for (i = 2; i <= 8; i++) {
		scanf("%d", &k2);
		if (res == 1 && k2 != k + 1) res = 3;
		else if (res == 2 && k2 != k - 1) res = 3;
		k = k2;
	}
	printf("%s\n", ntc[res]);
	scanf("%d", &k);
}