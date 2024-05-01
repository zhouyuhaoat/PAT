/*
 *	author:		zhouyuhao
 *	created:	2024-04-27 13:30:00
 *	modified:	2024-04-27 13:35:00
 *	item:		Programming Ability Test
 *	site:		Harbin
 */
#include <iostream>

using namespace std;

int trans(string s, char c) {
	int res = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == c) {
			res = res * 10 + (s[i] - '0');
		}
	}
	return res;
}

int main(int argc, char const *argv[]) {

	string a, b;
	char da, db;
	cin >> a >> da >> b >> db;
	cout << trans(a, da) + trans(b, db) << "\n";

	return 0;
}