/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 13:43:19
 *	modified:	2023-03-22 13:55:31
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805399578853376 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1070 Mooncake
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805399578853376
*/

// @pintia code=start
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct Mooncake {
    double stock, sale, price;
    // price per unit = sale / stock
};

int main(int argc, char const *argv[]) {

    int n;
    double demand;
    cin >> n >> demand;
    vector<Mooncake> inventory(n);
    for (int i = 0; i < n; i++) {
        cin >> inventory[i].stock;
    }
    for (int i = 0; i < n; i++) {
        cin >> inventory[i].sale;
        inventory[i].price = inventory[i].sale / inventory[i].stock;
    }
    sort(inventory.begin(), inventory.end(), [](Mooncake a, Mooncake b) {
        return a.price > b.price; // higher price per unit first
    });
    double profit = 0;
    for (int i = 0; i < n; i++) {
        if (demand > inventory[i].stock) { // not enough stock
            profit += inventory[i].sale;
            demand -= inventory[i].stock;
        } else { // enough stock
            profit += demand * inventory[i].price;
            break;
        }
    }
    cout << fixed << setprecision(2) << profit << "\n";

    return 0;
}
// @pintia code=end
