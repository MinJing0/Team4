/* �w�p�F���ĪG
 * �禡�^�Ǥ@�ӫ��СA�Ӹӫ��Цs�۫e��3�i�X�_�Ӭ�10���զX
 * �n���@�� &�ܼƥh�s���X�ղզX�A�̫�n����ƵP�n�A�ҥΪ�
*/

#include <iostream>
using namespace std;

#include "CardStyle.h"

int main() {
    CardStyle t;
    // double cards[5] = { 12.4, 13.4, 11.3, 12.3, 12.1 };
    double cards[5] = { 1.3, 13.4, 7.3, 13.3, 3.4 };
    t.setCards(cards);

    // int passComb[10][5];

    int arrIndex = 0; // arr ����

    std::cout << "�Ҧ��i�઺�զX�p�U�G" << std::endl;

    // �I�s generateCombinations ��ƥͦ��Ҧ��i�઺�զX
    t.generateCombinations(0, 0);

    t.checkSuper();
    if (!t.have_Final())
        // t.checkTwo();
        if (!t.have_Final())
            t.checkOne();

    t.print();

    // int num__comb = 0;
    // for (int i = 0; i < arrIndex; i++) 
    // {
    //     int sum = 0;
    //     for (int j = 0; j < 3; j++) 
    //     {
    //         sum += arr[i][j];
    //     }
    //     if (sum % 10 == 0)
    //     {
    //         for (int k = 0; k < 5; ++k)
    //             passComb[num__comb][k] = arr[i][k];
    //         num__comb++;
    //     }
    // }
    // for (int i = 0; i < num__comb; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //     {
    //         cout << passComb[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}