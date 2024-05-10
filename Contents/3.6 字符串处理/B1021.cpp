/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 22:19:04
 *	modified:	2023-03-22 22:21:55
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

	string s;
	cin >> s;
	map<char, int> count;
	for (auto c : s) {
		count[c]++;
	}
	for (auto it : count) {
		cout << it.first << ":" << it.second << "\n";
	}

	return 0;
}