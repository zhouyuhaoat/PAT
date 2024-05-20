/*
 *	author:		zhouyuhao
 *	created:	2023-04-13 17:53:15
 *	modified:	2023-04-13 18:14:44
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> t;

void upadjust(int lo, int hi) {
	int i = hi, j = i / 2;
	while (j >= lo) {
		if (t[i] > t[j]) {
			swap(t[i], t[j]);
			i = j;
			j = i / 2;
		} else {
			break;
		}
	}
}

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	t.resize(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> t[i + 1];
		upadjust(1, i + 1);
	}
	map<int, int> loc;
	for (int i = 0; i < n; i++) {
		loc[t[i + 1]] = i + 1;
	}
	getchar();
	for (int q = 0; q < m; q++) {
		string s;
		getline(cin, s);
		bool flag = false;
		if (s.find("root") != string::npos) {
			int r;
			sscanf(s.c_str(), "%d is the root", &r);
			if (loc[r] == 1) {
				flag = true;
			}
		} else if (s.find("siblings") != string::npos) {
			int a, b;
			sscanf(s.c_str(), "%d and %d are siblings", &a, &b);
			if (loc[a] / 2 == loc[b] / 2) {
				flag = true;
			}
		} else if (s.find("parent") != string::npos) {
			int pa, ch;
			sscanf(s.c_str(), "%d is the parent of %d", &pa, &ch);
			if (loc[pa] == loc[ch] / 2) {
				flag = true;
			}
		} else if (s.find("left") != string::npos) {
			int lc, pa;
			sscanf(s.c_str(), "%d is the left child of %d", &lc, &pa);
			if (loc[pa] * 2 == loc[lc]) {
				flag = true;
			}
		} else if (s.find("right") != string::npos) {
			int rc, pa;
			sscanf(s.c_str(), "%d is the right child of %d", &rc, &pa);
			if (loc[pa] * 2 + 1 == loc[rc]) {
				flag = true;
			}
		}
		cout << flag;
	}
	cout << "\n";

	return 0;
}