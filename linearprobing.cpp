#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;
int c = 0;

struct Node {
    int key;
    int value;

    Node(int x, int y) {
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
            return hashedKey;
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

    int n, x, y, q;
    scanf("%d", &n);
    HashMapLinearProbing linearhashmap(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        Node* tmp = new Node(x, y);
        linearhashmap.insert(tmp->key, tmp);
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &x);
        Node* ret = linearhashmap.find(x);
        // if (ret) {
        //     printf("%d\n", ret->value);
        // } else {
        //     printf("Not found\n");
        // }
    }

    t = clock() - t;
    printf("cpu time: %lf\n", ((double)t)/CLOCKS_PER_SEC);
    printf("comparison: %d\n", c);
}
