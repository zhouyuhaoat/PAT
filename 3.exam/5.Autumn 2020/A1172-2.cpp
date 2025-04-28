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

struct pan { // panda
    int id, weight;
    pan(int id, int w) : id(id), weight(w) { // constructor
    }
    friend bool operator<(pan a, pan b) { // overload < operator for min-heap
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
    priority_queue<pan> panda;
    for (int i = 0; i < n; i++) {
        cin >> weight[i + 1];
        panda.emplace(i + 1, weight[i + 1]);
    }
    vector<int> milk(n + 2);
    while (!panda.empty()) {
        pan top = panda.top(); // the lightest panda
        panda.pop();
        int id = top.id;
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
            // since weight first, index second in priority queue
            // => weight[id - 1] <= weight[id], weight[id] > weight[id + 1]
            if (weight[id] > weight[id - 1]) { // heavier than both sides
                milk[id] = max(milk[id - 1], milk[id + 1]) + 100;
            } else if (weight[id] == weight[id - 1]) { // equal to left side, heavier than right side
                milk[id] = max(milk[id - 1], milk[id + 1] + 100);
                if (milk[id] > milk[id - 1]) { // same weight, but not same milk
                    for (int j = id - 1; j >= 0; j--) { // backward
                        if (weight[j] == weight[id]) { // update milk since same weight
                            milk[j] = milk[id];
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
