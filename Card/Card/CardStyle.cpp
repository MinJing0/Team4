#include <iostream>
using namespace std;

#include "CardStyle.h"

CardStyle::CardStyle()
{
    cards = new double[5];
    final = new double[5];
    combinationSize = 3;
    MAX_COMBINATIONS = 10;
    buffer = new double[combinationSize];
    arrIndex = isSuper = isTwo = isOne = 0;
}

int CardStyle::getCombinationSize() const
{
    return combinationSize;
}

void CardStyle::setCards(double cards[])
{
    this->cards = cards;
}

void CardStyle::generateCombinations(int startIndex, int currentIndex)
{
    // 如果已經達到組合大小，則輸出組合
    if (currentIndex == combinationSize) {
        int currentArrIndex = arrIndex;

        // 儲存組合
        for (int i = 0; i < combinationSize; i++) {
            arr[currentArrIndex][i] = buffer[i];
        }

        // 儲存剩下的牌
        int remainingIndex = combinationSize;
        for (int i = 0; i < 5; i++) {
            bool isUsed = false;
            for (int j = 0; j < combinationSize; j++) {
                if (cards[i] == buffer[j]) {
                    isUsed = true;
                    break;
                }
            }
            if (!isUsed) {
                arr[currentArrIndex][remainingIndex] = cards[i];
                remainingIndex++;
            }
        }

        arrIndex++; // 增加 arr 索引
        return;
    }

    // 遞迴生成組合
    for (int i = startIndex; i <= 5 - combinationSize + currentIndex; i++) {
        buffer[currentIndex] = cards[i];
        generateCombinations(i + 1, currentIndex + 1);
    }
}

void CardStyle::checkSuper()
{
    for (int i = 0; i < 5; ++i)
        if (arr[0][i] < 11)
            return;
    isSuper = 1;
}

void CardStyle::print()
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 5; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    cout << "isSuper: " << isSuper << endl;
    cout << "isTwo: " << isTwo << endl;
    cout << "isOne: " << isOne << endl;
}