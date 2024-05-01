/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 21:17:38
 *	modified:	2023-03-22 21:29:28
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	string s;
	cin >> s;
	int n = s.size();
	int n1 = 0, n2 = 0, n3 = 0;
	for (int i = 3; i <= n; i++) {
		int temp = n + 2 - i;
		if (temp % 2 == 0 && temp / 2 <= i) {
			n1 = n3 = temp / 2;
			n2 = i;
			break;
		}
	}
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