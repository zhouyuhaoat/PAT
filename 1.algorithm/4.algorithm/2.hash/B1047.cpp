/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 21:48:03
 *	modified:	2023-03-25 21:52:11
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805260223102976 pid=994805277163896832 compiler=GXX
  ProblemSet: PAT (Basic Level) Practice （中文）
  Title: 1047 编程团体赛
  https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805277163896832
*/

// @pintia code=start
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    map<int, int> score;
    int h = -1, id = -1;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        int unused __attribute__((unused)) = 0;
        unused = scanf("%d-%d %d", &a, &b, &c);
        score[a] += c;
        if (score[a] > h) {
            h = score[a];
            id = a;
        }
    }
    cout << id << " " << h << "\n";

    return 0;
}
// @pintia code=end