/*
 *	author:		zhouyuhao
 *	created:	2023-04-14 23:05:51
 *	modified:	2023-04-14 23:12:48
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <iomanip>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int>> g(1e4);
vector<int> temp, ans;

void dfs(int r, int e) {
	if (r == e) {
		ans = temp;
		return;
	}
	for (int i = 0; i < (int)g[r].size(); i++) {
		temp.emplace_back(g[r][i]);
		dfs(g[r][i], e);
		temp.pop_back();
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	getchar();
	stack<int> st;
	map<int, int> level;
	map<int, bool> exist;
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
		exist[id] = true;
		if (id == 0) {
			st.emplace(0);
			continue;
		}
		int p = st.top();
		while (l <= level[p]) {
			st.pop();
			p = st.top();
		}
		st.emplace(id);
		g[p].emplace_back(id);
	}
	temp.emplace_back(0);
	int k;
	cin >> k;
	for (int q = 0; q < k; q++) {
		int id;
		cin >> id;
		if (exist[id]) {
			dfs(0, id);
			for (int i = 0; i < (int)ans.size(); i++) {
				cout << setfill('0') << setw(4) << ans[i];
				i < (int)ans.size() - 1 ? cout << "->" : cout << "\n";
			}
		} else {
			cout << "Error: " << setfill('0') << setw(4) << id << " is not found.\n";
		}
	}

	return 0;
}