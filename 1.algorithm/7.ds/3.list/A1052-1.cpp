/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 10:46:35
 *	modified:	2023-03-28 12:03:40
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805425780670464 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1052 Linked List Sorting
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805425780670464
*/

// @pintia code=start
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct node {
    int id, data, next;
    int flag;
};

int main(int argc, char const *argv[]) {

    int n, id;
    cin >> n >> id;
    if (id == -1) {
        cout << "0 -1\n";
        return 0;
    }
    vector<node> l(n + 1);
    map<int, int> loc;
    l[0].flag = 1;
    for (int i = 1; i <= n; i++) {
        cin >> l[i].id >> l[i].data >> l[i].next;
        l[i].flag = 1;
        loc[l[i].id] = i;
    }
    int cnt = 0;
    do {
        ++cnt;
        l[loc[id]].flag = 0;
        id = l[loc[id]].next;
    } while (id != -1);
    sort(l.begin(), l.end(), [](node a, node b) -> bool {
        if (a.flag != b.flag) {
            return a.flag < b.flag;
        } else {
            return a.data < b.data;
        }
    });
    cout << cnt << " " << setfill('0') << setw(5) << l[0].id << "\n";
    for (int i = 0; i < cnt; i++) {
        cout << setfill('0') << setw(5) << l[i].id << " " << l[i].data << " ";
        if (i < cnt - 1) {
            cout << setfill('0') << setw(5) << l[i + 1].id << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
// @pintia code=end