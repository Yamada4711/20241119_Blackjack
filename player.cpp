#include "player.h"

#include <iostream>
using namespace std;

void Player::PlayerPlay(const int MAX_CARD_NUM, int* alreadyPublishedCard, const int i)
{
	int state = PLAY;

	bool burst = false;

	if (pullNum == SECOND)
	{
		pullCardScore();
		burst = judgeBurst();
		showCard(false);
		cout << endl;
		cout << "	score > " << getScore() << endl;
		if (burst) cout << "�o�[�X�g�I" << endl;
		cout << endl;

		cout << "�����܂����H �I�����ɂȂ��񓚂͑�����Ƃ݂Ȃ��܂�" << endl
			<< "�Ȃ��A�o�[�X�g���Ă����ꍇ�͉�����͂��Ă����̐l�̃^�[���ɂȂ�܂�" << endl
			<< "1 : ������,�@2 : ��߂�" << endl;
		cin >> state;
	}

	while (!burst && state != QUIT)
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
		cout << "< �v���C���[ " << i + 1 << " >" << endl;
		showCard(false);
		cout << endl;
		cout << "	score > " << getScore() << endl;
		if (burst) cout << "�o�[�X�g�I" << endl;
		cout << endl;
		if (pullNum == FIRST)
		{
			pullNum = SECOND;
			break;
		}
		cout << "�����܂����H �I�����ɂȂ��񓚂͑�����Ƃ݂Ȃ��܂�" << endl
			<< "�Ȃ��A�o�[�X�g���Ă����ꍇ�͉�����͂��Ă����̐l�̃^�[���ɂȂ�܂�" << endl
			<< "1 : ������,�@2 : ��߂�" << endl;
		cin >> state;
	}
}