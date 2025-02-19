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