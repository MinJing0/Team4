#include <iostream>
using namespace std;

#include "Game.h"
#include "CardStyle.h"

int main()
{
	Game game;
	// 顯示歡迎及規則
	/*game.welcome();
	game.gamePlay();
	game.rule();*/

	// 初始化桌面(拿到整副撲克牌)
	game.createDeck();

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
		int money;
		c = game.getPlayer(i).getCards();
		game.playerHandCard(game.getPlayer(i), i, c);
		game.stakeMoney(game.getPlayer(i));
	}

	c = game.getPC().getCards();
	game.pcHandCard(game.getPC(), c);

	for (int i = 0; i < 3; ++i)
	{
		game.compare(game.getPlayer(i));
		game.win(game.getPlayer(i), i);
	}
}