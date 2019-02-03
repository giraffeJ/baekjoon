#include<stdio.h>
char a=0;
int main() {
	while (1) {
		a=getchar();
		if (a == EOF) break;
		putchar(a);
	}
	return 0;
}