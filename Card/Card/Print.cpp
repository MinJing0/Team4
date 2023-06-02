#include <iostream>
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
    cout << "有妞（小點）：注1賠2\n";
    cout << "有妞（大點）：注1賠3\n";
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
        cout << "Player " << index << " 你贏了\n";
    else
        cout << "Player " << index << " 你輸了\n";
}