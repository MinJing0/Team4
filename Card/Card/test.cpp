/* 預計達成效果
 * 函式回傳一個指標，而該指標存著前面3張合起來為10的組合
 * 要有一個 &變數去存有幾組組合，最後要比哪副牌好，所用的
*/

#include <iostream>
using namespace std;

#include "CardStyle.h"

int main() {
    CardStyle t;
    int cards[5] = { 3, 5, 4, 6, 2 };
    t.setCards(cards);

    int passComb[10][5];
    int arr[10][5]; // 儲存所有組合和剩下的牌
    int arrIndex = 0; // arr 索引

    std::cout << "所有可能的組合如下：" << std::endl;

    // 呼叫 generateCombinations 函數生成所有可能的組合
    t.generateCombinations(0, 0, arr, arrIndex);

    int num__comb = 0;
    for (int i = 0; i < arrIndex; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += arr[i][j];
        }
        if (sum % 10 == 0)
        {
            for (int k = 0; k < 5; ++k)
                passComb[num__comb][k] = arr[i][k];
            num__comb++;
        }
    }
    for (int i = 0; i < num__comb; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << passComb[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}