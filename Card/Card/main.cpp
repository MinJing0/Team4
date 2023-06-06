#include <iostream>
using namespace std;

#include "Game.h"
#include "CardStyle.h"

int main()
{
    Game game;
    // ����w��γW�h
    game.welcome();
    game.gamePlay();
    game.rule();

    // ��l�Ʈୱ(�����Ƽ��J�P)
    game.createDeck();

    while (game.getPlayer(0).getInPlay()||game.getPlayer(1).getInPlay()||game.getPlayer(2).getInPlay())
    {
        // �~�P
        game.Shuffle();
        // �N�P��3�Ӫ��a�β��a(�q��)
        game.giveCard();

        CardStyle cs;
        Card* c = new Card[5];
        int cStyle;
        for (int i = 0; i < 3; ++i)
        {
            // ���� cs
            cs = CardStyle();
            // �⪱�a���P�s�� c
            c = game.getPlayer(i).getCards();
            // �⪱�a���P�s�� cs
            cs.setCards(c);

            // �]�Ҧ����զX
            cs.generateCombinations();
            // �P�_���a�̨εP���βզX
            cs.checkStyle();
            // �^�ǳ̨βզX�� c
            c = cs.getFinal();
            // �N�̨βզX��^���a��P
            game.getPlayer(i).setCards(c);
            // �N�P���s�쪱�a������Y
            game.getPlayer(i).setCstyle(cs.getCstyle());
        }

        /*
        * �N�q�����P�ձƦ��̨βզX
        * �]�w�q���̨εP�ժ��զX�P��
        */

        // ���� cs
        cs = CardStyle();
        // ��q�����P�s�� c
        c = game.getPC().getCards();
        // ��q�����P�s�� cs
        cs.setCards(c);

        // �]�Ҧ����զX
        cs.generateCombinations();
        // �P�_�q���̨εP���βզX
        cs.checkStyle();
        // �^�ǳ̨βզX�� c
        c = cs.getFinal();
        // �N�̨βզX��^�q����P
        game.getPC().setCards(c);
        // �N�P���s��q��������Y
        game.getPC().setCstyle(cs.getCstyle());

        // ��ܤ�P�H�ο�J���
        for (int i = 0; i < 3; ++i)
        {
            // �٥��h�X�����a�åB�]���j��(�]�t)1000 �~���~���
            if (game.getPlayer(i).getInPlay() && game.getPlayer(i).getMoney() >= 1000)
            {
                c = game.getPlayer(i).getCards();
                game.playerHandCard(game.getPlayer(i), i, c);
                game.stakeMoney(game.getPlayer(i));
                system("cls");
            }
        }

        c = game.getPC().getCards();
        game.pcHandCard(game.getPC(), c);

        for (int i = 0; i < 3; ++i)
        {
            if (game.getPlayer(i).getInPlay() && game.getPlayer(i).getMoney() >= 1000)
            {
                cout << "----------------------------------\n";
                c = game.getPlayer(i).getCards();
                game.playerHandCard(game.getPlayer(i), i, c);
                game.showStakeMoney(game.getPlayer(i));
                cout << endl;
            }
        }

        for (int i = 0; i < 3; ++i)
        {
            if (game.getPlayer(i).getInPlay() && game.getPlayer(i).getMoney() >= 1000)
            {
                game.compare(game.getPlayer(i));
                if (game.getPlayer(i).getWin())
                    game.getPlayer(i).winMoney();
                else
                    game.getPlayer(i).loseMoney();
                game.win(game.getPlayer(i), i);
            }
            else
            {
                if (game.getPlayer(i).getMoney() < 1000)
                {
                    game.getPlayer(i).setInPlay(false);
                    game.notHaveMoney(i);
                }
                else
                    game.isExit(i);
            }
            game.lastMoney(game.getPlayer(i));
        }
        cout << "(��Enter�~��)";
        cin.get();
        system("cls");
    }
    cout << "\n�C������\n(��Enter�d�ݱƦ�)";
    cin.get();
    system("cls");
    game.rank(game.getPlayer(0), game.getPlayer(1), game.getPlayer(2));
}