#include<vector>
#include<deque>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size()-1;
        while(low<high){
            int sum = numbers[low]+numbers[high];
            if(sum == target){
                return {low+1, high+1};
            }
            else if(sum<target){
                low++;
            }
            else high--;
        }
        return {0,0};
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        int s = nums.size();
        vector<int> order, ans;
        deque<int> reverse;
        order.push_back(nums[0]);
        reverse.push_back(nums[s-1]);
        
        for(int i =1; i<s; i++){
            order.push_back(nums[i]*order[i-1]);
            reverse.push_front(nums[s-i-1]*reverse[0]);
        }

        ans.push_back(reverse[1]);
        for(int i = 1; i<s-1; i++){
            ans.push_back(order[i-1]*reverse[i+1]);
        }
        ans.push_back(order[s-2]);

        return ans;
    }

    void sortColors(vector<int>& nums) {
        int temp;
        for(int i = 0; i<nums.size(); i++){
            for(int j = 0; j<nums.size()-i-1; j++){
                if(nums[j]<=nums[j+1]) continue;
                if(nums[j]>nums[j+1]){
                    temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
        }
    }
};

