/*
 *	author:		zhouyuhao
 *	created:	2024-05-14 18:59:56
 *	modified:	2024-05-14 19:38:41
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */
#include <iostream>
#include <map>
#include <set>

using namespace std;

struct node {
	int id, freq;
	bool operator<(const node &n) const {
		if (freq != n.freq) {
			return freq > n.freq;
		} else {
			return id < n.id;
		}
	}
};

int main(int argc, char const *argv[]) {

	int n, k;
	cin >> n >> k;
	map<int, int> cnt;
	set<node> s;
	for (int i = 0; i < n; i++) {
		int id;
		cin >> id;
		if (!s.empty()) {
			cout << id << ":";
			int temp = 0;
			for (auto it = s.begin(); temp++ < k && it != s.end(); it++) {
				cout << " " << it->id;
			}
			cout << "\n";
		}
		auto it = s.find(node{id, cnt[id]});
		if (it != s.end()) {
			s.erase(it);
		}
		s.insert(node{id, ++cnt[id]});
	}

	return 0;
}