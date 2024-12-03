// 20241126 �ύX�_
// �J�[�h�̈�������ύX
// �J��Ԃ��s���鏈�����֐���


#include "player.h"

#include <iostream>
using namespace std;

void Player::PlayerPlay(const int i, Deck* deck)
{
	int state = PLAY;

	bool burst = false;

	if (pullNum == SECOND)
	{
		burst = CollectResult(i);
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
			InputCard(deck);
			turn++;
			//setSumCard();
		}
		burst = CollectResult(i);
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

bool Player::CollectResult(int i)
{
	PullCardScore();
	bool burst = JudgeBurst();
	cout << "< �v���C���[ " << i + 1 << " >" << endl;
	ShowCard();
	cout << endl;
	cout << "	score > " << GetScore() << endl;
	if (burst) cout << "�o�[�X�g�I" << endl;
	cout << endl;
	return burst;
}

void Player::ShowCard()
{
	int size = sumCard;

	for (int i = 0; i < size; i++)
	{
		int suit = cardNum[i] / 13;
		int num = cardNum[i] % 13;
		Deck::ShowSuitAndNum(suit, num);
	}
}