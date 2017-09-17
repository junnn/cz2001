/*
Input data:
The input is N, Q, X, where:
- N is the number of the data you want to insert
- Q is the number of search query to perform
- X is the number of search query that is found in the inserted data
*/
#include <iostream>
#include <cstdio>
#include <unordered_set>
#include <vector>

using namespace std;
int n, q, x;
unordered_set<int> sets, sets2;
vector<int> vec, vec2, vec3;

int main () {
    srand (time(NULL));
    scanf("%d %d %d", &n, &q, &x);
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
    printf("%d\n", n);
    for (int i = 0; i < vec.size(); i++) {
        printf("%d %d\n", vec[i], i + 1);
    }
    printf("%d\n", q);
    for (int i = 0; i < x; i++) {
        printf("%d\n", vec2[i]);
    }
    for (int i = 0; i < q - x; i++) {
        printf("%d\n", vec3[i]);
    }
}