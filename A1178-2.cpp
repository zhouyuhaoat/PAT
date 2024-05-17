/*
 *	author:		zhouyuhao
 *	created:	2023-04-14 22:53:15
 *	modified:	2023-04-14 23:18:52
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <iomanip>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

vector<int> f(1e4, -1);

void dfs(int v, vector<int> &ans) {
	if (v == 0) {
		ans.emplace_back(v);
		return;
	}
	dfs(f[v], ans);
	ans.emplace_back(v);
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	getchar();
	stack<int> st;
	map<int, int> level;
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		int l = 0;
		while (isspace(s[0])) {
			s.erase(0, 1);
			++l;
		}
		int id = stoi(s);
		level[id] = l;
		if (id == 0) {
			st.emplace(0);
			f[0] = 0;
			continue;
		}
		int p = st.top();
		while (l <= level[p]) {
			st.pop();
			p = st.top();
		}
		st.emplace(id);
		f[id] = p;
	}
	int k;
	cin >> k;
	for (int q = 0; q < k; q++) {
		int id;
		cin >> id;
		if (f[id] == -1) {
			cout << "Error: " << setfill('0') << setw(4) << id << " is not found." << "\n";
			continue;
		}
		vector<int> ans;
		dfs(id, ans);
		for (int i = 0; i < (int)ans.size(); i++) {
			cout << setfill('0') << setw(4) << ans[i];
			i < (int)ans.size() - 1 ? cout << "->" : cout << "\n";
		}
	}
	return 0;
}