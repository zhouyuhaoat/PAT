/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 19:59:56
 *	modified:	2023-04-04 20:46:20
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second != b.second) {
		return a.second > b.second;
	} else {
		return a.first < b.first;
	}
}

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	map<string, int> sites, siten;
	map<string, map<string, int>> date;
	vector<pair<string, int>> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i].first >> s[i].second;
		++siten[s[i].first.substr(1, 3)];
		sites[s[i].first.substr(1, 3)] += s[i].second;
		++date[s[i].first.substr(4, 6)][s[i].first.substr(1, 3)];
	}
	sort(s.begin(), s.end(), cmp);
	for (int q = 0; q < m; q++) {
		int type;
		string term;
		cin >> type >> term;
		cout << "Case " << q + 1 << ": " << type << " " << term << "\n";
		bool isempty = true;
		if (type == 1) {
			for (auto it : s) {
				if (it.first[0] == term[0]) {
					cout << it.first << " " << it.second << "\n";
					isempty = false;
				}
			}
		} else if (type == 2) {
			if (siten[term] != 0) {
				cout << siten[term] << " " << sites[term] << "\n";
				isempty = false;
			}
		} else {
			vector<pair<string, int>> ans(date[term].begin(), date[term].end());
			sort(ans.begin(), ans.end(), cmp);
			for (auto it : ans) {
				cout << it.first << " " << it.second << "\n";
				isempty = false;
			}
		}
		if (isempty) {
			cout << "NA\n";
		}
	}

	return 0;
}