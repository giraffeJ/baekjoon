#include<stdio.h>
#include<string.h>
int i, n, res;
char a[102];
int main() {
	scanf("%s", &a);
	n = strlen(a);
	for (i = 0; i < n; i++) {
		if (a[i] == 'c') {
			if (a[i + 1] == '=' || a[i + 1] == '-') {
				i++;
			}
		}
		else if (a[i] == 'd') {
			if (a[i + 1] == '-')
				i++;
			else if (a[i + 1] == 'z' && a[i + 2] == '=')
				i += 2;
		}
		else if (a[i] == 'l' && a[i + 1] == 'j')
			i++;
		else if (a[i] == 'n' && a[i + 1] == 'j')
			i++;
		else if (a[i] == 's' && a[i + 1] == '=')
			i++;
		else if (a[i] == 'z' && a[i + 1] == '=')
			i++;
		res++;
	}
	printf("%d\n", res);
	scanf("%d", &n);
}