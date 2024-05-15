/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 11:46:30
 *	modified:	2023-04-03 11:53:21
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>

using namespace std;

bool iscut(string s) {
	int z = stoi(s);
	int a = stoi(s.substr(0, s.size() / 2));
	int b = stoi(s.substr(s.size() / 2));
	if (a * b != 0 && z % (a * b) == 0) {
		return true;
	}
	return false;
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (iscut(s)) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

	return 0;
}