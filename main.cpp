#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // We want to eat m apples, so we stop when we have n-m or fewer apples left
    int target = n - m;
    
    // dp[i] represents the expected number of days to eat m apples when we have i apples remaining
    // If i <= target, we've already eaten at least m apples, so dp[i] = 0
    vector<double> dp(n + 1, 0.0);
    
    // For i > target, we need to calculate the expected days
    for (int i = target + 1; i <= n; i++) {
        // When we have i apples, we eat k apples with probability 1/i for k=1,2,...,i
        // After eating k apples, we have i-k apples left
        // If i-k <= target, we're done, so additional days = 0
        // Otherwise, we need dp[i-k] more days
        double sum = 0.0;
        for (int k = 1; k <= i; k++) {
            int remaining = i - k;
            if (remaining > target) {
                sum += dp[remaining];
            }
            // If remaining <= target, we're done, so add 0
        }
        dp[i] = 1.0 + sum / i;
    }
    
    // We start with n apples, so answer is dp[n]
    cout << fixed << setprecision(2) << dp[n] << endl;
    
    return 0;
}