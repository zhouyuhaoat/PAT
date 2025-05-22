/*
 *	author:		zhouyuhao
 *	created:	2023-03-26 21:36:09
 *	modified:	2023-03-26 22:07:59
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805433955368960 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1047 Student List for Course
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805433955368960
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    unordered_map<int, vector<string>> student; // course id -> student names
    for (int i = 0; i < n; i++) {
        string name;
        int num;
        cin >> name >> num;
        for (int j = 0; j < num; j++) {
            int id;
            cin >> id;
            student[id].emplace_back(name);
        }
    }
    for (auto& [_, name] : student) {
        sort(name.begin(), name.end());
    }
    for (int i = 1; i <= k; i++) {
        cout << i << " " << student[i].size() << "\n";
        for (string name : student[i]) {
            cout << name << "\n";
        }
    }

    return 0;
}
// @pintia code=end
