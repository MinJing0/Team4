#include "Card.h"

#ifndef Sty_H
#define Sty_H

class CardStyle
{
private:
    Card cards[5];
    Card buffer[5]; // �x�s�զX���}�C
    Card final[5]; // �x�s�̫��쪺�̦n�P
    Card arr[10][5]; // �x�s�Ҧ��P���զX
    int combinationSize; // �D�諸�P��
    int MAX_COMBINATIONS; // �̤j�զX��
    int arrIndex;
    bool haveFinal;
    int cStyle; // �w�q�P��

    // check function
    void checkSuper(); // �d�ݦ��S���׷����� -> cStyle <= 4
    void checkTwo(); // �d�ݦ��S������ -> cStyle <= 3
    void checkOne(); // �d�ݦ��S���� -> cStyle <= 2
    void checkPoor(); // �L�� -> cStyle <= 1, �Q�s -> cStyle <= 0

public:
    CardStyle();
    int getCombinationSize() const;
    void setCards(Card[]);
    void generateCombinations();
    void checkStyle(); // �ˬd�P���ݩ���
    Card* getFinal();
    int getCstyle();
    Card* getCards();

    // test
    void print();
};

#endif