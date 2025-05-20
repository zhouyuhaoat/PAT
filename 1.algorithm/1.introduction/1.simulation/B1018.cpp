/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 16:57:07
 *	modified:	2023-03-22 17:25:54
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805304020025344 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1018 锤子剪刀布
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805304020025344
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>

using namespace std;

struct Player {
    int win = 0, tie = 0, lose = 0;
    char pos = 'B'; // posture that has the most wins
    unordered_map<char, int> cnt; // pos -> win
};

void update(Player& p, char pos) { // update the posture with the most wins
    if (++p.cnt[pos] > p.cnt[p.pos] || (p.cnt[pos] == p.cnt[p.pos] && pos < p.pos)) {
        p.pos = pos;
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    Player p1, p2;
    unordered_map<char, int> pos2hand = {{'B', 0}, {'C', 1}, {'J', 2}};
    for (int i = 0; i < n; i++) {
        char pos1, pos2;
        cin >> pos1 >> pos2;
        int h1 = pos2hand[pos1], h2 = pos2hand[pos2];
        if ((h1 + 1) % 3 == h2) { // circular order
            p1.win++, p2.lose++;
            update(p1, pos1);
        } else if ((h2 + 1) % 3 == h1) {
            p1.lose++, p2.win++;
            update(p2, pos2);
        } else {
            p1.tie++, p2.tie++;
        }
    }
    cout << p1.win << " " << p1.tie << " " << p1.lose << "\n";
    cout << p2.win << " " << p2.tie << " " << p2.lose << "\n";
    cout << p1.pos << " " << p2.pos << "\n";

    return 0;
}
// @pintia code=end
