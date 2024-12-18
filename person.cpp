// 20241126 変更点
// showCardのswitch文の機能をデッキクラスに移行
// カードを引く処理を、当たりが出るまで引き続ける方法から、シャッフルしたカードが順番に引かれるように変更


#include "person.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Person::Person()
{
	for (int i = 0; i < MAX_PULL; i++)
	{
		cardNum[i] = 0;
		cardScore[i] = 0;
	}
	sumCard = 0;
	sumScore = 0;
}

Person::~Person()
{
	//cout << "デストラクタ" << endl;
}

int Person::PullCard()
{
	return rand() % 52 + 1;
}

//int Person::pullSuit()
//{
//	return rand() % 4 + 1;
//}

void Person::InputCard(Deck* deck)
{
	cardNum[sumCard] = deck->alreadyPublishedCard[deck->sumTurn];
	//cardSuit[i] = pullSuit();
	sumCard++;
	deck->sumTurn++;
}

//int Person::getCardNum(int i) const
//{
//	return cardNum[i];
//}

//void Person::setSumCard()
//{
//	sumCard++;
//}

//void Person::ShowCard(bool firstDealer)
//{
//	int size = 1;
//	if (!firstDealer)
//	{
//		size = sumCard;
//	}
//	for (int i = 0; i < size; i++)
//	{
//		int suit = cardNum[i] / 13;
//		int num = cardNum[i] % 13;
//		Deck::ShowSuitAndNum(suit, num);
//
//		/*switch (suit)
//		{
//		case Deck::DIAMONDS:
//			cout << "ダイヤの" << flush;
//			break;
//		case Deck::HEART:
//			cout << "ハートの" << flush;
//			break;
//		case Deck::SPADE:
//			cout << "スペードの" << flush;
//			break;
//		case Deck::CLUB:
//			cout << "クラブの" << flush;
//			break;
//		default:
//			break;
//		}
//		switch (num)
//		{
//		case Deck::A:
//			cout << "A, " << flush;
//			break;
//
//		case Deck::J:
//			cout << "J, " << flush;
//			break;
//
//		case Deck::Q:
//			cout << "Q, " << flush;
//			break;
//
//		case Deck::K:
//			cout << "K, " << flush;
//			break;
//		default:
//			cout << num << ", " << flush;
//			break;
//		}*/
//	}
//}
//
//void Person::inputSumScore()
//{
//	sumScore = 0;
//	for (int i = 0; i < sumCard; i++) sumScore += cardScore[i];
//}

void Person::PullCardScore()
{
	sumScore = 0;
	for (int i = 0; i < sumCard; i++)
	{
		int num = cardNum[i] % 13;
		switch (num)
		{
		case Deck::A:
			sumScore += 11;
			break;

		case Deck::J:
		case Deck::Q:
		case Deck::K:
			sumScore += 10;
			break;
		default:
			sumScore += num;
			break;
		}
	}
	if (sumScore > 21)
	{
		for (int i = 0; i < sumCard; i++)
		{
			int num = cardNum[i] % 13;
			switch (num)
			{
			case Deck::A:
				sumScore -= 10;
				if (sumScore < 22)
				{
					return;
				}
				break;
			default:
				break;
			}
		}
	}
}

//bool Person::changeAce()
//{
//	for (int i = 0; i < sumCard; i++)
//	{
//		if (cardNum[i] % 13 == A && cardScore[i] == 11)
//		{
//			cardScore[i] = 1;
//			inputSumScore();
//			return true;
//		}
//	}
//	return false;
//}

bool Person::JudgeBurst() // true ならバースト、false なら続行
{
	//bool discoverAce;
	if (sumScore >= 22)
	{
		/*discoverAce = changeAce();
		if (!discoverAce) */
		return true;
	}
	return false;
}

int Person::GetScore() const
{
	return sumScore;
}