// 打家劫舍 https://leetcode.cn/problems/house-robber/description/
//递推
/*
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int f[105];
        f[n] = f[n+1] = 0;
        for(int i = n-1; i >= 0; i--) {
            f[i] = max(f[i+1], f[i+2]+nums[i]);
        }
        return f[0];
    }
};
 */

// 记忆化
/*
int mem[105];
class Solution {
public:
    int dfs(int x, int n, vector<int>& nums) {
        if(mem[x] != -1) return mem[x];
        if(x >= n) {
            mem[x] = 0;
            return 0;
        } else {
            mem[x] = max(dfs(x+2, n, nums) + nums[x], dfs(x+1, n, nums));
            return mem[x];
        }

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(mem, -1, sizeof mem);
        return dfs(0, n, nums);
    }
};
 */