/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 03:19:31
 *	modified:	2023-04-03 03:41:20
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct node {
	node *lc, *rc;
};

vector<int> in, post;
map<int, vector<int>> t;

void create(int r, int s, int e, int l) {
	if (s > e) {
		return;
	}
	t[l].emplace_back(post[r]);
	int i = find(in.begin(), in.end(), post[r]) - in.begin();
	create(r - (e - i) - 1, s, i - 1, l + 1);
	create(r - 1, i + 1, e, l + 1);
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	in.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	post.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}
	create(n - 1, 0, n - 1, 1);
	vector<int> ans;
	for (auto it : t) {
		if (it.first % 2 != 0) {
			ans.insert(ans.end(), it.second.rbegin(), it.second.rend());
		} else {
			ans.insert(ans.end(), it.second.begin(), it.second.end());
		}
	}
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i];
		i < (int)ans.size() - 1 ? cout << " " : cout << "\n";
	}

	return 0;
}