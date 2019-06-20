/*
クイックソート
*/

#include <bits/stdc++.h>

using namespace std;

// 初期化処理
// n: 配列の大きさ (今回は 1万)
int n = 10000;

// クイックソート実行関数
void quick_sort(int arr[], int left, int right) {
    // right と left の差が 1 の場合 return する
    if (right - left == 1) return;
    // mid の計算 (この場合はないが, int のオーバーフローも考えて (left + right) / 2 を使わずに求める)
    int mid = left + (right - left) / 2;
    // pivot を mid として選択
    int pivot = arr[mid];

    // pivot を右端にする (pivot 未満/以上の選別を楽にするため)
    swap(arr[mid], arr[right - 1]);

    // i を left とする
    int i = left;
    // 選別処理
    for (int j = left; j < right; ++j) {
        // 現在の値が pivot より小さい場合
        if (arr[j] < pivot) {
            // 現在の値を arr[i] (i は left からの位置) と swap する
            swap(arr[i], arr[j]);
            // i をインクリメント
            ++i;
        }
    }

    // pivot を arr[i] と swap することで選別を完了させる
    swap(arr[i], arr[right - 1]);

    // 再帰してソートを完了させる
    quick_sort(arr, left, i);
    quick_sort(arr, i, right);
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

    // クイックソートの実行
    quick_sort(ex_arr, 0, n);

    // 終わりの時間を記録
    clock_t end = clock();

    // テスト用
    for (int i = 0; i < n; ++i) assert(i == ex_arr[i]);

    // 実行時間の表示
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
}

// 平均計算時間は O(nlogn), 最悪計算時間は O(n ^ 2)
