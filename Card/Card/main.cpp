#include <iostream>
using namespace std;

#include "Game.h"
#include "CardStyle.h"

int main()
{
	Game game;
	// ����w��γW�h
	/*game.welcome();
	game.gamePlay();
	game.rule();*/

	// ��l�Ʈୱ(�����Ƽ��J�P)
	game.createDeck();

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