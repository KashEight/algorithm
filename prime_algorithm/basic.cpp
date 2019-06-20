/*
愚直なアルゴリズム
*/

#include <bits/stdc++.h>

using namespace std;

// 初期化処理
// n: 範囲 (今回は 100万)
int n = 1000000;

// 素数判定をする関数 (O(n))
bool is_prime(int num) {
    // 2 は最初の素数なので true を返す
    if (num == 2) return true;

    // 偶数は素数ではないので false を返す
    if (num % 2 == 0) return false;

    // i を 3 から num - 1 まで 2 ずつ上げながら回す
    for (int i = 3; i < num; i += 2) {
        // num が i で割れるか調べ, 割れたら false を返す
        if (num % i == 0) return false;
    }

    return true;
}

int main() {
    // 初期化処理 (main 関数内)
    // count: n までに含まれる素数の数
    int count = 0;

    // 始めの時間を記録
    clock_t start = clock();

    // i を 2 から n まで 1 ずつ上げながら回す
    for (int i = 2; i <= n; ++i) {
        // 素数判定をして true なら count をインクリメント
        if (is_prime(i)) ++count;
    }

    // 終わりの時間を記録
    clock_t end = clock();

    // 素数の合計の表示
    cout << count << endl;
    // 実行時間の表示
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
}

// 全体の処理としては計算時間 O(n ^ 2) の処理となる
