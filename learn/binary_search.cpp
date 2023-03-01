#include <iostream>
#include <vector>
int binary(std::vector<int>& nums, int target);
int main()
{
    std::vector<int> nums = {1,2,3,4,5,6,7,8,9};
    int res = binary(nums, 8);
    std::cout << res;
}
/* 这个版本为左闭右闭的区间，所以while循环中的left和right可以相等，如果为左闭右开区间，则不能相等否则就没有意义了。同时，在左闭右开版本中，
right的取值需要+1，因为无法取到。第三个if中right也不需要减1 */
int binary(std::vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int middle = left + ((right - left) / 2);
        if (nums[middle] == target)
        {
            return nums[middle];
        }
        else if (target > nums[middle])
        {
            left = middle + 1;
        }
        else if (target < nums[middle])
        {
            right = middle - 1;
        }
        
    }
    return -1;
    
}