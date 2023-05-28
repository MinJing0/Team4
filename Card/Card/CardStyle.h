#ifndef Sty_H
#define Sty_H

class CardStyle
{
private:
    int* cards;
    int* buffer; // �x�s�զX���}�C
    int combinationSize; // �D�諸�P��
    int MAX_COMBINATIONS; // �̤j�զX��
public:
    CardStyle();
    int getCombinationSize() const;
    void setCards(int[]);
    void generateCombinations(int, int, int[][5], int&);
};
#endif