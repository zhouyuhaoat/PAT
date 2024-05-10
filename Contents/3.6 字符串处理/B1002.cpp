/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 22:39:47
 *	modified:	2023-03-22 22:45:38
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	string s;
	cin >> s;
	int sum = 0;
	for (auto c : s) {
		sum += c - '0';
	}
	s = to_string(sum);
	string pinyin[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	for (int i = 0; i < (int)s.size(); i++) {
		cout << pinyin[s[i] - '0'];
		if (i < (int)s.size() - 1) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}

	return 0;
}