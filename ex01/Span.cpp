#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <utility>
#include <deque>
#include <vector>

/* CONSTRUCTORS/DESTRUCTORS */

Span::Span(void)
: max_(0), nelem_(0)
{}

Span::Span(const unsigned int N)
: max_(N), nelem_(0)
{}

Span::~Span(void)
{}

Span::Span(const Span &src)
: max_(src.max_), nelem_(src.nelem_), elements_(src.elements_)
{}

/* OPERATORS */

Span	& Span::operator=(const Span &rhs)
{
	if (this != &rhs) {
		if (rhs.max_ >= max_) {
			nelem_ = rhs.nelem_;
			elements_ = rhs.elements_;
		}
		else
			throw (std::out_of_range("Copy inside smaller span"));
	}
	return (*this);
}

/* MEMBER FUNCTIONS */

unsigned int	Span::getMax(void) const
{
	return (max_);
}

unsigned int	Span::getNelem(void) const
{
	return (nelem_);
}

void	Span::addNumber(const int value)
{
	if (nelem_ >= max_)
		throw (std::out_of_range("Span max size already reached"));
	elements_.push_back(value);
	nelem_++;
}

unsigned int	Span::shortestSpan(void) const
{
	std::vector<int> temp(nelem_);
	if (nelem_ < 2)
		throw (std::logic_error("Not enought elements to calculate a span)"));
	std::sort(elements_.begin(), elements_.end());
	std::adjacent_difference(elements_.begin(), elements_.end(), temp);
	return (*std::min_element(temp.begin(), temp.end()));
}

unsigned int	Span::longestSpan(void) const
{
	if (nelem_ < 2)
		throw (std::logic_error("Not enought elements to calculate a span)"));
	return (std::abs(std::max_element(elements_.begin(), elements_.end()) - std::max_element(elements_.begin(), elements_.end())));
}

