/*
挿入ソート
*/

#include <bits/stdc++.h>

using namespace std;

// 初期化処理
// n: 配列の大きさ (今回は 1万)
int n = 10000;

// 挿入ソート実行関数
void insertion_sort(int arr[]) {
    // i を 1 から n - 1 まで 1 ずつ上げながら回す
    for (int i = 1; i < n; ++i) {
        // 一時変数
        int tmp = arr[i];
        int j = i - 1;
        // 入れ替え
        while (j >= 0 && arr[j] > tmp) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = tmp;
    }
}

int main() {
    // 配列の宣言
    int ex_arr[n];

    // ifstream で shuffule_code.txt を読み込む
    ifstream input_file;
    input_file.open("shuffle_code.txt");

    // shuffule_code.txt からデータ読み込んで配列に格納
    for (int i = 0; i < n; ++i) input_file >> ex_arr[i];

    // ファイルを閉じる
    input_file.close();

    // 始めの時間を記録
    clock_t start = clock();

    // 挿入ソートの実行
    insertion_sort(ex_arr);

    // 終わりの時間を記録
    clock_t end = clock();

    // 実行時間の表示
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
}

// 平均計算時間は O(n ^ 2), 最悪計算時間は O(n ^ 2)