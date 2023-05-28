#include "CardStyle.h"

CardStyle::CardStyle()
{
    cards = new int[5];
    combinationSize = 3;
    MAX_COMBINATIONS = 10;
    buffer = new int[combinationSize];
}

int CardStyle::getCombinationSize() const
{
    return combinationSize;
}

void CardStyle::setCards(int cards[])
{
    this->cards = cards;
}

void CardStyle::generateCombinations(int startIndex, int currentIndex, int arr[][5], int& arrIndex)
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
        generateCombinations(i + 1, currentIndex + 1, arr, arrIndex);
    }
}