#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

vector<char> a;
char b[10] = "abcde";
int i;
string temp;
char temp2[10] = "Abcde";

int main() {
	temp = temp2;
	a.push_back('a');
	a.push_back('c');
	temp = a;
	i++;

}