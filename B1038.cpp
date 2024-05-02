/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 21:19:36
 *	modified:	2023-03-25 21:22:20
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	map<int, int> count;
	for (int i = 0; i < n; i++) {
		int score;
		cin >> score;
		++count[score];
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int score;
		cin >> score;
		cout << count[score];
		if (i < k - 1) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}

	return 0;
}