#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // dp[i] represents the expected number of days to eat i apples
    vector<double> dp(n + 1, 0.0);
    
    // Base case: to eat 0 apples, it takes 0 days
    dp[0] = 0.0;
    
    // Fill the dp array
    for (int i = 1; i <= n; i++) {
        // When there are i apples left, the person eats k apples with probability 1/i for k = 1,2,...,i
        // So the expected days to eat i apples is 1 (for the current day) plus the average of dp[i-k] for k=1 to i
        double sum = 0.0;
        for (int k = 1; k <= i; k++) {
            sum += dp[i - k];
        }
        dp[i] = 1.0 + sum / i;
    }
    
    // Output the expected days to eat m apples
    cout << fixed << setprecision(2) << dp[m] << endl;
    
    return 0;
}