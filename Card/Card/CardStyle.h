#ifndef Sty_H
#define Sty_H

class CardStyle
{
private:
    int* cards;
    int* buffer; // 儲存組合的陣列
    int combinationSize; // 挑選的牌數
    int MAX_COMBINATIONS; // 最大組合數
public:
    CardStyle();
    int getCombinationSize() const;
    void setCards(int[]);
    void generateCombinations(int, int, int[][5], int&);
};
#endif