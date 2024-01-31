#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int n = nums.size();
    int count = -1;
    for(int i=0; i<n ;i++){
        int j=i+1;
        while(j<n){
            if(nums[i] == val){
                if(nums[i] == nums[j]){
                    j++;
                    swap(nums[i],nums[j]);
                    count++;
                }
                else{
                    swap(nums[i],nums[j]);
                    count++;
                }
            }
            break;
        }
    }
    return count;
}

int main(){
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    
    int count = removeElement(nums,val);
    
    cout << "Expected Nums: ";
    for(int i=0; i<count; i++){
        cout << nums[i] << " " ; 
    }
}