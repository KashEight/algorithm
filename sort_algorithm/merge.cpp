/*
マージソート
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

// 初期化処理
// n: 配列の大きさ (今回は 1万)
// INF: 足してもオーバーフローしないような高い値
int n = 10000;
const ll INF = 1LL << 60;

// マージソート実行関数
void merge_sort(int arr[], int left, int right) {
    // right と left の差が 1 の場合 return する
    if (right - left == 1) return;
    // mid の計算 (この場合はないが, int のオーバーフローも考えて (left + right) / 2 を使わずに求める)
    int mid = left + (right - left) / 2;

    // mid から左を再帰でソートさせる
    merge_sort(arr, left, mid);

    // mid から右を再帰でソートさせる
    merge_sort(arr, mid, right);

    // mid からの要素数を一時変数として保存
    // n1: 左側, n2: 右側
    int n1 = mid - left;
    int n2 = right - mid;

    // 左側, 右側のソート結果を格納する配列の宣言 (それぞれ 1 個余分に宣言)
    ll L[n1 + 1], R[n2 + 1];

    // 配列の初期化
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[mid + i];

    // n1, n2 番目を INF にする
    L[n1] = INF;
    R[n2] = INF;

    // 左側の配列の index と右側の配列の index となる変数の宣言, 初期化
    int L_index = 0, R_index = 0;

    // マージ処理
    for (int i = left; i < right; ++i) {
        // 左側と右側で大小比較
        if (L[L_index] <= R[R_index]) {
            // 左側の方が大きい場合
            arr[i] = L[L_index];
            // L_index をインクリメント (L_index = n1 の場合 INF になるので問題なし)
            ++L_index;
        } else {
            // 右側の方が大きい場合
            arr[i] = R[R_index];
            // R_index をインクリメント (R_index = n2 の場合 INF になるので問題なし)
            ++R_index;
        }
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

    // マージソートの実行
    merge_sort(ex_arr, 0, n);

    // 終わりの時間を記録
    clock_t end = clock();

    // テスト用
    for (int i = 0; i < n; ++i) assert(i == ex_arr[i]);

    // 実行時間の表示
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
}

// 平均計算時間は O(nlogn), 最悪計算時間は O(nlogn)
