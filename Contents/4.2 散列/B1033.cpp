/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 21:02:10
 *	modified:	2023-03-25 21:18:51
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	string a, b;
	getline(cin, a);
	getline(cin, b);
	bool shift = false;
	for (int i = 0; i < (int)a.size(); i++) {
		a[i] = tolower(a[i]);
		if (a[i] == '+') {
			shift = true;
		}
	}
	for (int i = 0; i < (int)b.size(); i++) {
		if (isupper(b[i])) {
			if (shift || a.find(tolower(b[i])) != string::npos) {
				continue;
			}
		} else {
			if (a.find(b[i]) != string::npos) {
				continue;
			}
		}
		cout << b[i];
	}
	cout << "\n";

	return 0;
}