#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
long long c = 0;

struct Node {
    int key;
    string value;

    Node(int x, string y) {
        key = x;
        value = y;
    }
};

class HashMapLinearProbing {
    public:
        vector<Node*> hashMap;

        int findHashKey(int key) {
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

        int findEmptyHashKey(int key) {
            int mapSize = hashMap.size();
            int hashedKey = key % mapSize;
            while (++c && hashMap[hashedKey] != NULL) {
                hashedKey = (hashedKey + 1) % mapSize;
            }
            return hashedKey;
        }

        void insert(int key, Node* data) {
            hashMap[findEmptyHashKey(key)] = data;
        }

        Node* find (int key) {
            int hashKey = findHashKey(key);
            if (hashKey != -1)
                return hashMap[findHashKey(key)];
            return NULL;
        }

        HashMapLinearProbing(int n) : hashMap(n + 1) { }
};

int main() {
    clock_t t;
    t = clock();

    int n, key, q;
    double multiplierLoadFactor;
    char employeeName[1000];
    scanf("%d %lf", &n, &multiplierLoadFactor);
    HashMapLinearProbing linearhashmap(ceil(n / multiplierLoadFactor));
    for (int i = 0; i < n; i++) {
        scanf("%d ", &key);
        fgets(employeeName, 1000, stdin);
        string tmpString(employeeName);

        Node* tmp = new Node(key, tmpString);
        linearhashmap.insert(tmp->key, tmp);
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &key);
        Node* ret = linearhashmap.find(key);
        // if (ret) {
        //     printf("%s\n", (ret->value).c_str());
        // } else {
        //     printf("Not found\n");
        // }
    }

    t = clock() - t;
    printf("cpu time: %lf\n", ((double)t)/CLOCKS_PER_SEC);
    printf("comparison: %lld\n", c);
}
