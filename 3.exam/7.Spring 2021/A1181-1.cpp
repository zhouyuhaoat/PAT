/*
 *	author:		zhouyuhao
 *	created:	2023-04-13 17:45:05
 *	modified:	2023-04-13 17:52:56
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1181 Lab Access Scheduling
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct per {
    string ent, exi; // enter and exit
};

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<per> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].ent >> p[i].exi; // time <=> string
    }
    // greedy: activity selection, interval scheduling
    sort(p.begin(), p.end(), [](per a, per b) {
        if (a.exi != b.exi) {
            return a.exi < b.exi; // end time: as earlier as possible
        } else {
            return a.ent > b.ent; // start time: for shorter time duration
        }
    });
    int cnt = 1;
    string lastExi = p[0].exi;
    for (int i = 1; i < n; i++) {
        if (p[i].ent >= lastExi) { // not overlap: enter after last exit
            cnt++;
            lastExi = p[i].exi;
        }
    }
    cout << cnt << "\n";

    return 0;
}
