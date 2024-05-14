/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 00:50:51
 *	modified:	2023-04-03 01:50:20
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isunq = true;
vector<int> pre, in, post;

void intra(int prel, int preh, int postl, int posth) {
	if (prel == preh) {
		in.emplace_back(pre[prel]);
		return;
	}
	if (pre[prel] == post[posth]) {
		int i = find(pre.begin() + 1, pre.end(), post[posth - 1]) - pre.begin();
		if (i - prel > 1) {
			intra(prel + 1, i - 1, postl, postl + (i - prel) - 1 - 1);
		} else {
			isunq = false;
		}
		in.emplace_back(post[posth]);
		intra(i, preh, postl + (i - prel) - 1, posth - 1);
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	pre.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> pre[i];
	}
	post.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}
	intra(0, n - 1, 0, n - 1);
	if (isunq) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	for (int i = 0; i < n; i++) {
		cout << in[i];
		i < n - 1 ? cout << " " : cout << "\n";
	}

	return 0;
}