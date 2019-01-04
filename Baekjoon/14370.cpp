#include<stdio.h>
#include<string.h>
int tcn, alp[28], num[12], i, j, k, n;
char input_string[3001];
int main() {
	scanf("%d", &tcn);
	for (i = 1; i <= tcn; i++) {
		scanf("%s", &input_string);
		n = strlen(input_string);
		for (j = 0; j < n; j++) {
			alp[input_string[j] - 64]++;
		}
		num[0] = alp[26];
		num[2] = alp[23];
		num[4] = alp[21];
		num[6] = alp[24];
		num[1] = alp[15] - num[0] - num[2] - num[4];
		num[3] = alp[18] - num[0] - num[4];
		num[7] = alp[19] - num[6];
		num[5] = alp[22] - num[7];
		num[8] = alp[20] - num[2] - num[3];
		num[9] = alp[9] - num[5] - num[6] - num[8];
		printf("Case #%d: ", i);
		for (j = 0; j <= 9; j++) {
			for (k = 1; k <= num[j]; k++) {
				printf("%d", j);
			}
			num[j] = 0;
		}
		for (j = 1; j <= 26; j++) {
			alp[j] = 0;
		}
		printf("\n");
	}
	scanf("%d", &tcn);
}