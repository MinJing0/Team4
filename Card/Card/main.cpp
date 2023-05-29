#include <iostream>
using namespace std;

#include "Game.h"
#include "Card.h"
#include "Player.h"

int main()
{
	Game game;
	// 顯示歡迎及規則
	// game.welcome();
	// game.gamePlay();
	// game.rule();

	// 初始化桌面(拿到整副撲克牌)
	game.createDeck();

	// 洗牌
	game.Shuffle();
	// 將牌給3個玩家及莊家(電腦)
	game.giveCard();
}
