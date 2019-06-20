/*
エラトステネスのふるいを使ったアルゴリズム
*/

#include <bits/stdc++.h>

using namespace std;

// 初期化処理
// n: 範囲 (今回は 100万)
int n = 1000000;

// 素数判定をする関数 (引数に数字と配列を取るように変更)
bool is_prime(int num, bool arr[]) {
    // arr (この場合は primes) から値を取得しそれを return する
    return arr[num - 1];
}

int main() {
    // 初期化処理 (main 関数内)
    // count: n までに含まれる素数の数
    // square_rooted_n: n の平方根
    // primes: 要素数 n の配列
    int count = 0;
    double square_rooted_n = sqrt(n);
    bool primes[n];

    // 始めの時間を記録
    clock_t start = clock();

    // 配列の初期化, すべて素数として仮定し, true とする
    for (int i = 0; i < n; ++i) primes[i] = true;

    // i を 2 から n まで 1 ずつ上げながら回す
    for (int i = 2; i <= n; ++i) {
        // 素数判定をして true なら count をインクリメント, ふるい落とし処理 (O(loglogn))
        if (is_prime(i, primes)) {
            ++count;
            // i が √n より小さいか調べる
            if (i < square_rooted_n) {
                // ふるい落とし処理
                // j を i から n まで i ずつ上げながら回す
                // primes の key (j - 1) を false に設定
                for (int j = i; j <= n; j += i) primes[j - 1] = false;
            }
        }
    }

    // 終わりの時間を記録
    clock_t end = clock();

    // 素数の合計の表示
    cout << count << endl;
    // 実行時間の表示
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
}

// 全体の処理としては計算時間 O(nloglogn) の処理となる
