/*
 *	author:		zhouyuhao
 *	created:	2024-05-01 21:42:15
 *	modified:	2024-05-01 21:50:15
 *	item:		Programming Ability Test
 *	site:		226, Harbin
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	string p[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	string w[10] = {"", "", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"};
	string s;
	cin >> s;
	if (s[0] == '-') {
		cout << "Fu ";
		s.erase(0, 1);
	}
	if (s.size() == 1) {
		cout << p[s[0] - '0'];
	} else {
		cout << p[s[0] - '0'] << " " << w[s.size()];
	}
	for (int i = 1; i < (int)s.size() - 1; i++) {
		if (s[i] != '0') {
			cout << " " << p[s[i] - '0'] << " " << w[s.size() - i];
		} else {
			if (s.size() - i == 5) {
				cout << " Wan";
			} else if (s[i + 1] != '0') {
				cout << " ling";
			}
		}
	}
	if (s[s.size() - 1] != '0') {
		cout << " " << p[s[s.size() - 1] - '0'];
	}
	cout << "\n";

	return 0;
}