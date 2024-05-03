/*
 *	author:		zhouyuhao
 *	created:	2023-04-10 22:39:17
 *	modified:	2023-04-11 09:49:24
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	string a;
	int b;
	cin >> a >> b;
	string c;
	int carry = 0;
	for (int i = 0; i < (int)a.size(); i++) {
		int n = a[i] - '0' + carry * 10;
		if (n >= b) {
			c += n / b + '0';
			carry = n % b;
		} else {
			c += '0';
			carry += n;
		}
	}
	while (c[0] == '0' && c.size() > 1) {
		c.erase(0, 1);
	}
	cout << c << " " << carry << "\n";

	return 0;
}