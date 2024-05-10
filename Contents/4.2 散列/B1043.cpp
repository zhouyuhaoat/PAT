/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 21:38:38
 *	modified:	2023-03-25 21:47:37
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

	string a;
	cin >> a;
	map<char, int> cnt;
	for (int i = 0; i < (int)a.size(); i++) {
		++cnt[a[i]];
	}
	char symbol[6] = {'P', 'A', 'T', 'e', 's', 't'};
	bool flag = true;
	for (int i = 0; flag; i++) {
		flag = false;
		for (int j = 0; j < 6; j++) {
			if (cnt[symbol[j]] != 0) {
				cout << symbol[j];
				--cnt[symbol[j]];
				flag = true;
			}
		}
	}
	cout << "\n";

	return 0;
}