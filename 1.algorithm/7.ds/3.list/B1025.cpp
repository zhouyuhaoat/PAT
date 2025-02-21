/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 10:11:09
 *	modified:	2023-03-28 11:22:01
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805260223102976 pid=994805296180871168 compiler=GXX
  ProblemSet: PAT (Basic Level) Practice （中文）
  Title: 1025 反转链表
  https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805296180871168
*/

// @pintia code=start
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct node {
    int data, next;
};

int main(int argc, char const *argv[]) {

    int id, n, k;
    cin >> id >> n >> k;
    node d[n + 1];
    map<int, int> loc;
    for (int i = 1; i <= n; i++) {
        int id;
        cin >> id >> d[i].data >> d[i].next;
        loc[id] = i;
    }
    vector<int> l;
    do {
        l.emplace_back(id);
        id = d[loc[id]].next;
    } while (id != -1);
    for (int i = 0; i < (int)l.size() / k; i++) {
        reverse(l.begin() + i * k, l.begin() + (i + 1) * k);
    }
    for (int i = 0; i < (int)l.size(); i++) {
        cout << setfill('0') << setw(5) << l[i] << " " << d[loc[l[i]]].data << " ";
        if (i < (int)l.size() - 1) {
            cout << setfill('0') << setw(5) << l[i + 1] << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
// @pintia code=end