/* �w�p�F���ĪG
 * �禡�^�Ǥ@�ӫ��СA�Ӹӫ��Цs�۫e��3�i�X�_�Ӭ�10���զX
 * �n���@�� &�ܼƥh�s���X�ղզX�A�̫�n����ƵP�n�A�ҥΪ�
*/

#include <iostream>
using namespace std;

#include "CardStyle.h"

int main() {
    CardStyle t;
    int cards[5] = { 3, 5, 4, 6, 2 };
    t.setCards(cards);

    int passComb[10][5];
    int arr[10][5]; // �x�s�Ҧ��զX�M�ѤU���P
    int arrIndex = 0; // arr ����

    std::cout << "�Ҧ��i�઺�զX�p�U�G" << std::endl;

    // �I�s generateCombinations ��ƥͦ��Ҧ��i�઺�զX
    t.generateCombinations(0, 0, arr, arrIndex);

    int num__comb = 0;
    for (int i = 0; i < arrIndex; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += arr[i][j];
        }
        if (sum % 10 == 0)
        {
            for (int k = 0; k < 5; ++k)
                passComb[num__comb][k] = arr[i][k];
            num__comb++;
        }
    }
    for (int i = 0; i < num__comb; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << passComb[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}