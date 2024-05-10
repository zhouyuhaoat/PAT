/*
 *	author:		zhouyuhao
 *	created:	2023-03-31 13:40:09
 *	modified:	2023-03-31 14:27:03
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<bool> vis;
vector<int> w;
vector<vector<int>> g;

int cnt = 1;
map<string, int> mid;
map<int, string> mstr;
void getid(string s) {
	if (mid[s] == 0) {
		mid[s] = cnt;
		mstr[cnt] = s;
		++cnt;
	}
}

void dfs(int v, int &num, int &sum, int &maxw, int &maxid) {
	vis[v] = true;
	++num;
	sum += w[v];
	if (w[v] > maxw) {
		maxw = w[v];
		maxid = v;
	}
	for (int i = 0; i < (int)g[v].size(); i++) {
		if (!vis[g[v][i]]) {
			dfs(g[v][i], num, sum, maxw, maxid);
		}
	}
}

int main(int argc, char const *argv[]) {

	int n, k;
	cin >> n >> k;
	vector<vector<int>> d;
	for (int i = 0; i < n; i++) {
		string n1, n2;
		int t;
		cin >> n1 >> n2 >> t;
		getid(n1), getid(n2);
		d.emplace_back(vector<int>{mid[n1], mid[n2], t});
	}
	g.resize(cnt), w.resize(cnt);
	for (int i = 0; i < n; i++) {
		g[d[i][0]].emplace_back(d[i][1]);
		g[d[i][1]].emplace_back(d[i][0]);
		w[d[i][0]] += d[i][2];
		w[d[i][1]] += d[i][2];
	}
	map<string, int> gang;
	vis.resize(cnt, false);
	for (int i = 1; i <= cnt - 1; i++) {
		if (!vis[i]) {
			int sum = 0, maxw = -1, maxid = -1, num = 0;
			dfs(i, num, sum, maxw, maxid);
			if (sum > 2 * k && num > 2) {
				gang.emplace(make_pair(mstr[maxid], num));
			}
		}
	}
	cout << gang.size() << "\n";
	for (auto it : gang) {
		cout << it.first << " " << it.second << "\n";
	}

	return 0;
}