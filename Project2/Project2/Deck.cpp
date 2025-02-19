#include "Deck.h"

void Deck::shuffle()
{
	std::shuffle(m_deck.begin(), m_deck.end(), Random::mt); // Shuffle and randomize the deck
}

const Card Deck::TakeCard() // take the top card from the deck's pile
{
	Card temp{ m_deck.back() };
	m_deck.pop_back();

	return temp;
}

const std::vector<Card>& Deck::getDeck() const
{
	return m_deck;
}

void Deck::reset()
{
	for (int color{ 0 }; color < Card::max_colors; color++)
	{
		for (int value{ 0 }; value < Card::max_values; value++)
		{
			m_deck.emplace_back(Card{ static_cast<Card::Value>(value), static_cast<Card::Color>(color) });
		}
	}
}