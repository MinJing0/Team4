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

void CardStyle::setCards(Card cards[])
{
    for (int i = 0; i < 5; ++i)
        this->cards[i] = cards[i];
}

void CardStyle::generateCombinations()
{
    // 暴力解，簡單，「快速」最佳演算法，又不燒腦，讚！
    arr[0][0] = cards[0];
    arr[0][1] = cards[1];
    arr[0][2] = cards[2];
    arr[0][3] = cards[3];
    arr[0][4] = cards[4];

    arr[1][0] = cards[0];
    arr[1][1] = cards[1];
    arr[1][2] = cards[3];
    arr[1][3] = cards[2];
    arr[1][4] = cards[4];

    arr[2][0] = cards[0];
    arr[2][1] = cards[1];
    arr[2][2] = cards[4];
    arr[2][3] = cards[2];
    arr[2][4] = cards[3];

    arr[3][0] = cards[0];
    arr[3][1] = cards[2];
    arr[3][2] = cards[3];
    arr[3][3] = cards[1];
    arr[3][4] = cards[4];

    arr[4][0] = cards[4];
    arr[4][1] = cards[0];
    arr[4][2] = cards[2];
    arr[4][3] = cards[3];
    arr[4][4] = cards[1];

    arr[5][0] = cards[0];
    arr[5][1] = cards[3];
    arr[5][2] = cards[4];
    arr[5][3] = cards[1];
    arr[5][4] = cards[2];

    arr[6][0] = cards[3];
    arr[6][1] = cards[1];
    arr[6][2] = cards[2];
    arr[6][3] = cards[0];
    arr[6][4] = cards[4];

    arr[7][0] = cards[4];
    arr[7][1] = cards[1];
    arr[7][2] = cards[2];
    arr[7][3] = cards[3];
    arr[7][4] = cards[0];

    arr[8][0] = cards[4];
    arr[8][1] = cards[1];
    arr[8][2] = cards[3];
    arr[8][3] = cards[0];
    arr[8][4] = cards[2];

    arr[9][0] = cards[3];
    arr[9][1] = cards[4];
    arr[9][2] = cards[2];
    arr[9][3] = cards[0];
    arr[9][4] = cards[1];
}

void CardStyle::checkSuper()
{
    for (int i = 0; i < 5; ++i)
        if (arr[0][i].getCard() < 11)
            return;
    for (int i = 0; i < 5; ++i)
        final[i] = arr[0][i];
    haveFinal = 1;
    cStyle = 4;
}

void CardStyle::checkTwo()
{
    Card passComb[10][5];
    int num__comb = 0;
    for (int i = 0; i < 10; i++)
    {
        int sum = 0;
        int sum2 = 0;
        for (int j = 0; j < 3; j++)
        {
            if (int(arr[i][j].getCard()) > 10)
            {
                sum += 10;
                continue;
            }
            sum += arr[i][j].getCard();
        }
        for (int j = 3; j < 5; j++)
        {
            if (int(arr[i][j].getCard()) > 10)
            {
                sum2 += 10;
                continue;
            }
            sum2 += arr[i][j].getCard();
        }
        if (sum % 10 == 0 && sum2 % 10 == 0)
        {
            for (int j = 0; j < 5; j++)
                final[j] = arr[i][j];
            haveFinal = 1;
            cStyle = 3;
        }
    }
}

void CardStyle::checkOne()
{
    Card passComb[10][5];
    int num__comb = 0;

    for (int i = 0; i < 10; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            if (int(arr[i][j].getCard()) > 10)
            {
                sum += 10;
                continue;
            }
            sum += arr[i][j].getCard();
        }
        if (sum % 10 == 0)
        {
            for (int k = 0; k < 5; ++k)
                passComb[num__comb][k] = arr[i][k];
            num__comb++;
        }
    }

    // 代表無妞
    if (num__comb == 0)
        return;
    if (num__comb > 1)
    {
        int maxi = 0;
        for (int i = 1; i < num__comb; ++i)
        {
            if ((passComb[i][3].getSymbol() + passComb[i][4].getSymbol()) % 10 > (passComb[maxi][3].getSymbol() + passComb[maxi][4].getSymbol()) % 10)
                maxi = i;
        }
        for (int i = 0; i < 5; ++i)
            final[i] = passComb[maxi][i];
        haveFinal = 1;
        cStyle = 2;
        return;
    }
    for (int i = 0; i < 5; ++i)
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
    for (int i = 0; i < 5; ++i)
        final[i] = arr[0][i];
    for (int i = 0; i < 5; i++)
    {
        if (int(arr[0][i].getCard()) > 10)
        {
            haveFinal = 1;
            cStyle = 1;
        }
    }
    if (!haveFinal)
        cStyle = 0;
}

void CardStyle::checkStyle()
{
    checkSuper();
    if (!haveFinal)
    {
        checkTwo();
        if (!haveFinal)
        {
            checkOne();
            if (!haveFinal)
                checkPoor();
        }

    }
}

Card* CardStyle::getFinal()
{
    return final;
}

int CardStyle::getCstyle()
{
    return cStyle;
}

Card* CardStyle::getCards()
{
    return cards;
}

void CardStyle::print()
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 5; ++j)
            cout << arr[i][j].getCard() << " ";
        cout << endl;
    }
    cout << "------------------------------\n";
    for (int i = 0; i < 5; ++i)
        cout << final[i].getCard() << " ";
    cout << endl;
    cout << "cStyle: " << cStyle << endl;
}