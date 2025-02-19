#include "Deck.h"

void Deck::shuffleDeck()
{
	std::shuffle(m_deck.begin(), m_deck.end(), Random::mt); // Shuffle and randomize the deck
}

const Card Deck::TakeCard() // take the top card from the deck's pile
{
	Card temp{ m_deck.back() };
	m_deck.pop_back();

	return temp;
}