/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 13:27:55
 *	modified:	2023-03-27 14:14:14
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> d) {
	for (int i = 0; i < (int)d.size(); i++) {
		cout << d[i];
		if (i < (int)d.size() - 1) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<int> d1(n), d2(n);
	for (int i = 0; i < n; i++) {
		cin >> d1[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> d2[i];
	}
	vector<int> d3 = d1;
	for (int i = 2; i <= n; i++) {
		sort(d1.begin(), d1.begin() + i);
		if (d1 == d2) {
			cout << "Insertion Sort\n";
			sort(d1.begin(), d1.begin() + i + 1);
			print(d1);
			return 0;
		}
	}
	int g = 2;
	while (true) {
		for (int i = 0; i <= n / g; i++) {
			sort(d3.begin() + i * g, d3.begin() + min(n, (i + 1) * g));
		}
		g *= 2;
		if (d3 == d2) {
			cout << "Merge Sort\n";
			for (int i = 0; i <= n / g; i++) {
				sort(d3.begin() + i * g, d3.begin() + min(n, (i + 1) * g));
			}
			print(d3);
			break;
		}
	}

	return 0;
}