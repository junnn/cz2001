#include <vector>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>

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

class HashMapDoubleHashing {
    public:
        vector<Node*> hashMap;
        int mapSize;

        int hash2(int key) {
            return 1 + ((key / mapSize) % (mapSize - 1));
        }

        int findHashKey(int key) {
            int initialHashedKey = key % mapSize;
            int hashedKey = initialHashedKey;
            int d = hash2(key);
            int ans = -1;
            while (++c && hashMap[hashedKey] != NULL) {
                if (hashMap[hashedKey]->key == key) {
                    ans = hashedKey;
                    break;
                }
                hashedKey = (hashedKey + d) % mapSize;
                if (hashedKey == initialHashedKey) break;
            }
            return hashedKey;
        }

        int findEmptyHashKey(int key) {
            int hashedKey = key % mapSize;
            int d = hash2(key);
            while (++c && hashMap[hashedKey] != NULL) {
                hashedKey = (hashedKey + d) % mapSize;
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

        HashMapDoubleHashing(int n) : hashMap(n + 1), mapSize(n) { }
};

int findPrime(int n) {
    """
    sieve of eratosthenes to count the next prime in O(N)
    """
    bool arr[(2 * n) + 5];
    memset(arr, false, sizeof(arr));

    for (int i = 2; i <= sqrt(2 * n); i ++) {
        if (arr[i] == false) {
            int j = i * i;
            while (j < 2 * n) {
                arr[j] = true;
                j += i;
            }
        }
    }
    for (int i = n + 1; i < 2 * n; i++)
        if (arr[i] == false) return i;

    return -1;
}

int main() {
    clock_t t;
    t = clock();

    int n, x, y, q;
    scanf("%d", &n);
    int nearestLargerPrime = findPrime(n);
    HashMapDoubleHashing doublehashmap(nearestLargerPrime);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        Node* tmp = new Node(x, y);
        doublehashmap.insert(tmp->key, tmp);
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &x);
        Node* ret = doublehashmap.find(x);
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
