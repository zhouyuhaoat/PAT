/*
 *	author:		zhouyuhao
 *	created:	2023-03-26 11:12:11
 *	modified:	2023-03-26 12:37:52
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	map<int, int> l;
	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		l[d] = i;
	}
	int count = 0, match = 1;
	bool sorted = false;
	while (!sorted) {
		while (l[0] != 0) {
			swap(l[0], l[l[0]]);
			++count;
		}
		sorted = true;
		for (int i = match; i < n; i++) {
			if (l[i] != i) {
				swap(l[i], l[0]);
				++count;
				match = i;
				sorted = false;
				break;
			}
		}
	}
	cout << count << "\n";

	return 0;
}