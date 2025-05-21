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

struct Student {
    string id, name;
    int score;
};

int main(int argc, char const *argv[]) {

    int n, idx;
    cin >> n >> idx;
    vector<Student> student(n);
    for (int i = 0; i < n; i++) {
        cin >> student[i].id >> student[i].name >> student[i].score;
    }
    sort(student.begin(), student.end(), [idx](Student a, Student b) {
        if (idx == 2) {
            return a.name != b.name ? a.name < b.name : a.id < b.id;
        } else if (idx == 3) {
            return a.score != b.score ? a.score < b.score : a.id < b.id;
        } else {
            return a.id < b.id;
        }
    });
    for (auto it : student) {
        cout << it.id << " " << it.name << " " << it.score << "\n";
    }

    return 0;
}
// @pintia code=end
