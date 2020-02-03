class Solution {
public:

    int minSubArrayLen(int s, vector<int>& nums) {
    //     sort(nums.begin(), nums.end(), greater <>());

        int templength=0;
       for(int i=0;i<nums.size();i++){
           int sum = 0;
            int sum_count=0;
          for(int j=i;j<nums.size();j++){
              sum+=nums[j];
              sum_count++;
           if(sum>=s){
               if(i==0){
                   templength = sum_count;
               }
               if(sum_count<templength && i>0){
                   templength = sum_count;
               }
               break;
           }
       }
       }
     return templength;
    }
};
