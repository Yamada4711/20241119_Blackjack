#include "player.h"

#include <iostream>
using namespace std;

void Player::PlayerPlay(const int i, Deck deck, int* sumTurn)
{
	int state = PLAY;

	bool burst = false;

	if (pullNum == SECOND)
	{
		burst = collectResult(i);
		state = Question();
	}

	while (!burst && state != QUIT)
	{
		for (int j = 0; j < pullNum; j++)
		{
			//int card = -1;
			//bool ok = false;
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
			inputCard(deck, sumTurn);
			++*sumTurn;
			turn++;
			//setSumCard();
		}
		burst = collectResult(i);
		if (pullNum == FIRST)
		{
			pullNum = SECOND;
			break;
		}
		state = Question();
	}
}

int Player::Question()
{
	int state = 0;
	cout << "�����܂����H �I�����ɂȂ��񓚂͑�����Ƃ݂Ȃ��܂�" << endl
		<< "�Ȃ��A�o�[�X�g���Ă����ꍇ�͉�����͂��Ă����̐l�̃^�[���ɂȂ�܂�" << endl
		<< "1 : ������,�@2 : ��߂�" << endl;
	cin >> state;
	return state;
}

bool Player::collectResult(int i)
{
	pullCardScore();
	bool burst = judgeBurst();
	cout << "< �v���C���[ " << i + 1 << " >" << endl;
	showCard(false);
	cout << endl;
	cout << "	score > " << getScore() << endl;
	if (burst) cout << "�o�[�X�g�I" << endl;
	cout << endl;
	return burst;
}