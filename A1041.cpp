/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 21:52:17
 *	modified:	2023-03-25 21:57:08
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<int> d(n);
	map<int, int> count;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		++count[d[i]];
	}
	bool exist = false;
	for (auto it : d) {
		if (count[it] == 1) {
			cout << it << "\n";
			exist = true;
			break;
		}
	}
	if (!exist) {
		cout << "None\n";
	}

	return 0;
}