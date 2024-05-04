/*
 *	author:		zhouyuhao
 *	created:	2023-03-26 21:36:09
 *	modified:	2023-03-26 22:07:59
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(int argc, char const *argv[]) {

	int n, k;
	cin >> n >> k;
	map<string, set<int>> c;
	for (int i = 0; i < k; i++) {
		int no, ns;
		cin >> no >> ns;
		for (int j = 0; j < ns; j++) {
			string name;
			cin >> name;
			c[name].emplace(no);
		}
	}
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		cout << name << " " << c[name].size();
		for (auto it : c[name]) {
			cout << " " << it;
		}
		cout << "\n";
	}

	return 0;
}