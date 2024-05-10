/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 20:40:55
 *	modified:	2023-03-22 20:50:36
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	int m;
	cin >> m;
	string firstid, lastid;
	int firsts = 24 * 3600 + 1;
	int lasts = -1;
	for (int i = 0; i < m; ++i) {
		string id;
		cin >> id;
		int h, m, s;
		int unused __attribute__((unused));
		unused = scanf("%d:%d:%d", &h, &m, &s);
		int ins = h * 3600 + m * 60 + s;
		unused = scanf("%d:%d:%d", &h, &m, &s);
		int outs = h * 3600 + m * 60 + s;
		if (ins < firsts) {
			firsts = ins;
			firstid = id;
		}
		if (outs > lasts) {
			lasts = outs;
			lastid = id;
		}
	}
	cout << firstid << " " << lastid << "\n";

	return 0;
}