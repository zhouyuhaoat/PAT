/*
 *	author:		zhouyuhao
 *	created:	2023-03-26 21:09:50
 *	modified:	2023-03-26 21:32:15
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<int> d(n);
	cin >> d[0];
	vector<int> leftmax(n);
	int lm = d[0];
	for (int i = 1; i < n; i++) {
		cin >> d[i];
		leftmax[i] = lm;
		lm = max(lm, d[i]);
	}
	vector<int> rightmin(n);
	rightmin[n - 1] = INT_MAX;
	int rm = d[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		rightmin[i] = rm;
		rm = min(rm, d[i]);
	}
	set<int> r;
	for (int i = 0; i < n; i++) {
		if (d[i] > leftmax[i] && d[i] < rightmin[i]) {
			r.emplace(d[i]);
		}
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