/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 16:57:07
 *	modified:	2023-03-22 17:25:54
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805304020025344 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1018 锤子剪刀布
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805304020025344
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void print(vector<int> v) {
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i];
        i < (int)v.size() - 1 ? cout << " " : cout << "\n";
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> a(3), b(3);
    vector<int> ap(3), bp(3);
    char pos[3] = {'B', 'C', 'J'};
    map<char, int> m = {{'B', 0}, {'C', 1}, {'J', 2}};
    for (int i = 0; i < n; i++) {
        char ca, cb;
        cin >> ca >> cb;
        int ia = m[ca], ib = m[cb];
        if ((ia + 1) % 3 == ib) { // circular order
            a[0]++, b[2]++;
            ap[ia]++;
        } else if ((ib + 1) % 3 == ia) {
            a[2]++, b[0]++;
            bp[ib]++;
        } else {
            a[1]++, b[1]++;
        }
    }
    int am = max_element(ap.begin(), ap.end()) - ap.begin();
    int bm = max_element(bp.begin(), bp.end()) - bp.begin();
    print(a), print(b);
    cout << pos[am] << " " << pos[bm] << "\n";

    return 0;
}
// @pintia code=end
