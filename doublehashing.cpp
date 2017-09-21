/*
This file is using input generated from generatedata.cpp and will output the statistics of given input

You can un-comment the printf after each search to test the hashmap
*/
#include <vector>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>

using namespace std;
// c is comparison count
long long c = 0;
long long totalc = 0;
long long maxc = 0;
long long minc = 1000000000000000000;

// t is time count
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

class HashMapDoubleHashing {
    public:
        vector<Node*> hashMap;
        int mapSize;

        int hash2(long long key) {
            /*
                the mod is (mapSize - 1) because (mapSize - 1) is coprime with mapSize
                + 1 is because so that the hash2 will be > 0
            */
            return 1 + ((key / mapSize) % (mapSize - 1));
        }

        int findHashKey(long long key) {
            int initialHashedKey = key % mapSize;
            int hashedKey = initialHashedKey;
            int d = hash2(key);
            int ans = -1; // -1 means not found
            while (++c && hashMap[hashedKey] != NULL) {
                if (hashMap[hashedKey]->key == key) {
                    ans = hashedKey;
                    break;
                }
                hashedKey = (hashedKey + d) % mapSize;
                if (hashedKey == initialHashedKey) break;
            }
            return ans;
        }

        int findEmptyHashKey(long long key) {
            int hashedKey = key % mapSize;
            int d = hash2(key);
            while (++c && hashMap[hashedKey] != NULL) {
                hashedKey = (hashedKey + d) % mapSize;
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
        // +1 here is because array in c++ is zero based
        HashMapDoubleHashing(int n) : hashMap(n + 1), mapSize(n) { }
};

int findPrime(int n) {
    /*
    sieve of eratosthenes to count the next prime in O(N)
    only search until 2 * n, is because Bertrand's postulate
    */
    vector<bool> arr(2 * n, false);

    for (int i = 2; i <= sqrt(2 * n); i ++) {
        if (arr[i] == false) {
            int j = i * i;
            while (j < 2 * n) {
                arr[j] = true;
                j += i;
            }
        }
    }
    for (int i = n; i < 2 * n; i++)
        if (arr[i] == false) return i;

    return -1;
}

int main() {
    int n = 100000, q, dataSize;
    long long key;
    char employeeName[1000];
    scanf("%d", &dataSize);
    int nearestLargerPrime = findPrime(n);
    HashMapDoubleHashing doublehashmap(nearestLargerPrime);
    for (int i = 0; i < dataSize; i++) {
        scanf("%lld ", &key);
        fgets(employeeName, 1000, stdin);
        employeeName[strlen(employeeName) - 1] = '\0';  // remove endline
        string tmpString(employeeName);

        Node* tmp = new Node(key, tmpString);
        doublehashmap.insert(tmp->key, tmp);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%lld", &key);
        c = 0;
        t = clock();
        Node* ret = doublehashmap.find(key);
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
