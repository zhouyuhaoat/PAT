/*
 *	author:		zhouyuhao
 *	created:	2023-04-14 13:57:59
 *	modified:	2023-04-14 19:15:20
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=1697151678120173568 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1172 Panda and PP Milk
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1697151678120173568
*/

// @pintia code=start
#include <iostream>
#include <queue>

using namespace std;

struct Panda {
    int id, weight;
    Panda(int id, int weight) : id(id), weight(weight) {
    }
    friend bool operator<(Panda a, Panda b) {
        if (a.weight != b.weight) {
            return a.weight > b.weight;
        } else {
            return a.id > b.id;
        }
    }
};

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> weight(n + 2);
    priority_queue<Panda> panda;
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
        panda.emplace(i, weight[i]);
    }
    vector<int> milk(n + 2);
    while (!panda.empty()) {
        auto [id, _] = panda.top(); // the lightest panda
        panda.pop();
        if (milk[id - 1] == 0 && milk[id + 1] == 0) { // no both sides
            milk[id] = 200; // basic
        } else if (milk[id - 1] != 0 && milk[id + 1] == 0) { // only left side
            milk[id] = milk[id - 1]; // inherit
            if (weight[id] > weight[id - 1]) { // heavier
                milk[id] += 100;
            }
        } else if (milk[id + 1] != 0 && milk[id - 1] == 0) { // only right side
            milk[id] = milk[id + 1];
            if (weight[id] > weight[id + 1]) {
                milk[id] += 100;
            }
        } else { // both sides
            /*
                weight[id - 1] <= weight[id], weight[id] > weight[id + 1]
                - since weight first, index second in priority queue
            */
            if (weight[id] > weight[id - 1]) { // heavier than both sides
                milk[id] = max(milk[id - 1], milk[id + 1]) + 100;
            } else if (weight[id] == weight[id - 1]) { // equal to left side, heavier than right side
                milk[id] = max(milk[id - 1], milk[id + 1] + 100);
                if (milk[id] > milk[id - 1]) { // same weight, but not same milk
                    for (int i = id - 1; i >= 0; i--) { // backward
                        if (weight[i] == weight[id]) { // update milk since same weight
                            milk[i] = milk[id];
                        } else { // until the first different weight
                            break;
                        }
                    }
                }
            }
        }
    }
    int sum = 0;
    for (int it : milk) {
        sum += it;
    }
    cout << sum << "\n";

    return 0;
}
// @pintia code=end
