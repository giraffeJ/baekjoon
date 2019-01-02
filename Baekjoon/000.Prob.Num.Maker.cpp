#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
	int t;
	t = time(NULL);
	srand(t);
	int n = rand() % 16771;
	n++;
	printf("%d\n", n);
	scanf("%d", &n);
}