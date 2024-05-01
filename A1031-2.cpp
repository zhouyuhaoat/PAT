/*
 *	author:		zhouyuhao
 *	created:	2024-04-27 18:24:00
 *	modified:	2024-04-27 18:30:00
 *	item:		Programming Ability Test
 *	site:		226, Harbin
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	string s;
	cin >> s;
	int n = s.size() + 2;
	int n1 = n / 3, n3 = n1, n2 = n - n1 - n3;
	for (int i = 0; i < n1 - 1; i++) {
		for (int j = 0; j < n2; j++) {
			if (j == 0) {
				cout << s[i];
			} else if (j == n2 - 1) {
				cout << s[s.size() - 1 - i];
			} else {
				cout << " ";
			}
		}
		cout << "\n";
	}
	for (int i = 0; i < n2; i++) {
		cout << s[n1 + i - 1];
	}
	cout << "\n";

	return 0;
}