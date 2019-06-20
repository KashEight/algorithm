/*
バブルソート
*/

#include <bits/stdc++.h>

using namespace std;

// 初期化処理
// n: 配列の大きさ (今回は 1万)
int n = 10000;

// バブルソート実行関数
void bubble_sort(int arr[]) {
    // i を 0 から n - 1 まで 1 ずつ上げながら回す
    for (int i = 0; i < n; ++i) {
        // j を n - 1 から i + 1 まで 1 ずつ減らしながら回す
        // i まで整列済みなので i + 1 まで回せば良い
        for (int j = n - 1; j > i; --j) {
            // j - 1 番目の要素 が j 番目の要素より大きい場合 swap する
            if (arr[j - 1] > arr[j]) swap(arr[j - 1], arr[j]);
        }
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

    // バブルソートの実行
    bubble_sort(ex_arr);

    // 終わりの時間を記録
    clock_t end = clock();

    // 実行時間の表示
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
}

// 平均計算時間は O(n ^ 2), 最悪計算時間は O(n ^ 2)
