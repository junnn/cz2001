#include <vector>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <map>

using namespace std;

map<int, string> maps;

int main() {
    int n, x, q;
    double dummy;
    char y[1000];
    scanf("%d %lf", &n, &dummy);
    for (int i = 0; i < n; i++) {
        scanf("%d ", &x);
        gets(y);
        string tmpString(y);
        maps[x] = tmpString;
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &x);
        if (maps.find(x) != maps.end()) {
            printf("%s\n", maps[x].c_str());
        } else {
            printf("Not found\n");
        }
    }
}