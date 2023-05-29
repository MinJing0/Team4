#ifndef Sty_H
#define Sty_H

class CardStyle
{
private:
    double* cards;
    double buffer[5]; // 儲存組合的陣列
    double final[5]; // 儲存最後找到的最好牌
    double arr[10][5]; // 儲存所有牌的組合
    int combinationSize; // 挑選的牌數
    int MAX_COMBINATIONS; // 最大組合數
    int arrIndex;
    bool haveFinal;
public:
    CardStyle();
    int getCombinationSize() const;
    void setCards(double[]);
    void generateCombinations(int, int);
    void checkSuper(); // 查看有沒有終極妞妞
    void checkTwo(); // 查看有沒有妞妞
    void checkOne(); // 查看有沒有妞
    bool have_Final();
    double* getFinal();

    // test
    void print();
};

#endif