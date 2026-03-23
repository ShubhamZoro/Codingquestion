#include <vector>
using namespace std;

class Solution {
public:
    int lower_bound_binary_search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;

            if (nums[mid] > target) {
                right = mid - 1;
            } 
            else if (nums[mid] < target) {
                left = mid + 1;
            } 
            else {
                right = mid;  // move left
            }
        }

        return (!nums.empty() && nums[left] == target) ? left : -1;
    }

    int upper_bound_binary_search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2 + 1; // right bias

            if (nums[mid] > target) {
                right = mid - 1;
            } 
            else if (nums[mid] < target) {
                left = mid + 1;
            } 
            else {
                left = mid;  // move right
            }
        }

        return (!nums.empty() && nums[right] == target) ? right : -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int lower = lower_bound_binary_search(nums, target);
        int upper = upper_bound_binary_search(nums, target);
        return {lower, upper};
    }
};
