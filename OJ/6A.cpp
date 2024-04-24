#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    // 计算相邻元素之差的最小值
    int minDifference = numbers[n - 1] - numbers[0];
    for (int i = 0; i < n - k + 1; ++i) {
        int currentDifference = numbers[i + k - 1] - numbers[i];
        minDifference = min(minDifference, currentDifference);
    }

    cout << minDifference << endl;

    return 0;
}

