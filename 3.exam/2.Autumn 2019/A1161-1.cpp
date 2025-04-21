/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 19:33:11
 *	modified:	2023-04-05 20:57:47
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=1478635524918910976 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1161 Merging Linked Lists
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478635524918910976
*/

// @pintia code=start
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct node {
    int data, next;
};

unordered_map<int, node> nodes;

int main(int argc, char const *argv[]) {

    int head1, head2, n;
    cin >> head1 >> head2 >> n;
    for (int i = 0; i < n; i++) {
        int addr;
        cin >> addr >> nodes[addr].data >> nodes[addr].next;
    }
    vector<int> l1, l2;
    for (int p = head1; p != -1; p = nodes[p].next) {
        l1.emplace_back(p);
    }
    for (int p = head2; p != -1; p = nodes[p].next) {
        l2.emplace_back(p);
    }
    if (l1.size() < l2.size()) { // merge the shorter one into the longer one
        swap(l1, l2);
    }
    vector<int> ans;
    int idx = l2.size() - 1; // reverse order
    for (int i = 0; i < (int)l1.size(); i++) {
        ans.emplace_back(l1[i]);
        if ((i + 1) % 2 == 0 && idx >= 0) { // each two elements
            ans.emplace_back(l2[idx--]);
        }
    }
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << setfill('0') << setw(5) << ans[i] << " " << nodes[ans[i]].data << " ";
        if (i < (int)ans.size() - 1) {
            cout << setfill('0') << setw(5) << ans[i + 1] << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
// @pintia code=end
