/*
Input data:
The input is N, Q, X, L where:
- N is the number of the data you want to insert
- Q is the number of search query to perform
- X is the number of search query that is found in the inserted data
- L is the load factor
*/
#include <iostream>
#include <cstdio>
#include <unordered_set>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;
int n, q, x;
double loadFactor;
unordered_set<int> sets, sets2;
vector<int> vec, vec2, vec3;
vector<string> names;
string line;

int main () {
    srand (time(NULL));
    // input name
    ifstream myfile ("name.in");
    while (getline(myfile, line)) {
        names.push_back(line);
    }

    scanf("%d %d %d %lf", &n, &q, &x, &loadFactor);
    // generate N keys
    for (int i = 0; i < n; i++) {
        while (true) {
            int tmp = rand() % 2000000000;
            if (sets.find(tmp) == sets.end()) {
                sets.insert(tmp);
                vec.push_back(tmp);
                break;
            }
        }
    }
    // generate Q - X keys that is not in N
    for (int i = 0; i < q - x; i++) {
        while (true) {
            int tmp = rand() % 2000000000;
            if (sets.find(tmp) == sets.end()) {
                sets.insert(tmp);
                vec3.push_back(tmp);
                break;
            }
        }
    }
    // generate X keys that is in N
    for (int i = 0; i < x; i++) {
        while (true) {
            int tmp = vec[rand() % vec.size()];
            if (sets2.find(tmp) == sets2.end()) {
                sets2.insert(tmp);
                vec2.push_back(tmp);
                break;
            }
        }
    }
    printf("%d %lf\n", n, loadFactor);
    for (int i = 0; i < vec.size(); i++) {
        int tmp = rand() % names.size();
        int tmp2 = rand() % names.size();
        printf("%d %s %s\n", vec[i], names[tmp].c_str(), names[tmp2].c_str());
    }
    printf("%d\n", q);
    for (int i = 0; i < x; i++) {
        printf("%d\n", vec2[i]);
    }
    for (int i = 0; i < q - x; i++) {
        printf("%d\n", vec3[i]);
    }
}