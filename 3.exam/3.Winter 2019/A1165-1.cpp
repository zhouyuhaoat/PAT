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

struct Node {
    int data, next;
};

int main(int argc, char const *argv[]) {

    int head, n, k;
    cin >> head >> n >> k;
    unordered_map<int, Node> nodes;
    for (int i = 0; i < n; i++) {
        int addr;
        cin >> addr >> nodes[addr].data >> nodes[addr].next;
    }
    vector<int> addr;
    for (int p = head; p != -1; p = nodes[p].next) {
        addr.emplace_back(p);
    }
    vector<int> res;
    int size = addr.size(); // size % k: the last truncated block
    for (int lo = size - size % k, hi = size; lo >= 0; hi = lo, lo -= k) {
        // group = part = block = [lo, hi)
        res.insert(res.end(), addr.begin() + lo, addr.begin() + hi);
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
