/*
 *	author:		zhouyuhao
 *	created:	2023-04-14 13:57:59
 *	modified:	2023-04-14 19:15:20
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <iostream>
#include <queue>

using namespace std;

struct pan {
	int id, w;
	pan(int id, int w) : id(id), w(w) {
	}
	friend bool operator<(pan a, pan b) {
		if (a.w != b.w) {
			return a.w > b.w;
		} else {
			return a.id > b.id;
		}
	}
};

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<int> w(n + 2);
	priority_queue<pan> p;
	for (int i = 0; i < n; i++) {
		cin >> w[i + 1];
		p.emplace(i + 1, w[i + 1]);
	}
	vector<int> m(n + 2);
	while (!p.empty()) {
		pan t = p.top();
		p.pop();
		int id = t.id;
		if (m[id - 1] == 0 && m[id + 1] == 0) {
			m[id] = 200;
		} else if (m[id - 1] != 0 && m[id + 1] == 0) {
			m[id] = m[id - 1];
			if (w[id] > w[id - 1]) {
				m[id] += 100;
			}
		} else if (m[id + 1] != 0 && m[id - 1] == 0) {
			m[id] = m[id + 1];
			if (w[id] > w[id + 1]) {
				m[id] += 100;
			}
		} else {
			if (w[id] > w[id - 1]) {
				m[id] = max(m[id - 1], m[id + 1]) + 100;
			} else if (w[id] == w[id - 1]) {
				m[id] = max(m[id - 1], m[id + 1] + 100);
				if (m[id] > m[id - 1]) {
					for (int j = id - 1; j >= 0; j--) {
						if (w[j] == w[id]) {
							m[j] = m[id];
						} else {
							break;
						}
					}
				}
			}
		}
	}
	int sum = 0;
	for (auto it : m) {
		sum += it;
	}
	cout << sum << "\n";

	return 0;
}