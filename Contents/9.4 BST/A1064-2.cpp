/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 20:18:41
 *	modified:	2023-03-29 20:38:03
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, front = 0;
vector<int> in, cbt;

void intra(int r) {
	if (r >= n) {
		return;
	}
	intra(2 * r + 1);
	cbt[r] = in[front++];
	intra(2 * r + 2);
}

int main(int argc, char const *argv[]) {

	cin >> n;
	in.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	sort(in.begin(), in.end());
	cbt.resize(n);
	intra(0);
	for (int i = 0; i < n; i++) {
		cout << cbt[i];
		i < n - 1 ? cout << " " : cout << "\n";
	}

	return 0;
}