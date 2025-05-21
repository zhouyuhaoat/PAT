/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 13:58:24
 *	modified:	2023-03-25 14:10:39
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805421066272768 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1055 The World's Richest
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805421066272768
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct People {
    string name;
    int age, worth;
};

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    vector<People> people(n);
    for (int i = 0; i < n; i++) {
        cin >> people[i].name >> people[i].age >> people[i].worth;
    }
    sort(people.begin(), people.end(), [](People a, People b) {
        if (a.worth != b.worth) {
            return a.worth > b.worth;
        } else if (a.age != b.age) {
            return a.age < b.age;
        } else {
            return a.name < b.name;
        }
    });
    for (int i = 0; i < k; i++) {
        int m, lo, hi;
        cin >> m >> lo >> hi;
        cout << "Case #" << i + 1 << ":\n";
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (people[j].age >= lo && people[j].age <= hi) {
                cout << people[j].name << " " << people[j].age << " " << people[j].worth << "\n";
                if (++cnt == m) {
                    break;
                }
            }
        }
        if (cnt == 0) {
            cout << "None\n";
        }
    }

    return 0;
}
// @pintia code=end
