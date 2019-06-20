/*
0 ~ 9999 までの数字をシャッフルしファイルに出力するプログラム
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 10000;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) v[i] = i;

    random_device seed_gen;
    mt19937 engine(seed_gen());
    shuffle(v.begin(), v.end(), engine);

    string fn = "shuffle_code.txt";

    ofstream writing_file(fn);

    for (int i = 0; i < n; ++i) writing_file << v[i] << endl;
}