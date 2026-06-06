/* approach :
1. get the size of the input array .
2. take totalsum of the  input array.
3. remember this formula of the  rightsum = totalsum-leftsum-num[i]
4. then take absolute value of the leftsum-rightsum for the positive  answer of teh difference.
5.then make leftsum=nums[i];
*/

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);

        int totalSum = 0;
        for (int x : nums) totalSum += x;

        int leftSum = 0;

        for (int i = 0; i < n; i++) {
            int rightSum = totalSum - leftSum - nums[i];
            answer[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }

        return answer;
    }
};
