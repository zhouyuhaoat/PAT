/*
 *	author:		zhouyuhao
 *	created:	2023-03-26 22:24:59
 *	modified:	2023-03-26 22:29:43
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

	int m, n;
	cin >> m >> n;
	map<int, int> count;
	int threshold = m * n / 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			if (++count[num] > threshold) {
				cout << num << "\n";
				return 0;
			}
		}
	}

	return 0;
}