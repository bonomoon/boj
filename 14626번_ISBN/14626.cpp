#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

char ch[15];
int num[14];

int main() {
	int a;

	//문자입력
	for (int i = 1; i < 14; i++) {
		scanf("%c", &ch[i]);
	}

	//from ch to int
	for (int i = 1; i < 14; i++) {
		if (ch[i] == '*') {
			a = i;
			num[i] = 0;
		}
		else {
			num[i] = ch[i] - '0';
		}
	}

	if (num[13] != 0) {
		num[13] = 10 - num[13];
	}
	
	int temp = 0;

	for (int i = 0; i < 10; i++) {
		num[a] = i;

		for (int j = 1; j < 13; j++) {
			if (j % 2 == 0) {
				temp += 3 * num[j];
			}
			else {
				temp += num[j];
			}
		}

		if (temp % 10 == num[13]) {
			printf("%d\n", i);
			break;
		}
		temp = 0;
	}
}
