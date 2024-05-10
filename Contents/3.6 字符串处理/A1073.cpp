/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 17:43:14
 *	modified:	2023-03-23 18:56:44
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	string a;
	cin >> a;
	if (a[0] == '-') {
		cout << a[0];
	}
	a.erase(0, 1);
	size_t E = a.find('E');
	int e = stoi(a.substr(E + 1));
	a.erase(E);
	a.erase(1, 1);
	if (e < 0) {
		a.insert(0, abs(e), '0');
		a.insert(1, ".");
	} else if (e > 0) {
		int right = a.size() - 1;
		if (e >= right) {
			a.insert(a.size(), e - right, '0');
		} else {
			a.insert(e + 1, ".");
		}
	}
	cout << a << "\n";

	return 0;
}