// 习题7.1
// 在有序表ST中折半查找其关键字等于key的数据元素，若查找成功，返回k所在位置，查找失败返回0

// 注: a[0]闲置不用
int BinSearch_Cur(int a[], int key, int low, int high) {
    if (low > high)
        return 0;                                       // 查找不到时返回0

    if (low <= high)                                    // low和high分别是有序表的下界和上界
    {
        int mid = (low + high) / 2;                     // mid取值为low和high的中间值
        if (a[mid] == key)
            return mid + 1;                             // 查找到返回该位置
        else if (key < a[mid])
            return BinSearch_Cur(a, key, low, mid - 1);    // 对左子表递归查找
        else
            return BinSearch_Cur(a, key, mid + 1, high);    // 对右子表递归查找
    }
}