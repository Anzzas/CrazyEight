#include "PlayPile.h"

void PlayPile::putCard(const Card& card)
{
	m_pile.emplace_back(card);
}

const Card& PlayPile::getTopCard() const
{
	return m_pile.back();
}