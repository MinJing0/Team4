#ifndef Sty_H
#define Sty_H

class CardStyle
{
private:
    double *cards;
    double buffer[5]; // 儲存組合的陣列
    double final[5]; // 儲存最後找到的最好牌
    double arr[10][5]; // 儲存所有牌的組合
    int combinationSize; // 挑選的牌數
    int MAX_COMBINATIONS; // 最大組合數
    int arrIndex;
    bool haveFinal;
    int cStyle; // 定義牌型

    // check function
    void checkSuper(); // 查看有沒有終極妞妞 -> cStyle <= 4
    void checkTwo(); // 查看有沒有妞妞 -> cStyle <= 3
    void checkOne(); // 查看有沒有妞 -> cStyle <= 2
    void poorCard(); // 無妞 -> cStyle <= 1
    void realPoor(); // 烏龍 -> cStyle <= 0

public:
    CardStyle();
    int getCombinationSize() const;
    void setCards(double []);
    void generateCombinations(int, int);
    void checkStyle(); // 檢查牌型屬於何者
    double* getFinal();
    int getCstyle();

    // test
    void print();         
};

#endif
