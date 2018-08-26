class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        stable_sort(nums.begin(),nums.end());
        int dup=0,len=nums.size(),ans=0;
        for(int j=0;j<nums.size()-1;j++){
            if(nums[j]==nums[j+1]){
                dup=nums[j];
                break;
            }
        }
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        int ans=len*(len+1)/2;
        ans=ans-sum+dup;
        vector<int> v;
        v.push_back(dup);
        v.push_back(ans);
        return v;
    }
};
