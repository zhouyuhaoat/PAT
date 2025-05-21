/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 21:19:36
 *	modified:	2023-03-25 21:22:20
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805284092887040 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1038 统计同成绩学生
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805284092887040
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    unordered_map<int, int> cnt; // score -> count
    for (int i = 0; i < n; i++) {
        int score;
        cin >> score;
        cnt[score]++;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int score;
        cin >> score;
        cout << cnt[score];
        i < k - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
