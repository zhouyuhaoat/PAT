/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 09:51:43
 *	modified:	2023-04-05 10:02:06
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	map<string, bool> al;
	for (int i = 0; i < n; i++) {
		string id;
		cin >> id;
		al[id] = true;
	}
	int m;
	cin >> m;
	int cntal = 0;
	string oal, oalbd = "99999999";
	string ogu, ogubd = oalbd;
	for (int i = 0; i < m; i++) {
		string id;
		cin >> id;
		string bd = id.substr(6, 8);
		if (al[id]) {
			++cntal;
			if (bd < oalbd) {
				oalbd = bd;
				oal = id;
			}
		} else if (bd < ogubd) {
			ogubd = bd;
			ogu = id;
		}
	}
	cout << cntal << "\n";
	if (cntal == 0) {
		cout << ogu << "\n";
	} else {
		cout << oal << "\n";
	}

	return 0;
}