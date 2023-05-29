#include <iostream>
using namespace std;

#include "CardStyle.h"

CardStyle::CardStyle()
{
    combinationSize = 3;
    MAX_COMBINATIONS = 10;
    haveFinal = 0;
}

int CardStyle::getCombinationSize() const
{
    return combinationSize;
}

void CardStyle::setCards(double cards[])
{
    for(int i = 0; i < 5; ++i)
        this->cards[i] = cards[i];
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
    for(int i = 0; i < 5; ++i)
        if(arr[0][i] < 11)
            return;
    for(int i = 0; i < 5; ++i)
        final[i] = arr[0][i];
    haveFinal = 1;
    cStyle = 4;
}

void CardStyle::checkTwo()
{
    double passComb[10][5];
    int num__comb = 0;
    for (int i = 0; i < 10; i++) 
    {
        int sum = 0;
        int sum2 = 0;
        for (int j = 0; j < 3; j++) 
        {
            if(arr[i][j] > 10)
            {
                sum += 10;
                continue;
            }
            sum += arr[i][j];
        }
        for(int j = 3; j < 5; j++)
        {
            if(arr[i][j] > 10)
            {
                sum2 += 10;
                continue;
            }
            sum2 += arr[i][j];
        }
        if (sum % 10 == 0 && sum2 % 10 == 0)
        {
            for(int j = 0; j < 5; j++)
                final[j] = arr[i][j];
            haveFinal = 1;
            cStyle = 3;
        }
    }
}

void CardStyle::checkOne()
{
    double passComb[10][5];
    int num__comb = 0;

    for (int i = 0; i < 10; i++) 
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            if(arr[i][j] > 10)
            {
                sum += 10;
                continue;
            }
            sum += arr[i][j];
        }
        if (sum % 10 == 0)
        {
            for (int k = 0; k < 5; ++k)
                passComb[num__comb][k] = arr[i][k];
            num__comb++;
        }
    }

    // 代表無妞
    if(num__comb == 0)
        return;

    if(num__comb > 1)
    {
        int maxi = 0;
        for(int i = 1; i < num__comb; ++i)
        {
            if(int(passComb[i][3] + passComb[i][4])%10 > int(passComb[maxi][3] + passComb[maxi][4])%10)
                maxi = i;
        }
        for(int i = 0; i < 5; ++i)
            final[i] = passComb[maxi][i];
        haveFinal = 1;
        cStyle = 2;
        return;
    }
    for(int i = 0; i < 5; ++i)
        final[i] = passComb[0][i];
    haveFinal = 1;
    cStyle = 2;
}

void CardStyle::checkPoor()
{
    /*
        直接存進去，不管無妞還是烏龍的牌組都是一樣，
        最後再判斷是無妞還是烏龍，這種方法可以提升效率
    */ 
    for(int i = 0; i < 5; ++i)
        final[i] = arr[0][i];
    for(int i = 0; i < 5; i++)
    {
        if(arr[0][i] > 10)
        {
            haveFinal = 1;
            cStyle = 1;
        }
    }
    if(!haveFinal)
        cStyle = 0;
}

void CardStyle::checkStyle()
{
    checkSuper();
    if(!haveFinal)
    {
        checkTwo();
        if(!haveFinal)
        {
            checkOne();
            if(!haveFinal)
                checkPoor();
        }
        
    }
}

double* CardStyle::getFinal()
{
    return final;
}

int CardStyle::getCstyle()
{
    return cStyle;
}

void CardStyle::print()
{
    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 5; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << "------------------------------\n";
    for(int i = 0; i < 5; ++i)
        cout << final[i] << " ";
    cout << endl;
    cout << "cStyle: " << cStyle << endl;
}
