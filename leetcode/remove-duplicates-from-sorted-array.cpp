class Solution {
public:
  int removeDuplicates(vector<int>& nums) {

    if(nums.size() == 0){
      return 0;
    }

    if(nums.size() == 1){
      return 1;
    }


    int last_valid = 0;
    int current = 1;
    while(current < nums.size()){

      if(nums[last_valid] == nums[current]){
        current++;
        continue;
      }

      last_valid++;
      nums[last_valid] = nums[current];
      current++;
    }

    last_valid++;
    return last_valid;
  }
};
