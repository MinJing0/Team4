#ifndef Sty_H
#define Sty_H

class CardStyle
{
private:
    double* cards;
    double buffer[5]; // �x�s�զX���}�C
    double final[5]; // �x�s�̫��쪺�̦n�P
    double arr[10][5]; // �x�s�Ҧ��P���զX
    int combinationSize; // �D�諸�P��
    int MAX_COMBINATIONS; // �̤j�զX��
    int arrIndex;
    bool haveFinal;
public:
    CardStyle();
    int getCombinationSize() const;
    void setCards(double[]);
    void generateCombinations(int, int);
    void checkSuper(); // �d�ݦ��S���׷�����
    void checkTwo(); // �d�ݦ��S������
    void checkOne(); // �d�ݦ��S����
    bool have_Final();
    double* getFinal();

    // test
    void print();
};

#endif