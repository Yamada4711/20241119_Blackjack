// 20241126 変更点
// カードの引き方を変更
// 繰り返し行われる処理を関数化


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
	cout << "続けますか？ 選択肢にない回答は続けるとみなします" << endl
		<< "なお、バーストしていた場合は何を入力しても次の人のターンになります" << endl
		<< "1 : 続ける,　2 : やめる" << endl;
	cin >> state;
	return state;
}

bool Player::CollectResult(int i)
{
	PullCardScore();
	bool burst = JudgeBurst();
	cout << "< プレイヤー " << i + 1 << " >" << endl;
	ShowCard(false);
	cout << endl;
	cout << "	score > " << GetScore() << endl;
	if (burst) cout << "バースト！" << endl;
	cout << endl;
	return burst;
}