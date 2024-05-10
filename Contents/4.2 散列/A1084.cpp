/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 20:41:09
 *	modified:	2023-03-25 20:57:13
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <set>

using namespace std;

int main(int argc, char const *argv[]) {

	string a, b;
	cin >> a >> b;
	set<char> r;
	for (int i = 0; i < (int)a.size(); i++) {
		if (b.find(a[i]) == string::npos) {
			a[i] = toupper(a[i]);
			if (r.find(a[i]) == r.end()) {
				r.emplace(a[i]);
				cout << a[i];
			}
		}
	}
	cout << "\n";

	return 0;
}