/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 19:46:29
 *	modified:	2023-03-23 19:57:34
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	int a, b;
	cin >> a >> b;
	string c = to_string(a + b);
	reverse(c.begin(), c.end());
	string d;
	for (int i = 0; i < (int)c.size(); i++) {
		d += c[i];
		if ((i + 1) % 3 == 0 && isdigit(c[i + 1])) {
			d += ",";
		}
	}
	reverse(d.begin(), d.end());
	cout << d << "\n";

	return 0;
}