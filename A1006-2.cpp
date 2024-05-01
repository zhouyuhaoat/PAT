/*
 *	author:		zhouyuhao
 *	created:	2024-04-27 15:35:00
 *	modified:	2024-04-27 15:40:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	int m;
	cin >> m;
	string ft = "24:00:01", lt = "00:00:00";
	string fid, lid;
	for (int i = 0; i < m; ++i) {
		string id, in, out;
		cin >> id >> in >> out;
		if (in < ft) {
			ft = in;
			fid = id;
		}
		if (out >= lt) {
			lt = out;
			lid = id;
		}
	}
	cout << fid << " " << lid << "\n";

	return 0;
}