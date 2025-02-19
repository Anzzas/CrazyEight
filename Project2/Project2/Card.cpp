#include "Card.h"
#include <array>
#include <string>

const Card::Value& Card::getValue() const
{
	return m_value;
}

const Card::Color& Card::getColor() const
{
	return m_color;
}

Card& Card::operator= (const Card& card)
{
	this->m_color = card.m_color;
	this->m_value = card.m_value;

	return *this;
}

const bool Card::isCardMatching(const Card& card2) const
{
	if ((m_color == card2.getColor()) || (m_value == card2.getValue()) || (m_value == Value::eight))
	{
		return true;
	}
	return false;
}

std::ostream& operator<< (std::ostream& out, const Card& card)
{
	out << card.getValue() << " of " << card.getColor();
	return out;
}

std::ostream& operator<< (std::ostream& out, const Card::Value& value)
{
	const std::array<const std::string, Card::max_values> names{ "ace", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king" };
	static_assert(std::size(names) == Card::max_values);

	out << names[value];
	return out;
}

std::ostream& operator<< (std::ostream& out, const Card::Color& color)
{
	const std::array<const std::string, Card::max_colors> names{ "club", "diamond", "spade", "heart" };
	static_assert(std::size(names) == Card::max_colors);

	out << names[color];
	return out;
}