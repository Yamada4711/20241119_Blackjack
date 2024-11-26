#pragma once

class Deck
{
public:
	Deck();
	static void showSuitAndNum(int suitnum, int number);

	enum Card
	{
		K = 0,
		A = 1,
		J = 11,
		Q = 12,
	};
	enum Suit
	{
		DIAMONDS = 0,
		HEART = 1,
		SPADE = 2,
		CLUB = 3,
	};

	static const int MAX_CARD_NUM = 52;
	int alreadyPublishedCard[MAX_CARD_NUM]; // 既に引いたカードを格納する配列
};