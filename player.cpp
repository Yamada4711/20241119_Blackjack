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
		if (burst) cout << "バースト！" << endl;
		cout << endl;

		cout << "続けますか？ 選択肢にない回答は続けるとみなします" << endl
			<< "なお、バーストしていた場合は何を入力しても次の人のターンになります" << endl
			<< "1 : 続ける,　2 : やめる" << endl;
		cin >> state;
	}

	while (!burst && state != QUIT)
	{
		for (int j = 0; j < pullNum; j++)
		{
			int card = -1;
			bool ok = false;
			do
			{
				//inputCard();
				card = pullCard();
				for (int k = 0; k < MAX_CARD_NUM; k++)
				{
					if (alreadyPublishedCard[k] == -1)
					{
						ok = true;
						alreadyPublishedCard[k] = card;
						inputCard(card);
						break;
					}
					if (card == alreadyPublishedCard[k]) break;
				}
			} while (!ok);
			turn++;
			setSumCard();
		}
		pullCardScore();
		burst = judgeBurst();
		cout << "< プレイヤー " << i + 1 << " >" << endl;
		showCard(false);
		cout << endl;
		cout << "	score > " << getScore() << endl;
		if (burst) cout << "バースト！" << endl;
		cout << endl;
		if (pullNum == FIRST)
		{
			pullNum = SECOND;
			break;
		}
		cout << "続けますか？ 選択肢にない回答は続けるとみなします" << endl
			<< "なお、バーストしていた場合は何を入力しても次の人のターンになります" << endl
			<< "1 : 続ける,　2 : やめる" << endl;
		cin >> state;
	}
}