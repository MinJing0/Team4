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