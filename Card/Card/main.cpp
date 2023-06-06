#include <iostream>
using namespace std;

#include "Game.h"
#include "CardStyle.h"

int main()
{
    Game game;
    // 顯示歡迎及規則
    game.welcome();
    game.gamePlay();
    game.rule();

    // 初始化桌面(拿到整副撲克牌)
    game.createDeck();

    while (game.getPlayer(0).getInPlay()||game.getPlayer(1).getInPlay()||game.getPlayer(2).getInPlay())
    {
        // 洗牌
        game.Shuffle();
        // 將牌給3個玩家及莊家(電腦)
        game.giveCard();

        CardStyle cs;
        Card* c = new Card[5];
        int cStyle;
        for (int i = 0; i < 3; ++i)
        {
            // 重整 cs
            cs = CardStyle();
            // 把玩家的牌存到 c
            c = game.getPlayer(i).getCards();
            // 把玩家的牌存到 cs
            cs.setCards(c);

            // 跑所有的組合
            cs.generateCombinations();
            // 判斷玩家最佳牌型及組合
            cs.checkStyle();
            // 回傳最佳組合給 c
            c = cs.getFinal();
            // 將最佳組合放回玩家手牌
            game.getPlayer(i).setCards(c);
            // 將牌型存到玩家物件裡頭
            game.getPlayer(i).setCstyle(cs.getCstyle());
        }

        /*
        * 將電腦的牌組排成最佳組合
        * 設定電腦最佳牌組的組合牌型
        */

        // 重整 cs
        cs = CardStyle();
        // 把電腦的牌存到 c
        c = game.getPC().getCards();
        // 把電腦的牌存到 cs
        cs.setCards(c);

        // 跑所有的組合
        cs.generateCombinations();
        // 判斷電腦最佳牌型及組合
        cs.checkStyle();
        // 回傳最佳組合給 c
        c = cs.getFinal();
        // 將最佳組合放回電腦手牌
        game.getPC().setCards(c);
        // 將牌型存到電腦物件裡頭
        game.getPC().setCstyle(cs.getCstyle());

        // 顯示手牌以及輸入賭金
        for (int i = 0; i < 3; ++i)
        {
            // 還未退出的玩家並且財產大於(包含)1000 才能繼續賭
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
        cout << "(按Enter繼續)";
        cin.get();
        system("cls");
    }
    cout << "\n遊戲結束\n(按Enter查看排行)";
    cin.get();
    system("cls");
    game.rank(game.getPlayer(0), game.getPlayer(1), game.getPlayer(2));
}