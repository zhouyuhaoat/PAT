/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 14:32:14
 *	modified:	2023-03-25 16:30:05
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct stu {
	int id;
	int total;
	int rank;
	int perfect;
	bool show;
	vector<int> score;
	vector<bool> submit;
};

int main(int argc, char const *argv[]) {

	int n, k, m;
	cin >> n >> k >> m;
	vector<int> p(k + 1);
	for (int i = 0; i < k; i++) {
		cin >> p[i + 1];
	}
	map<int, int> loc;
	vector<vector<int>> list(m);
	int count = 0;
	for (int i = 0; i < m; i++) {
		vector<int> t(3);
		cin >> t[0] >> t[1] >> t[2];
		list[i] = t;
		if (loc[t[0]] == 0) {
			loc[t[0]] = ++count;
		}
	}
	++count;
	vector<stu> s(count);
	for (int i = 0; i < count; i++) {
		s[i].score.resize(k + 1);
		s[i].submit.resize(k + 1);
	}
	for (int i = 0; i < m; i++) {
		s[loc[list[i][0]]].id = list[i][0];
		if (list[i][2] > s[loc[list[i][0]]].score[list[i][1]]) {
			s[loc[list[i][0]]].total += list[i][2] - s[loc[list[i][0]]].score[list[i][1]];
			s[loc[list[i][0]]].score[list[i][1]] = list[i][2];
			s[loc[list[i][0]]].show = true;
			if (list[i][2] == p[list[i][1]]) {
				++s[loc[list[i][0]]].perfect;
			}
		} else if (list[i][2] == 0) {
			s[loc[list[i][0]]].show = true;
		}
		s[loc[list[i][0]]].submit[list[i][1]] = true;
	}
	sort(s.begin(), s.end(), [](stu a, stu b) -> bool {
		if (a.total != b.total) {
			return a.total > b.total;
		} else if (a.perfect != b.perfect) {
			return a.perfect > b.perfect;
		} else {
			return a.id < b.id;
		}
	});
	s[0].rank = 1;
	for (int i = 1; i < (int)s.size(); i++) {
		if (s[i].total == s[i - 1].total) {
			s[i].rank = s[i - 1].rank;
		} else {
			s[i].rank = i + 1;
		}
	}
	for (auto it : s) {
		if (it.show) {
			cout << it.rank << " " << setfill('0') << setw(5) << it.id << " " << it.total << " ";
			for (int i = 1; i <= k; i++) {
				if (it.submit[i]) {
					cout << it.score[i];
				} else {
					cout << "-";
				}
				if (i < k) {
					cout << " ";
				} else {
					cout << "\n";
				}
			}
		}
	}

	return 0;
}