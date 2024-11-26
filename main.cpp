#include "player.h"
#include "dealer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// これは２０２４年７月に作成したコードを改変したもの

const int MAX_PLAYER = 2; // 最大人数を固定する場合に使用

enum Result
{
	WIN = 0,
	LOSE = 1,
	DRAW = 2,
	OTHER = 3,
};

void InitRand()
{
	srand((unsigned int)time(NULL));
}

int main()
{
	InitRand();
	Result result = OTHER;
	const char* resultArr[] = {"Win", "Lose", "Draw", "Other"};
	const int MAX_CARD_NUM = 52;
	int alreadyPublishedCard[MAX_CARD_NUM]; // 既に引いたカードを格納する配列
	for (int i = 0; i < MAX_CARD_NUM; i++)
	{
		alreadyPublishedCard[i] = -1;
	}

	Player player[MAX_PLAYER]; // 最大人数を固定する場合に使用
	Dealer dealer;

	//player* player;	// 最大人数を固定しない場合に使用
	int size = MAX_PLAYER;	// 最大人数を固定する場合はMAX_player、固定しない場合は0を入力
	/*while (size < 2)
	{
		cout << "何人でプレイしますか？（１名はディーラー役になります）" << endl;
		cin >> size;
		if (size < 2) cout << "二人以上でプレイしてください" << endl;
	}

	player = new player[size];*/

	/*system("cls");
	cout << "プレイヤー１はディーラーです。" << endl
		<< "結果発表ではプレイヤー２以降の人がディーラーに勝てたかどうかが判定されます。" << endl;*/

	/*for (int i = 1; i < size; i++)
	{
		int turn = 0;
		do
		{
			for (int j = 0; j < pullNum; j++)
			{
				bool ok = false;
				do
				{
					player[i].inputCard();
					for (int k = 0; k < MAX_CARD_NUM; k++)
					{
						if (alreadyPublishedCard[k] == -1)
						{
							ok = true;
							alreadyPublishedCard[k] = player[i].getCardNum(turn);
							break;
						}
						if (player[i].getCardNum(turn) == alreadyPublishedCard[k]) break;
					}
				} while (!ok);
				turn++;
				player[i].setSumCard();
			}
			pullNum = SECOND;
			player[i].pullCardScore();
			burst = player[i].judgeBurst();
			cout << "< プレイヤー " << i + 1 << " >" << endl;
			player[i].showCard();
			cout << endl;
			cout << "	score > " << player[i].getScore() << endl;
			if (burst) cout << "バースト！" << endl;
			cout << endl;
			cout << "続けますか？ 選択肢にない回答は続けるとみなします" << endl
				<< "なお、バーストしていた場合は強制的に次の人のターンになります" << endl
				<< "1 : 続ける,　2 : やめる" << endl;
			cin >> state;
			system("cls");
		} while (!burst && state != QUIT);
		pullNum = FIRST;
		state = PLAY;
	}*/
	dealer.DealerPlay(MAX_CARD_NUM, &alreadyPublishedCard[0]); // 1ターン目
	cout << endl;

	for (int i = 0; i < MAX_PLAYER; i++)
	{
		player[i].PlayerPlay(MAX_CARD_NUM, &alreadyPublishedCard[0], i);
		cout << endl;
	}

	for (int i = 0; i < MAX_PLAYER; i++) // ２ターン目
	{
		cout << endl;
		cout << "< プレイヤー" << i + 1 << " >" << endl;
		player[i].PlayerPlay(MAX_CARD_NUM, &alreadyPublishedCard[0], i);
	}
	dealer.DealerPlay(MAX_CARD_NUM, &alreadyPublishedCard[0]);

	cout << "<<結果発表>>" << endl
		<< endl
		<< "< ディーラー  >" << endl
		<< "	カード > " << flush;
	dealer.showCard(false);
	cout << endl;
	cout << "	スコア > " << dealer.getScore() << endl
		<< endl;
	for (int i = 0; i < size; i++)
	{
		cout << "< プレイヤー" << i + 1 << " >" << endl
			<< "	カード > " << flush;
		player[i].showCard(false);
		cout << endl;
		cout << "	スコア > " << player[i].getScore() << " > " << flush;
		(!player[i].judgeBurst() && player[i].getScore() > dealer.getScore()) || dealer.judgeBurst() ?  result = WIN:
			player[i].judgeBurst() || player[i].getScore() < dealer.getScore() ? result = LOSE:
			result = DRAW;
		cout << resultArr[result] << endl 
			<< endl;
	}

	// もし、プレイヤーの人数が固定じゃなかったらコメント化解除
	/*cout << endl;
	{
		delete[] player;
		cout << "メモリを解放しました" << endl;
	}*/
}