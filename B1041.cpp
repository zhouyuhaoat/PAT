/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 19:24:51
 *	modified:	2023-03-22 19:42:23
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	map<int, pair<string, int>> s;
	for (int i = 0; i < n; i++) {
		pair<string, int> temp;
		int id;
		cin >> temp.first >> id >> temp.second;
		s.insert(make_pair(id, temp));
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int id;
		cin >> id;
		cout << s[id].first << " " << s[id].second << "\n";
	}

	return 0;
}