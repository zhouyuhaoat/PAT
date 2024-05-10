/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 16:06:59
 *	modified:	2023-03-22 16:13:04
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>

using namespace std;

int trans(string s, char c) {
	int cnt = count(s.begin(), s.end(), c);
	string t = string(cnt, c);
	if (!t.empty()) {
		return stoi(t);
	}
	return 0;
}

int main(int argc, char const *argv[]) {

	string a, b;
	char da, db;
	cin >> a >> da >> b >> db;
	cout << trans(a, da) + trans(b, db) << "\n";

	return 0;
}