#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums,int n) {
    int j = 0;
    for(int i = 0; i<n-1; i++){
        if(nums[i] != nums[i+1]){
            nums[j++] = nums[i];
        }
    }
    nums[j++] = nums[n-1];
    return j;
}

int main()
{
    vector<int> nums = {0,0,0,1,1,2,3,4,4,5};
    int n = nums.size();
    n = removeDuplicates(nums,n);
    for(int i=0 ; i<n; i++){
        cout << nums[i] << " ";
    }
    return 0;
}