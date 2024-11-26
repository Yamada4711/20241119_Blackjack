#include "dealer.h"
#include <iostream>
using namespace std;

void Dealer::DealerPlay(const int MAX_CARD_NUM, int* alreadyPublishedCard)
{
	bool burst = false;
	bool firstDealer = false;
	if (pullNum == FIRST)
	{
		firstDealer = true;
	}

	do
	{
		for (int j = 0; j < pullNum; j++)
		{
			bool ok = false;
			do
			{
				inputCard();
				for (int k = 0; k < MAX_CARD_NUM; k++)
				{
					if (alreadyPublishedCard[k] == -1)
					{
						ok = true;
						alreadyPublishedCard[k] = getCardNum(turn);
						break;
					}
					if (getCardNum(turn) == alreadyPublishedCard[k]) break;
				}
			} while (!ok);
			turn++;
			setSumCard();
		}
		pullCardScore();
		burst = judgeBurst();
		if (pullNum == FIRST)
		{
			break;
		}
	} while (!burst && getScore() < 17);
	cout << "< �f�B�[���[ >" << endl;
	showCard(firstDealer);
	cout << endl;
	if (pullNum == SECOND)
	{
		cout << "	score > " << getScore() << endl;
		if (burst) cout << "�o�[�X�g�I" << endl;
		cout << endl;
	}
	else if (pullNum == FIRST)
	{
		pullNum = SECOND;
	}
}