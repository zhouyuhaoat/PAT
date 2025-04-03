/*
 *	author:		zhouyuhao
 *	created:	2023-04-13 20:13:36
 *	modified:	2023-04-13 20:24:06
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1185 Stack of Hats
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct per {
    int id, w; // the heavier one wears larger hat
};

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) { // stack from bottom to top
        cin >> d[i];
    }
    vector<per> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].w;
        p[i].id = i + 1; // 0-based -> 1-based
    }
    vector<int> s(d); // size of hats
    sort(s.begin(), s.end(), greater<int>()); // larger hats first
    map<int, int> order; // size -> index -> person
    for (int i = 0; i < n; i++) {
        order[s[i]] = i;
    }
    sort(p.begin(), p.end(), [](per a, per b) { // heavier person first
        return a.w > b.w;
    });
    for (int i = n - 1; i >= 0; i--) { // de-stack from top to bottom
        cout << p[order[d[i]]].id;
        i > 0 ? cout << " " : cout << "\n";
    }

    return 0;
}