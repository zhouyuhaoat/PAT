/*
 *	author:		zhouyuhao
 *	created:	2023-04-11 13:45:49
 *	modified:	2023-04-12 01:05:09
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	int b = 1, cnt = 0;
	while (n / b != 0) {
		int left = n / b / 10;
		int now = n / b % 10;
		int right = n % b;
		if (now == 0) {
			cnt += left * b;
		} else if (now == 1) {
			cnt += left * b + right + 1;
		} else {
			cnt += (left + 1) * b;
		}
		b *= 10;
	}
	cout << cnt << "\n";

	return 0;
}