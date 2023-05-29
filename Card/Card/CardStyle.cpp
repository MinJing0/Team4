#include <iostream>
using namespace std;

#include "CardStyle.h"

CardStyle::CardStyle()
{
    cards = new double[5];
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
    this->cards = cards;
}

void CardStyle::generateCombinations(int startIndex, int currentIndex)
{
    // �p�G�w�g�F��զX�j�p�A�h��X�զX
    if (currentIndex == combinationSize) {
        int currentArrIndex = arrIndex;

        // �x�s�զX
        for (int i = 0; i < combinationSize; i++) {
            arr[currentArrIndex][i] = buffer[i];
        }

        // �x�s�ѤU���P
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

        arrIndex++; // �W�[ arr ����
        return;
    }

    // ���j�ͦ��զX
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
    for (int i = 0; i < 5; ++i)
        final[i] = arr[0][i];
    haveFinal = 1;
}

// void CardStyle::checkTwo()
// {
//     int num__comb = 0;
//     for (int i = 0; i < 10; i++) 
//     {
//         int sum = 0;
//         for (int j = 0; j < 3; j++) 
//             sum += arr[i][j];
//         if (sum % 10 == 0)
//         {
//             isTwo = 1;
//         }
//     }
// }

void CardStyle::checkOne()
{
    double passComb[10][5];
    int num__comb = 0;

    for (int i = 0; i < 10; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] > 10)
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

    if (num__comb > 1)
    {
        int maxi = 0;
        for (int i = 1; i < num__comb; ++i)
        {
            if (int(passComb[i][3] + passComb[i][4]) % 10 > int(passComb[maxi][3] + passComb[maxi][4]) % 10)
                maxi = i;
        }
        for (int i = 0; i < 5; ++i)
            final[i] = passComb[maxi][i];
        return;
    }
    for (int i = 0; i < 5; ++i)
        final[i] = passComb[0][i];
}

bool CardStyle::have_Final()
{
    return haveFinal;
}

double* CardStyle::getFinal()
{
    return final;
}

void CardStyle::print()
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 5; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << "------------------------------\n";
    for (int i = 0; i < 5; ++i)
        cout << final[i] << " ";
    cout << endl;
}