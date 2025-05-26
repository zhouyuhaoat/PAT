/*
 *	author:		zhouyuhao
 *	created:	2023-04-02 22:35:40
 *	modified:	2023-04-02 22:50:15
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805355358306304 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1116 Come on! Let's C
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805355358306304
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    unordered_map<string, int> rank;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        rank[s] = i + 1;
    }
    int k;
    cin >> k;
    unordered_map<string, int> check; // bool <-> int
    while (k--) {
        string s;
        cin >> s;
        cout << s << ": ";
        if (check[s] != 0) { // visited
            cout << "Checked\n";
        } else {
            if (rank[s] == 0) { // not in the list
                cout << "Are you kidding?\n";
            } else if (++check[s] && rank[s] == 1) {
                cout << "Mystery Award\n";
            } else if (isPrime(rank[s])) {
                cout << "Minion\n";
            } else {
                cout << "Chocolate\n";
            }
        }
    }

    return 0;
}
// @pintia code=end
