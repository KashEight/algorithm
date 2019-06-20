/*
選択ソート
*/

#include <bits/stdc++.h>

using namespace std;

// 初期化処理
// n: 配列の大きさ (今回は 1万)
int n = 10000;

// 選択ソート実行関数
void selection_sort(int arr[]) {
    // i を 0 から n - 1 まで 1 ずつ上げながら回す
    for (int i = 0; i < n; ++i) {
        // 最小値がある index を最初は i とする (i までは既にソート済み)
        int min_index = i;
        // j を i から n - 1 まで 1 ずつ上げながら回す
        for (int j = i; j < n; ++j) {
            // 現在の arr[min_index] より小さい arr[j] があったら min_index を更新
            if (arr[j] < arr[min_index]) min_index = j;
        }
        // arr[i] と arr[min_index] を swap し小さい値が最初に来るようにする
        swap(arr[i], arr[min_index]);
    }
}

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

    // 選択ソートの実行
    selection_sort(ex_arr);

    // 終わりの時間を記録
    clock_t end = clock();

    // テスト用
    for (int i = 0; i < n; ++i) assert(i == ex_arr[i]);

    // 実行時間の表示
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
}

// 平均計算時間は O(n ^ 2), 最悪計算時間は O(n ^ 2)
