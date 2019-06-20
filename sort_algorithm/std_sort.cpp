/*
C++ の STL にある sort 関数
*/

#include <bits/stdc++.h>

using namespace std;

// 初期化処理
// n: 配列の大きさ (今回は 1万)
int n = 10000;

int main() {
    // 配列の宣言
    int ex_arr[n];

    // ifstream で shuffule_code.txt を読み込む
    ifstream input_file;
    input_file.open("shuffle_code.txt");

    // dist から直接実行した場合の処理
    if (!input_file) input_file.open("../shuffle_code.txt");

    // shuffule_code.txt からデータ読み込んで配列に格納
    for (int i = 0; i < n; ++i) input_file >> ex_arr[i];

    // ファイルを閉じる
    input_file.close();

    // 始めの時間を記録
    clock_t start = clock();

    // ソートの実行
    sort(ex_arr, ex_arr + n);

    // 終わりの時間を記録
    clock_t end = clock();

    // テスト用
    for (int i = 0; i < n; ++i) assert(i == ex_arr[i]);

    // 実行時間の表示
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
}

// 平均計算時間は O(nlogn), 最悪計算時間は O(nlogn)
