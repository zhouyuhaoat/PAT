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

struct Node {
    int data, next;
};

int main(int argc, char const *argv[]) {

    int head1, head2, n;
    cin >> head1 >> head2 >> n;
    unordered_map<int, Node> nodes;
    for (int i = 0; i < n; i++) {
        int addr;
        cin >> addr >> nodes[addr].data >> nodes[addr].next;
    }
    vector<int> list1, list2;
    for (int p = head1; p != -1; p = nodes[p].next) {
        list1.emplace_back(p);
    }
    for (int p = head2; p != -1; p = nodes[p].next) {
        list2.emplace_back(p);
    }
    if (list1.size() < list2.size()) { // merge the shorter one into the longer one
        swap(list1, list2);
    }
    vector<int> res;
    int idx = list2.size() - 1; // reverse order
    for (int i = 0; i < (int)list1.size(); i++) {
        res.emplace_back(list1[i]);
        if ((i + 1) % 2 == 0 && idx >= 0) { // each two elements
            res.emplace_back(list2[idx--]);
        }
    }
    for (int i = 0; i < (int)res.size(); i++) {
        cout << setfill('0') << setw(5) << res[i] << " " << nodes[res[i]].data << " ";
        if (i < (int)res.size() - 1) {
            cout << setfill('0') << setw(5) << res[i + 1] << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
// @pintia code=end
