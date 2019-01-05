#include<stdio.h>
#include<string.h>
int tcn, i, j, k, n, m;
char a[1001];

int main() {
	scanf("%d", &tcn);
	for (i = 1; i <= tcn; i++) {
		scanf("%s", &a);
		n = strlen(a);
		for (j = 0; j < n; j++) {
			if (a[j] == '0') {
				if (a[j + 1] == '1') {
					j++;
				}
				else break;
			}
			else if (a[j] == '1') {
				if (a[j + 1] == '0' && a[j + 2] == '0') {
					for (k = j + 1; k<n; k++) {
						if (a[k] == '1') break;
					}
					if (k == n) break;
					else {
						for (; k < n; k++) {
							if (a[k] == '0') break;
						}
						if (k == n) {
							j = k;
							break;
						}
						else {
							if (a[k] == '0' && a[k + 1] == '0' && a[k-1]=='1' && a[k-2]=='1') {
								j = k - 2;
							}
							else j = k - 1;
						}
					}
				}
				else break;
			}
		}
		if (j == n) printf("YES\n");
		else printf("NO\n");
	}
	scanf("%d", &tcn);
}