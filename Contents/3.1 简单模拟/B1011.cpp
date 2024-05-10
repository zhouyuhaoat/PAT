/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 16:02:14
 *	modified:	2023-03-22 16:04:53
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long a, b, c;
		cin >> a >> b >> c;
		cout << "Case #" << i + 1;
		if (a + b > c) {
			cout << ": true\n";
		} else {
			cout << ": false\n";
		}
	}

	return 0;
}