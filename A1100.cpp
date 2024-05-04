/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 19:57:35
 *	modified:	2023-03-27 20:19:10
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

	int b = 13;
	string s1[b] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
	string s2[b] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
	map<string, int> m1, m2;
	for (int i = 0; i < b; i++) {
		m1[s1[i]] = i;
	}
	for (int i = 0; i < b; i++) {
		m2[s2[i]] = i;
	}
	int n;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		if (isdigit(s[0])) {
			int num = stoi(s);
			if (num < 13) {
				cout << s1[num] << "\n";
			} else if (num % 13 == 0) {
				cout << s2[num / b] << "\n";
			} else {
				cout << s2[num / b] << " " << s1[num % b] << "\n";
			}
		} else {
			if (s.size() > 3) {
				cout << m2[s.substr(0, 3)] * b + m1[s.substr(4, 3)] << "\n";
			} else {
				if (m1[s] != 0) {
					cout << m1[s] << "\n";
				} else {
					cout << m2[s] * 13 << "\n";
				}
			}
		}
	}

	return 0;
}