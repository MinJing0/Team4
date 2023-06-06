#include <iostream>
#include <cctype>
#include <sstream>
using namespace std;

#include "Print.h"

void Print::welcome()
{
    cout << "歡迎加入我們牛牛的行列\n";
    cout << "(按 Enter 顯示遊戲玩法)" << endl;
    cin.get();
    system("cls");
}

void Print::gamePlay()
{
    cout << "遊戲人數設定為4人，一名莊家（電腦）以及三名玩家。\n";
    cout << "-----------------------------------------------------\n";
    cout << "由玩家先下注，下注完後每人發五張牌，每個玩家與莊家各自比大小，輸牌便損失注金，贏牌可以向莊家索取規定倍數的獎金。\n";
    cout << "(按 Enter 顯示遊戲玩法)" << endl;
    cin.get();
    system("cls");
}

void Print::rule()
{
    cout << "牌面A=1點，2~9即為牌面點數，J、Q、K都算10點。牌局中如果需要比大小，順序是A最小，接下來依序為2、3、4…10、J、Q、K。\n";
    cout << "-----------------------------------------------------\n";
    cout << "基本牌: \n";
    cout << "\n無妞（烏龍）：又分為無公牌（莊家贏）、有公牌（JQK)\n";
    cout << "EX: 10 3 2 Q 6 因為沒有3張能加起來成為10的整數倍\n";
    cout << "有妞：分為大點（第二組牌>6點）、小點（第二組牌<=6點）EX: 10 3 7 Q 6 為牛六\n";
    cout << "妞妞：第二組牌剛好也是10的倍數，EX: 10 3 7 Q K\n";
    cout << "終極妞妞：全部都是公牌\n";
    cout << "-----------------------------------------------------\n";
    cout << "牌型大小: \n";
    cout << "\n如果號碼相同可以比花色，原則是黑桃＞紅心＞方塊＞梅花(梅花Q＞紅心J、黑桃K＞紅心K)\n";
    cout << "無妞：比單張大小單張最大為 K……A\n";
    cout << "有妞：比分數大小 9分最大 9-8-……A\n";
    cout << "妞妞：比單張+花色大小 K……A 黑桃>紅桃>梅花>方塊\n";
    cout << "-----------------------------------------------------\n";
    cout << "贏牌賠率: \n";
    cout << "\n烏龍（不帶公牌）：直接輸掉本局\n";
    cout << "帶公烏龍：注1賠2\n";
    cout << "有妞：注1賠3\n";
    cout << "妞妞：注1賠4\n";
    cout << "終極妞妞：注1賠6\n";
    cout << "-----------------------------------------------------\n";
    cout << "(按 Enter 繼續)" << endl;
    cin.get();
    system("cls");
}

void Print::playerHandCard(Player& p, int index, Card* c)
{
    cout << "Player " << index + 1 << "手牌：";
    for (int i = 0; i < 5; ++i)
        cout << c[i].get_str_suit() << c[i].get_str_symbol() << " ";
    cout << endl;
    if (p.getCstyle() == 4)
        cout << "恭喜你終極妞妞！！！賭大一點吧！！！\n";
    else if (p.getCstyle() == 3)
        cout << "恭喜你妞妞！！！機會難得 賭了吧！！！\n";
    else if (p.getCstyle() == 2)
        cout << "有妞～～～\n";
    else if (p.getCstyle() == 1)
        cout << "無妞QQ 下次燒香拜佛吧\n";
    else
        cout << "烏龍TAT 你不要再玩比較好\n";
    cout << endl;
}

void Print::pcHandCard(PC& pc, Card* c)
{
    cout << "電腦的牌是：";
    for (int i = 0; i < 5; ++i)
        cout << c[i].get_str_suit() << c[i].get_str_symbol() << " ";
    cout << endl;
    if (pc.getCstyle() == 4)
        cout << "是終極妞妞！！！\n";
    else if (pc.getCstyle() == 3)
        cout << "是妞妞！！！\n";
    else if (pc.getCstyle() == 2)
        cout << "有妞!\n";
    else if (pc.getCstyle() == 1)
        cout << "無妞QQ\n";
    else
        cout << "烏龍TAT\n";
    cout << endl;
}

void Print::win(Player& p, int index)
{
    index++;
    if (p.getWin())
        cout << "Player " << index << " 你贏了 ";
    else
        cout << "Player " << index << " 你輸了 ";
}

void Print::stakeMoney(Player& p)
{
    string money;
    /* status
     * 1: 成功
     * 2: 判斷未知字元
     * 3: 金額不超過 1000
     * 4: 超過自己的金額
    */
    int status;
    int sta2 = false;
    int sMoney = 0;

    cout << "你目前手頭上還有 $" << p.getMoney() << endl;
    cout << "請輸入你的賭金(輸入 exit 退出遊戲): ";
    getline(cin, money);

    if (money == "exit"||money == "Exit"||money == "EXIT")
    {
        p.setInPlay(false);
        cout << "\n你已經成功退出遊戲" << endl;
        cout << "(按 Enter 繼續)" << endl;
        cin.get();
        return;
    }

    for (int i = 0; i < money.size(); ++i)
    {
        if (!isdigit(money[i]))
        {
            sta2 = true;
            status = 2;
            break;
        }
    }

    stringstream ss;
    if (!sta2)
    {
        int m;
        ss << money;
        ss >> m;

        if (m < 1000)
            status = 3;
        else if (m > p.getMoney())
            status = 4;
        else
        {
            status = 1;
            sMoney = m;
        }
    }

    while (status != 1)
    {
        if (status == 2)
        {
            cout << "\n判斷未知指令\n";
            cout << "請再輸入一次金額(只能輸入數字且不能包含\"空格\" ; 輸入 exit 退出遊戲): ";
            getline(cin, money);
            if (money == "exit" || money == "Exit" || money == "EXIT")
            {
                p.setInPlay(false);
                cout << "\n你已經成功退出遊戲" << endl;
                cout << "(按 Enter 繼續)" << endl;
                cin.get();
                return;
            }

            sta2 = false;
            for (int i = 0; i < money.size(); ++i)
            {
                if (!isdigit(money[i]))
                {
                    sta2 = true;
                    break;
                }
            }
            if (!sta2)
            {
                int m;
                ss.clear();
                ss << money;
                ss >> m;
                if (m < 1000)
                    status = 3;
                else if (m > p.getMoney())
                    status = 4;
                else
                {
                    status = 1;
                    sMoney = m;
                }
            }
        }
        else if (status == 3)
        {
            cout << "\n請再輸入一次金額必須大於(包含)1000 (輸入 exit 退出遊戲): ";
            getline(cin, money);

            if (money == "exit"||money == "Exit"||money == "EXIT")
            {
                p.setInPlay(false);
                cout << "\n你已經成功退出遊戲" << endl;
                cout << "(按 Enter 繼續)" << endl;
                cin.get();
                return;
            }

            sta2 = false;
            for (int i = 0; i < money.size(); ++i)
            {
                if (!isdigit(money[i]))
                {
                    status = 2;
                    sta2 = true;
                    break;
                }
            }

            if (!sta2)
            {
                int m;
                ss.clear();
                ss << money;
                ss >> m;
                if (m < 1000)
                {
                    status = 3;
                }
                else if (m > p.getMoney())
                    status = 4;
                else
                {
                    status = 1;
                    sMoney = m;
                }
            }
        }
        else if (status == 4)
        {
            cout << "\n輸入金額超過自己的戶頭! \n";
            cout << "請再輸入一次金額必須大於(包含)1000 (輸入 exit 退出遊戲): ";
            getline(cin, money);

            if (money == "exit"||money == "Exit"||money == "EXIT")
            {
                p.setInPlay(false);
                cout << "\n你已經成功退出遊戲" << endl;
                cout << "(按 Enter 繼續)" << endl;
                cin.get();
                return;
            }

            sta2 = false;
            for (int i = 0; i < money.size(); ++i)
            {
                if (!isdigit(money[i]))
                {
                    status = 2;
                    sta2 = true;
                    break;
                }
            }

            if (!sta2)
            {
                int m;
                ss.clear();
                ss << money;
                ss >> m;
                if (m < 1000)
                {
                    status = 3;
                }
                else if (m > p.getMoney())
                    status = 4;
                else
                {
                    status = 1;
                    sMoney = m;
                }
            }
        }
    }
    p.setStakeMoney(sMoney);
}

void Print::showStakeMoney(Player& p)
{
    cout << "賭注金額: " << p.getStakeMoney() << endl;
}

void Print::notHaveMoney(int index)
{
    cout << "Player " << index + 1 << " 已沒有錢參加遊戲 ";
}

void Print::isExit(int index)
{
    cout << "Player " << index + 1 << " 已終止繼續遊戲 ";
}

void Print::lastMoney(Player& p)
{
    cout << "剩餘金額: " << p.getMoney() << endl;
}

void Print::rank(Player& p1, Player& p2, Player& p3)
{
    int iarr[3];
    Player arr[3];
    arr[0] = p1;
    arr[1] = p2;
    arr[2] = p3;

    iarr[0] = 1;
    iarr[1] = 2;
    iarr[2] = 3;

    for (int i = 0; i < 2; ++i)
        for (int j = i + 1; j < 3; ++j)
            if (arr[i].getMoney() > arr[j].getMoney())
            {
                Player pbuffer;
                int ibuffer;
                pbuffer = arr[i];
                arr[i] = arr[j];
                arr[j] = pbuffer;
                ibuffer = iarr[i];
                iarr[i] = iarr[j];
                iarr[j] = ibuffer;
            }
    for (int i = 0; i < 3; ++i)
    {
        cout << "rank" << i + 1 << " -> Player " << iarr[2-i] << endl;
    }
}