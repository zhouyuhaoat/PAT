/*
 *	author:		zhouyuhao
 *	created:	2023-04-13 19:47:38
 *	modified:	2023-04-13 22:49:31
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <iostream>
#include <vector>

using namespace std;

struct arr {
	int add, len;
};

int main(int argc, char const *argv[]) {

	int n, k;
	cin >> n >> k;
	vector<arr> d(n);
	int size = 0;
	for (int i = 0; i < n; i++) {
		cin >> d[i].add >> d[i].len;
		size += d[i].len;
	}
	int ans = 1;
	for (int q = 0; q < k; q++) {
		int v;
		cin >> v;
		if (v >= size) {
			cout << "Illegal Access\n";
			continue;
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += d[i].len;
			if (v < sum) {
				cout << d[i].add + (v - sum + d[i].len) * 4 << "\n";
				ans = max(ans, i + 1);
				break;
			}
		}
	}
	cout << ans << "\n";

	return 0;
}