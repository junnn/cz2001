#include <vector>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>

using namespace std;
long long c = 0;
long long totalc = 0;
long long maxc = 0;
long long minc = 1000000000000000000;

long long t;
long long totalt = 0;
long long maxt = 0;
long long mint = 1000000000000000000;

struct Node {
    long long key;
    string value;

    Node(long long x, string y) {
        key = x;
        value = y;
    }
};

class HashMapLinearProbing {
    public:
        vector<Node*> hashMap;

        int findHashKey(long long key) {
            int mapSize = hashMap.size();
            int initialHashedKey = key % mapSize;
            int hashedKey = initialHashedKey;
            int ans = -1;
            while (++c && hashMap[hashedKey] != NULL) {
                if (hashMap[hashedKey]->key == key) {
                    ans = hashedKey;
                    break;
                }
                hashedKey = (hashedKey + 1) % mapSize;
                if (hashedKey == initialHashedKey) break;
            }
            return ans;
        }

        int findEmptyHashKey(long long key) {
            int mapSize = hashMap.size();
            int hashedKey = key % mapSize;
            while (++c && hashMap[hashedKey] != NULL) {
                hashedKey = (hashedKey + 1) % mapSize;
            }
            return hashedKey;
        }

        void insert(long long key, Node* data) {
            hashMap[findEmptyHashKey(key)] = data;
        }

        Node* find (long long key) {
            int hashKey = findHashKey(key);
            if (hashKey != -1)
                return hashMap[hashKey];
            return NULL;
        }

        HashMapLinearProbing(int n) : hashMap(n + 1) { }
};

int main() {
    int n = 100000, q, x;
    long long key;
    char employeeName[1000];
    scanf("%d", &x);
    HashMapLinearProbing linearhashmap(ceil((double)n));
    for (int i = 0; i < x; i++) {
        scanf("%lld ", &key);
        fgets(employeeName, 1000, stdin);
        employeeName[strlen(employeeName) - 1] = '\0';  // remove endline
        string tmpString(employeeName);

        Node* tmp = new Node(key, tmpString);
        linearhashmap.insert(tmp->key, tmp);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%lld", &key);
        c = 0;
        t = clock();
        Node* ret = linearhashmap.find(key);
        t = clock() - t;
        totalt += t;
        maxt = max(maxt, t);
        mint = min(mint, t);
        totalc += c;
        maxc = max(maxc, c);
        minc = min(minc, c);

        // if (ret) {
        //     printf("%s\n", (ret->value).c_str());
        // } else {
        //     printf("Not found\n");
        // }
    }

    printf("total comparison: %lld\n", totalc);
    printf("average comparison: %lf\n", (double)totalc / q);
    printf("max comparison: %lld\n", maxc);
    printf("min comparison: %lld\n", minc);
    printf("total CPU time: %lld microsecond\n", totalt);
    printf("average CPU time: %lf microsecond\n", (double)(totalt) / q);
    printf("max CPU time: %lld microsecond\n", maxt);
    printf("min CPU time: %lld microsecond\n", mint);
}
