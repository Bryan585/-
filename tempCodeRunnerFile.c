// 猜数字游戏的完整实现
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 题目要求的 Decision 函数：输出适当的响应
// 返回值 1 代表猜对了，0 代表没猜对
int Decision(int secret, int guess) {
    if (guess == secret) {
        printf("Excellent! You guessed the number!\n");
        return 1; 
    } else if (guess < secret) {
        printf("Too low. Try again.\n");
        return 0;
    } else {
        printf("Too high. Try again.\n");
        return 0;
    }
}

int main() {
    int secret, guess, status;
    int playAgain = 1;

    // 设置随机数种子，确保每次运行数字不同
    srand(time(NULL));

    while (playAgain) {
        // 生成 1 到 1000 之间的随机数
        secret = rand() % 1000 + 1;

        printf("\nI have a number between 1 and 1000.\n");
        printf("Can you guess my number?\n");
        printf("Please type your first guess: ");

        // 游戏内部循环
        do {
            scanf("%d", &guess);
            // 调用 Decision 函数进行判断
            status = Decision(secret, guess);
            
            if (!status) {
                printf("? "); // 如果没猜对，继续提示输入
            }
        } while (status == 0);

        // 询问是否继续
        printf("Would you like to play again (Press 1 to continue and 0 to exit)? ");
        scanf("%d", &playAgain);
    }

    printf("Thank you for playing!\n");
    return 0;
}