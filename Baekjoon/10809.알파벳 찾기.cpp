#include<stdio.h>
#include<string.h>
int i, j, k, n, alpo[28];
char a[1001];
int main() {
	scanf("%s", &a);
	n = strlen(a);
	for (i = 0; i < n; i++)
		if (alpo[a[i] - 'a'] == 0)
			alpo[a[i] - 'a'] = i + 1;

	for (i = 0; i <= 25; i++)
		printf("%d ", alpo[i] - 1);
	scanf("%d", &n);
}
