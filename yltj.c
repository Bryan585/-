#include <stdio.h>
#include <string.h> // 必须引入，用于处理字符串比较和拷贝

int main() {
    char names[3][20]; // 3个学生的姓名托盘，每个最长19字符
    char temp[20];     // 用于交换位置的临时中转托盘
    int i, j;

    // 1. 获取输入
    for (i = 0; i < 3; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", names[i]);
    }

    // 2. 冒泡排序法：按字母顺序排列
    for (i = 0; i < 2; i++) {
        for (j = i + 1; j < 3; j++) {
            // 如果 names[i] 的字母顺序比 names[j] 靠后（结果 > 0）
            if (strcmp(names[i], names[j]) > 0) {
                // 交换这两个名字的位置
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    // 3. 打印排序后的结果
    printf("\nNames in alphabetical order:\n");
    for (i = 0; i < 3; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}