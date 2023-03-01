#include <iostream>
int main()
{
    // 冒泡排序的实现
    int arr[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    // 冒泡排序需要确定轮次和每轮比较的次数
    // 总轮次=数组大小-1
    // 每轮比较的次数=当前数组大小-1
    int i = 0;
    int j = 0;
    int curlen = 9;
    int temp = 0;
    for (i = 0; i < 9 - 1; i++) //i代表的是当前轮数
    {
        for (j = 0; j < curlen - 1; j++) //这里的curlen - 1可以使用9 - i - 1来代替，因为i可以代表第几轮比较，这个式子正好和比较次数相等
        {

            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        curlen--;
    }
    
    for (i = 0; i < 9; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}