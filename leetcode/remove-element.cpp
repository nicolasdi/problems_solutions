class Solution {
public:
  void swap(vector<int>& nums, int i, int  j){
    int aux = nums[i];
    nums[i] = nums[j];
    nums[j] = aux;
  }

  int removeElement(vector<int>& nums, int val) {
    int j = nums.size() - 1;
    while(j >= 0 && nums[j] == val){
      j--;
    }

    int i = 0;
    while(i <= j){
      if(nums[i] == val){
        swap(nums, i, j);
        j--;
        continue;
      }

      i++;
    }

    return j + 1;
  }
};
