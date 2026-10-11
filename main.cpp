#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // dp[eaten] represents the expected number of additional days needed to eat m apples,
    // given that we have already eaten 'eaten' apples
    vector<double> dp(m + 1, 0.0);
    
    // Base case: if we have already eaten m apples, we need 0 more days
    dp[m] = 0.0;
    
    // Fill the dp array backwards from m-1 down to 0
    for (int eaten = m - 1; eaten >= 0; eaten--) {
        // Current number of apples remaining
        int remaining = n - eaten;
        
        // We can eat k apples with probability 1/remaining for k = 1,2,...,remaining
        // But we only need to consider cases where we don't reach m apples yet
        // If we eat k apples and eaten + k >= m, we reach our goal in 1 day (so no additional days)
        // So we only sum over k from 1 to min(remaining, m - eaten - 1)
        int max_k = min(remaining, m - eaten - 1);
        double sum = 0.0;
        for (int k = 1; k <= max_k; k++) {
            sum += dp[eaten + k];
        }
        
        // Expected days = 1 (current day) + average of additional days needed
        dp[eaten] = 1.0 + sum / remaining;
    }
    
    // Output the expected days to eat m apples starting from 0 eaten
    cout << fixed << setprecision(2) << dp[0] << endl;
    
    return 0;
}