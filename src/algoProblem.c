/**
* Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    //two pointers, start of the array and finish
    int start = 0;
    int end = numsSize - 1;

    //go through the array, moving the pointers
    //swap evens with odds
    
    while (end > start){
        //first case: if we can swap
        //second case: if both values are odd
        //third case: if both values are even
        if (nums[start] % 2 != 0 && nums[end] % 2 == 0){
            //swap!
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        } else if (nums[start] % 2 != 0 && nums[end] % 2 != 0){
            //decrement end so that we can get to an even number at nums[end]
            end--;
        } else {
            //just increment start so that we can get to an odd number at nums[start]
            start++;
        }
    }
    *returnSize = numsSize;
   
    return nums;
}