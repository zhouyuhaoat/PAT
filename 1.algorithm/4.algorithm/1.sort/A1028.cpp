/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 13:09:11
 *	modified:	2023-03-25 13:53:59
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805468327690240 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1028 List Sorting
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805468327690240
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct stu {
    string id, name;
    int score;
};

int main(int argc, char const *argv[]) {

    int n, idx;
    cin >> n >> idx;
    vector<stu> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i].id >> data[i].name >> data[i].score;
    }
    sort(data.begin(), data.end(), [idx](stu a, stu b) -> bool {
        switch (idx) {
            case 1:
                return a.id < b.id;
                break;
            case 2:
                return a.name == b.name ? a.id < b.id : a.name < b.name;
                break;
            case 3:
                return a.score == b.score ? a.id < b.id : a.score < b.score;
                break;
        }
    });
    for (auto it : data) {
        cout << it.id << " " << it.name << " " << it.score << "\n";
    }

    return 0;
}
// @pintia code=end
