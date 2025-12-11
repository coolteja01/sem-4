#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            freq[arr[i]]++;
        }
        
        vector<int> nums;
        for (auto& p : freq) {
            nums.push_back(p.first);
        }
        
        // Sort by popcount, then by value
        sort(nums.begin(), nums.end(), [](int a, int b) {
            int pa = __builtin_popcount(a);
            int pb = __builtin_popcount(b);
            if (pa != pb) return pa < pb;
            return a < b;
        });
        
        int m = nums.size();
        vector<int> dp(m, 0);
        int ans = 0;
        
        for (int i = 0; i < m; i++) {
            dp[i] = freq[nums[i]];
            for (int j = 0; j < i; j++) {
                if ((nums[j] & nums[i]) == nums[j]) {
                    dp[i] = max(dp[i], dp[j] + freq[nums[i]]);
                }
            }
            ans = max(ans, dp[i]);
        }
        
        cout << ans << endl;
    }
    return 0;
}
