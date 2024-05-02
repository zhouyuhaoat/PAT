/*
 *	author:		zhouyuhao
 *	created:	2024-04-28 19:30:00
 *	modified:	2024-04-28 19:40:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> b = a;
	sort(a.begin(), a.end());
	set<int> r;
	int lm = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i] && b[i] > lm) {
			r.emplace(b[i]);
		}
		lm = max(lm, b[i]);
	}
	int count = r.size();
	cout << count << "\n";
	for (auto it : r) {
		cout << it;
		if (--count) {
			cout << " ";
		}
	}
	cout << "\n";

	return 0;
}