/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 22:49:25
 *	modified:	2023-04-05 23:05:37
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=1478635841315209216 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1165 Block Reversing
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478635841315209216
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

unordered_map<int, node> nodes; // addr <=> key

int main(int argc, char const *argv[]) {

    int head, n, k;
    cin >> head >> n >> k;
    for (int i = 0; i < n; i++) {
        int addr;
        cin >> addr >> nodes[addr].data >> nodes[addr].next;
    }
    vector<int> addr;
    for (int p = head; p != -1; p = nodes[p].next) {
        addr.emplace_back(p);
    }
    vector<int> ans;
    int size = addr.size();
    for (int i = size - size % k; i < size; i++) {
        ans.emplace_back(addr[i]);
    }
    int g = size / k; // group <=> block <=> part
    for (int i = g - 1; i >= 0; i--) { // block reversing
        for (int j = i * k; j < (i + 1) * k; j++) { // one block
            ans.emplace_back(addr[j]);
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
