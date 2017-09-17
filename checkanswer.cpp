#include <cstdio>
#include <map>

using namespace std;

map<int, int> maps;

int main() {
    int n, x, y, q;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        maps[x] = y;
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &x);
        if (maps.find(x) != maps.end()) {
            printf("%d\n", maps[x]);
        } else {
            printf("Not found\n");
        }
    }
}