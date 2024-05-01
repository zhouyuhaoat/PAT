/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 19:07:40
 *	modified:	2023-03-31 15:52:46
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long a, b, c, sum;
		cin >> a >> b >> c;
		sum = a + b;
		bool flag = false;
		if (a > 0 && b > 0 && sum < 0) {
			flag = true;
		} else if (!(a < 0 && b < 0 && sum >= 0) && sum > c) {
			flag = true;
		}
		cout << "Case #" << i + 1;
		if (flag) {
			cout << ": true\n";
		} else {
			cout << ": false\n";
		}
	}

	return 0;
}