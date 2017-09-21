#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

void generateList(vector<int> &result, int n) {
    set<int> sets;
    // generate N keys
    for (int i = 0; i < n; i++) {
        while (true) {
            int tmp = rand() % 2000000000;
            if (sets.find(tmp) == sets.end()) {
                sets.insert(tmp);
                result.push_back(tmp);
                break;
            }
        }
    }
}

void generateSearchExist(vector<int> &result, vector<int> &vec, int n) {
    // generate N keys that is in vec and put inside result
    if (n == vec.size()) {
        // if the size is the same, just copy it directly
        for (int i = 0; i < n; i++) {
            result.push_back(vec[i]);
        }
    } else {
        set<int> sets;
        for (int i = 0; i < n; i++) {
            while (true) {
                int tmp = vec[rand() % vec.size()];
                if (sets.find(tmp) == sets.end()) {
                    sets.insert(tmp);
                    result.push_back(tmp);
                    break;
                }
            }
        }
    }
}

void generateSearchNotExist(vector<int> &result, vector<int> &vec, int n) {
    set<int> sets;
    // generate N keys that is not found in vec and put inside result
    for (int i = 0; i < vec.size(); i++) {
        sets.insert(vec[i]);
    }
    for (int i = 0; i < n; i++) {
        while (true) {
            int tmp = rand() % 2000000000;
            if (sets.find(tmp) == sets.end()) {
                sets.insert(tmp);
                result.push_back(tmp);
                break;
            }
        }
    }
}

string intToStr (int x) {
    string tmp = "";
    while (x) {
        tmp = (char)((x % 10) + '0') + tmp;
        x /= 10;
    }
    return tmp;
}

vector<string> names;
string line;

void generatedata1() {
    vector<int> data1, searchSuccess, searchFail;
    printf("starting generate data 1: increasing data\n");
    for (int i = 1; i <= 100000; i++)
        data1.push_back(i);
    printf("generate list ok\n");
    generateSearchExist(searchSuccess, data1, 100000);
    printf("generate success ok\n");
    generateSearchNotExist(searchFail, data1, 100000);
    printf("generate unsuccessful ok\n");

    for (int i = 25; i <= 75; i += 25) {
        ofstream myfile;
        string filename = "data1_0." + intToStr(i) + "_success.in";
        printf("writing to %s\n", filename.c_str());
        myfile.open (filename);
        myfile << "100000 0." << intToStr(i) << "\n";
        for (int i = 0; i < data1.size(); i++) {
            int firstname = rand() % names.size();
            int lastname = rand() % names.size();
            myfile << data1[i] << " " << names[firstname].c_str() <<" "<< names[lastname].c_str() << endl;
        }
        myfile << "100000\n";
        for (int i = 0; i < searchSuccess.size(); i++) {
            myfile << searchSuccess[i] << endl;
        }
        myfile.close();
    }

    for (int i = 25; i <= 75; i += 25) {
        ofstream myfile;
        string filename = "data1_0." + intToStr(i) + "_unsuccessful.in";
        printf("writing to %s\n", filename.c_str());
        myfile.open (filename);
        myfile << "100000 0." << intToStr(i) << "\n";
        for (int i = 0; i < data1.size(); i++) {
            int firstname = rand() % names.size();
            int lastname = rand() % names.size();
            myfile << data1[i] << " " << names[firstname].c_str() <<" "<< names[lastname].c_str() << endl;
        }
        myfile << "100000\n";
        for (int i = 0; i < searchFail.size(); i++) {
            myfile << searchFail[i] << endl;
        }
        myfile.close();
    }
}

void generatedata2() {
    vector<int> data2, searchSuccess, searchFail;
    printf("starting generate data 2: random data\n");
    generateList(data2, 100000);
    printf("generate list ok\n");
    generateSearchExist(searchSuccess, data2, 100000);
    printf("generate success ok\n");
    generateSearchNotExist(searchFail, data2, 100000);
    printf("generate unsuccessful ok\n");

    for (int i = 25; i <= 75; i += 25) {
        ofstream myfile;
        string filename = "data2_0." + intToStr(i) + "_success.in";
        printf("writing to %s\n", filename.c_str());
        myfile.open (filename);
        myfile << "100000 0." << intToStr(i) << "\n";
        for (int i = 0; i < data2.size(); i++) {
            int firstname = rand() % names.size();
            int lastname = rand() % names.size();
            myfile << data2[i] << " " << names[firstname].c_str() <<" "<< names[lastname].c_str() << endl;
        }
        myfile << "100000\n";
        for (int i = 0; i < searchSuccess.size(); i++) {
            myfile << searchSuccess[i] << endl;
        }
        myfile.close();
    }

    for (int i = 25; i <= 75; i += 25) {
        ofstream myfile;
        string filename = "data2_0." + intToStr(i) + "_unsuccessful.in";
        printf("writing to %s\n", filename.c_str());
        myfile.open (filename);
        myfile << "100000 0." << intToStr(i) << "\n";
        for (int i = 0; i < data2.size(); i++) {
            int firstname = rand() % names.size();
            int lastname = rand() % names.size();
            myfile << data2[i] << " " << names[firstname].c_str() <<" "<< names[lastname].c_str() << endl;
        }
        myfile << "100000\n";
        for (int i = 0; i < searchFail.size(); i++) {
            myfile << searchFail[i] << endl;
        }
        myfile.close();
    }
}

void generatedata3() {
    vector<long long> data3, searchSuccess, searchFail;
    const int HASH_TABLE_SIZE = 100000;
    printf("starting generate data 3: multiple of hash table size\n");

    for (int i = 25; i <= 75; i += 25) {
        data3.clear(); searchSuccess.clear(); searchFail.clear();
        for (int j = 1; j <= 100000; j++)
            data3.push_back((long long)j * (ceil((double)HASH_TABLE_SIZE * 100 / i) + 1));
        printf("generate list ok\n");
        for (int j = 1; j <= 100000; j++)
            searchSuccess.push_back((long long)j * (ceil((double)HASH_TABLE_SIZE * 100 / i) + 1));
        printf("generate success ok\n");

        ofstream myfile;
        string filename = "data3_0." + intToStr(i) + "_success.in";
        printf("writing to %s\n", filename.c_str());
        myfile.open (filename);
        myfile << "100000 0." << intToStr(i) << "\n";
        for (int j = 0; j < data3.size(); j++) {
            int firstname = rand() % names.size();
            int lastname = rand() % names.size();
            myfile << data3[j] << " " << names[firstname].c_str() <<" "<< names[lastname].c_str() << endl;
        }
        myfile << "100000\n";
        for (int j = 0; j < searchSuccess.size(); j++) {
            myfile << searchSuccess[j] << endl;
        }
        myfile.close();
    }

    for (int i = 25; i <= 75; i += 25) {
        data3.clear(); searchSuccess.clear(); searchFail.clear();
        for (int j = 1; j <= 100000; j++)
            data3.push_back((long long)j * (ceil((double)HASH_TABLE_SIZE * 100 / i) + 1));
        printf("generate list ok\n");
        for (int j = 100001; j <= 100000 * 2; j++)
            searchFail.push_back((long long)j * (ceil((double)HASH_TABLE_SIZE * 100 / i) + 1));
        printf("generate unsuccessful ok\n");

        ofstream myfile;
        string filename = "data3_0." + intToStr(i) + "_unsuccessful.in";
        printf("writing to %s\n", filename.c_str());
        myfile.open (filename);
        myfile << "100000 0." << intToStr(i) << "\n";
        for (int j = 0; j < data3.size(); j++) {
            int firstname = rand() % names.size();
            int lastname = rand() % names.size();
            myfile << data3[j] << " " << names[firstname].c_str() <<" "<< names[lastname].c_str() << endl;
        }
        myfile << "100000\n";
        for (int j = 0; j < searchFail.size(); j++) {
            myfile << searchFail[j] << endl;
        }
        myfile.close();
    }
}

int hashString(string x) {
    int ret = 0;
    for (int i = 0; i < x.length(); i++) {
        ret += (int)x[i];
    }
    return ret;
}

int main() {
    srand (hashString("CZ2001 Group 4"));
    ifstream namefile ("name.in");
    while (getline(namefile, line)) {
        names.push_back(line);
    }
    namefile.close();

    // data 1: if the key is increasing
    generatedata1();
    // data 2: if the key is random
    generatedata2();
    // data 3: if the key is increasing in sequence of multiple of the hash table size
    generatedata3();
}