// 20241126 �ύX�_
// �J�[�h�̈�������ύX

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
	cout << "< �f�B�[���[ >" << endl;
	ShowCard();
	cout << endl;
	if (pullNum == SECOND)
	{
		cout << "	score > " << GetScore() << endl;
		if (burst) cout << "�o�[�X�g�I" << endl;
		cout << endl;
	}
	else if (pullNum == FIRST)
	{
		pullNum = SECOND;
	}
}

void Dealer::ShowCard()
{
	int size = 1;
	if (sumCard != 2)
	{
		size = sumCard;
	}
	for (int i = 0; i < size; i++)
	{
		int suit = cardNum[i] / 13;
		int num = cardNum[i] % 13;
		Deck::ShowSuitAndNum(suit, num);
	}
}