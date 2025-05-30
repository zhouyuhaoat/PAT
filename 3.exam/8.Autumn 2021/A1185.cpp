/*
 *	author:		zhouyuhao
 *	created:	2023-04-13 20:13:36
 *	modified:	2023-04-13 20:24:06
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1185 Stack of Hats
*/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Person {
    int id, weight; // the heavier one wears larger hat
};

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> size(n); // size of hats
    for (int i = 0; i < n; i++) { // stack from bottom to top
        cin >> size[i];
    }
    vector<Person> person(n);
    for (int i = 0; i < n; i++) {
        cin >> person[i].weight;
        person[i].id = i + 1; // 0-based -> 1-based
    }
    vector<int> hat(size); // copy of size of hats
    /*
        pair the largest hat with the heaviest person
        1. larger hats first
        2. heavier person first
    */
    sort(hat.begin(), hat.end(), greater<int>());
    sort(person.begin(), person.end(), [](Person a, Person b) {
        return a.weight > b.weight;
    });
    unordered_map<int, int> order; // size -> index -> person
    for (int i = 0; i < n; i++) {
        order[hat[i]] = i;
    }
    for (int i = n - 1; i >= 0; i--) { // de-stack from top to bottom
        cout << person[order[size[i]]].id;
        i > 0 ? cout << " " : cout << "\n";
    }

    return 0;
}
