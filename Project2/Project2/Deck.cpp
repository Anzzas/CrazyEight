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

const std::vector<Card>& Deck::getDeck() const
{
	return m_deck;
}

void Deck::resetDeck(PlayPile& pile)
{
	for (const auto& e : pile.) //
	{

	}
}