// 20241126 変更点
// カードの引き方を変更

#include "dealer.h"
#include <iostream>
using namespace std;

void Dealer::DealerPlay(Deck* deck)
{
	bool burst = false;
	bool firstDealer = false;
	if (pullNum == FIRST)
	{
		firstDealer = true;
	}
	else
	{
		PullCardScore();
		burst = JudgeBurst();
	}

	while (!burst && GetScore() < 17)
	{
		for (int j = 0; j < pullNum; j++)
		{
			/*bool ok = false;
			int card = -1;*/
			//do
			//{
			//	//inputCard();
			//	card = pullCard();
			//	for (int k = 0; k < MAX_CARD_NUM; k++)
			//	{
			//		if (alreadyPublishedCard[k] == -1)
			//		{
			//			ok = true;
			//			alreadyPublishedCard[k] = card;
			//			inputCard(card);
			//			break;
			//		}
			//		if (card == alreadyPublishedCard[k]) break;
			//	}
			//} while (!ok);
			InputCard(deck);
			turn++;
			//setSumCard();
		}
		PullCardScore();
		burst = JudgeBurst();
		if (pullNum == FIRST)
		{
			break;
		}
	}
	cout << "< ディーラー >" << endl;
	ShowCard(firstDealer);
	cout << endl;
	if (pullNum == SECOND)
	{
		cout << "	score > " << GetScore() << endl;
		if (burst) cout << "バースト！" << endl;
		cout << endl;
	}
	else if (pullNum == FIRST)
	{
		pullNum = SECOND;
	}
}