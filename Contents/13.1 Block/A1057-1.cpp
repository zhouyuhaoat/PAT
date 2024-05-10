/*
 *	author:		zhouyuhao
 *	created:	2023-04-12 16:45:24
 *	modified:	2023-04-12 17:08:43
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int maxn = 1e5 + 1;
const int sqr = sqrt(maxn);
stack<int> st;
vector<int> b(sqr), ht(maxn);

void emplace(int v) {
	st.emplace(v);
	++b[v / sqr];
	++ht[v];
}

void pop() {
	int v = st.top();
	st.pop();
	--b[v / sqr];
	--ht[v];
	cout << v << "\n";
}

void peekmedian(int k) {
	int cnt = 0, bi = 0;
	while (cnt + b[bi] < k) {
		cnt += b[bi++];
	}
	int median = bi * sqr;
	while (cnt + ht[median] < k) {
		cnt += ht[median++];
	}
	cout << median << "\n";
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s.find("Push") != string::npos) {
			int v;
			cin >> v;
			emplace(v);
		} else if (s.find("Pop") != string::npos) {
			if (st.empty()) {
				cout << "Invalid\n";
			} else {
				pop();
			}
		} else {
			if (st.empty()) {
				cout << "Invalid\n";
			} else {
				int k = (st.size() + 1) / 2;
				peekmedian(k);
			}
		}
	}

	return 0;
}