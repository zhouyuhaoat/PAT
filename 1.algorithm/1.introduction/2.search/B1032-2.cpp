/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 11:12:31
 *	modified:	2023-03-22 11:28:10
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805289432236032 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1032 挖掘机技术哪家强
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805289432236032
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    unordered_map<int, int> list;
    for (int i = 0; i < n; i++) {
        int id, score;
        cin >> id >> score;
        list[id] += score;
    }
    auto res = max_element(list.begin(), list.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    cout << res->first << " " << res->second << "\n";

    return 0;
}
// @pintia code=end
