#ifndef Sty_H
#define Sty_H

class CardStyle
{
private:
    double* cards;
    double* buffer; // �x�s�զX���}�C
    double* final; // �x�s�̫��쪺�̦n�P
    double arr[10][5]; // �x�s�Ҧ��P���զX
    int combinationSize; // �D�諸�P��
    int MAX_COMBINATIONS; // �̤j�զX��
    int arrIndex;
    bool isSuper; // ���S���׷�����
    bool isTwo; // ���S������
    bool isOne; // ���S����
public:
    CardStyle();
    int getCombinationSize() const;
    void setCards(double[]);
    void generateCombinations(int, int);
    void checkSuper(); // �d�ݦ��S���׷�����
    void checkTwo(); // �d�ݦ��S������
    void checkOne(); // �d�ݦ��S����

    // test
    void print();
};

#endif