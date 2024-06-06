class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //initializing return array as size is not fix we take dynamic
        vector<vector<int>> rtn;
        int n = nums.size();
        //sorting elements so that we can skip same elemets easily and us two pointer technique
        sort(nums.begin(),nums.end());
        //outer loop to fix elements one by one
        for(int i =0;i<n-2;i++){
            //executing for first duplicate bcz it wil cover all triplet that could be made if we consider rest of the duplicates.
            if(i>0 && nums[i]==nums[i-1]) continue;
            int target = -nums[i];
            int j=i+1;
            int k= n-1; 
            //loop to check if any combination of remaining element + fixed element equals to sum if yes then add to rtn array
            while(j<k){
                int sum = nums[j] + nums[k];
                if(sum == target){
                    rtn.push_back({nums[i], nums[j], nums[k]});
                    //skipping same elements.
                    //again we are executing for first 
                    while(j<k && nums[j]==nums[j+1]) j++;
                    while(j<k && nums[k]==nums[k-1]) k--;
                    //if we want to execute for last identical element then it would be like
                    // while(j<k && j>i+1 && nums[j]==nums[j-1]) j++;
                    // while(j<k && k<n-1 && nums[k]==nums[k+1]) k--;
                    //we are incrementing both bcz array is sorted and we are skipping same elements so only incrementing one would be inefficient but would be correct
                    j++;
                    k--;
                }
                else if(sum>target) {
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return rtn;
    }
};
