/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 20:38:11
 *	modified:	2023-03-29 20:38:50
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
	if (r > n) {
		return;
	}
	intra(2 * r);
	cbt[r] = in[front++];
	intra(2 * r + 1);
}

int main(int argc, char const *argv[]) {

	cin >> n;
	in.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	sort(in.begin(), in.end());
	cbt.resize(n + 1);
	intra(1);
	for (int i = 1; i <= n; i++) {
		cout << cbt[i];
		i < n ? cout << " " : cout << "\n";
	}

	return 0;
}