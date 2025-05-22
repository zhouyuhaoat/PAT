/*
 *	author:		zhouyuhao
 *	created:	2023-03-26 21:36:09
 *	modified:	2023-03-26 22:07:59
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805447855292416 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1039 Course List for Student
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805447855292416
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
    unordered_map<string, vector<int>> course; // student name -> course ids
    for (int i = 0; i < k; i++) {
        int id, num;
        cin >> id >> num;
        for (int j = 0; j < num; j++) {
            string name;
            cin >> name;
            course[name].emplace_back(id);
        }
    }
    for (auto& [_, id] : course) {
        sort(id.begin(), id.end());
    }
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        cout << name << " " << course[name].size();
        for (int id : course[name]) {
            cout << " " << id;
        }
        cout << "\n";
    }

    return 0;
}
// @pintia code=end
