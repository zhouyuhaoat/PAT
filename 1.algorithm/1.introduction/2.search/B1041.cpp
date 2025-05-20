/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 19:24:51
 *	modified:	2023-03-22 19:42:23
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805281567916032 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1041 考试座位号
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805281567916032
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    unordered_map<int, pair<string, int>> seat; // seat1 -> {id, seat2}
    for (int i = 0; i < n; i++) {
        pair<string, int> temp;
        int id;
        cin >> temp.first >> id >> temp.second;
        seat.emplace(id, temp);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int seat1;
        cin >> seat1;
        cout << seat[seat1].first << " " << seat[seat1].second << "\n";
    }

    return 0;
}
// @pintia code=end
