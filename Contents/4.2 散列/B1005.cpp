/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 22:02:14
 *	modified:	2023-03-25 22:21:19
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int k;
	cin >> k;
	vector<int> d(k);
	for (int i = 0; i < k; i++) {
		cin >> d[i];
	}
	set<int, greater<int>> s;
	map<int, bool> flag;
	for (int i = 0; i < k; i++) {
		int n = d[i];
		while (n != 1) {
			if (n % 2 != 0) {
				n = 3 * n + 1;
			}
			n = n >> 1;
			flag[n] = true;
		}
	}
	for (auto it : d) {
		if (!flag[it]) {
			s.emplace(it);
		}
	}
	int count = s.size();
	for (auto it : s) {
		cout << it;
		if (--count > 0) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}

	return 0;
}