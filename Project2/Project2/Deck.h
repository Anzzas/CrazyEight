#ifndef DECK_H
#define DECK_H
#include <vector>
#include "Random.h"
#include "Card.h"
#include <algorithm>

class Deck
{
public:

	Deck()
		: m_deck{}
	{
		for (int color{ 0 }; color < Card::max_colors; color++)
		{
			for (int value{ 0 }; value < Card::max_values; value++)
			{
				m_deck.emplace_back(Card{ static_cast<Card::Value>(value), static_cast<Card::Color>(color) });
			}
		}
	}

	void shuffleDeck();
	const Card TakeCard();

private:

	const int m_maxCards{ 52 };

protected:

	std::vector<Card> m_deck;
};

#endif