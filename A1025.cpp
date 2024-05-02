/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 11:58:47
 *	modified:	2023-03-22 12:37:37
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct stu {
	string id;
	int score, loc;
	int fr, lr;
};

bool cmp(stu a, stu b) {
	if (a.score != b.score) {
		return a.score > b.score;
	} else {
		return a.id < b.id;
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<stu> list;
	int count = 0;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			stu s;
			cin >> s.id >> s.score;
			s.loc = i + 1;
			list.emplace_back(s);
		}
		sort(list.begin() + count, list.begin() + count + k, cmp);
		list[count].lr = 1;
		for (int j = count + 1; j < count + k; j++) {
			if (list[j].score == list[j - 1].score) {
				list[j].lr = list[j - 1].lr;
			} else {
				list[j].lr = j - count + 1;
			}
		}
		count += k;
	}
	sort(list.begin(), list.end(), cmp);
	list[0].fr = 1;
	for (int i = 1; i < count; i++) {
		if (list[i].score == list[i - 1].score) {
			list[i].fr = list[i - 1].fr;
		} else {
			list[i].fr = i + 1;
		}
	}
	cout << count << "\n";
	for (auto it : list) {
		cout << it.id << " " << it.fr << " " << it.loc << " " << it.lr << "\n";
	}

	return 0;
}