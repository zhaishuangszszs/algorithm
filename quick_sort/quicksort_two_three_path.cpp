#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// 普通快排缺点，不能解决基本有序和重复值问题（时间复杂度为n*n）
int partition_normal(vector<int> &nums, int low, int high) {
    int key=nums[low];
    int i=low; //i后面和i指向的元素(除了key)都为小于key,i就是枢纽位置（在最后交换后是这样的）
    for(int j=i+1;j<=high;j++){
        if(nums[j]<key){
            i++;
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[low],nums[i]);
    return i;
}

void quicksort_normal(vector<int> &nums, int low, int high) {
  if (low >= high) {
    return;
  }
  int pivot = partition_normal(nums, low, high);
  quicksort_normal(nums, low, pivot-1);
  quicksort_normal(nums, pivot+1, high);
}


// 随机快排 解决基本有序，解决不了重复值很多
int partition_random(vector<int> &nums, int low, int high){
    int index=random()%(high-low+1)+low;
    swap(nums[low],nums[index]);
    int key=nums[low];
    int i=low; //i后面和i指向的元素(除了key)都为小于key,i就是枢纽位置（在最后交换后是这样的）
    for(int j=i+1;j<=high;j++){
        if(nums[j]<key){
            i++;
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[low],nums[i]);
    return i;
}

void quicksort_random(vector<int> &nums, int low, int high){
    if (low >= high) {
        return;
    }
    int pivot = partition_random(nums, low, high);
    quicksort_random(nums, low, pivot-1);
    quicksort_random(nums, pivot+1, high);
}


// 双路快排 可以解决重复问题因为i++,j--尽可能保证i,j在中间位置
int partiton_twopath(vector<int> &nums, int low, int high){
    int index=random()%(high-low+1)+low;
    swap(nums[low],nums[index]);
    int key=nums[low];

    int i=low+1; // i后面指向小于key的元素,i指向<v部分的下一个元素
    int j=high; // j后面元素指向大与key的元素,用j指向>v部分的前一个元素
    while(true){
        // 从j开始向前遍历，如果遍历的元素e>v，则继续向前遍历，直到遍历的元素e<=v，则停止遍历
        while(j>=low+1&&nums[j]>key){
            j--;
        }
        // 从i开始向后遍历，如果遍历的元素e<v，则继续向后遍历，直到遍历的元素e>=v，则停止遍历
        while(i<=high&&nums[i]<key){
            i++;
        }
        if(i>=j){
            //此时i=j说明nums[i]=key
            //i>j则nums[j]一定<key
            break;
        }
        swap(nums[i],nums[j]);
        i++;
        j--;
    }
    swap(nums[low],nums[j]);
    return j;

}
void quiksort_twopath(vector<int> &nums, int low, int high){
    if (low >= high) {
        return;
    }
    int pivot = partiton_twopath(nums, low, high);
    quiksort_twopath(nums, low, pivot-1);
    quiksort_twopath(nums, pivot+1, high);
}


//三路快排
pair<int,int> partiton_threepath(vector<int> &nums, int low, int high){
    int index=random()%(high-low+1)+low;
    swap(nums[low],nums[index]);
    int key=nums[low];

    int l=low; //l指向小于key的第一个元素
    int eq=low+1; //eq指向等于key的前一个元素
    int gt=high; //gt指向大key的前一个元素
    // 从eq扫描到gt停止
    while(eq<=gt){
        if(nums[eq]==key){
            eq++;
        }
        else if(nums[eq]<key){
            l++;
            swap(nums[eq],nums[l]);
            eq++;//有无都行
        }
        else if(nums[eq]>key){
            swap(nums[gt],nums[eq]);
            gt--;
        }
    }
    swap(nums[low],nums[l]);
    // 交换后l指向key,也就是等于key的第一个
    return {l,gt};
}
void quicksort_threepath(vector<int> &nums, int low, int high){
    if(low>=high){
        return;
    }
    pair<int,int> pivot = partiton_threepath(nums, low, high);
    quicksort_threepath(nums, low, pivot.first-1);
    quicksort_threepath(nums, pivot.second+1, high);
}
int main() { 
    vector<int> nums = {3, 4, 7, 2, 6, 1, 0}; 
    vector<int> nums2={2,2,2,2,2,2,2,2};
    // quicksort_normal(nums, 0, nums.size()-1);
    // quicksort_random(nums, 0, nums.size()-1);
    // quiksort_twopath(nums, 0, nums.size()-1);
    quicksort_threepath(nums, 0, nums.size()-1);
    quicksort_threepath(nums2, 0, nums2.size()-1);
    for(auto val:nums){
        std::cout<<val<<' ';
    }
    std::cout<<std::endl;
    
    for(auto val:nums2){
        std::cout<<val<<' ';
    }
    std::cout<<std::endl;
    return 0;
}