#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <utility>
#include <deque>
#include <vector>

/* CONSTRUCTORS/DESTRUCTORS */

Span::Span(void)
: elements_(),
  max_(0),
  nelem_(0)
{}

Span::Span(const unsigned int N)
: elements_(),
  max_(N),
  nelem_(0)
{}

Span::~Span(void)
{}

Span::Span(const Span &src)
: elements_(src.elements_),
  max_(src.max_),
  nelem_(src.nelem_)
{}

/* OPERATORS */

Span	& Span::operator=(const Span &rhs)
{
	if (this != &rhs) {
		if (max_ >= rhs.nelem_) {
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

std::deque<int>::const_iterator	Span::getBegin(void) const
{
	return (elements_.begin());
}

std::deque<int>::const_iterator	Span::getEnd(void) const
{
	return (elements_.end());
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
	if (nelem_ < 2)
		throw (std::logic_error("Not enought elements to calculate a span"));

	std::vector<int>	temp_sort(elements_.begin(), elements_.end());
	std::vector<int>	diff_vec(nelem_);

	std::sort(temp_sort.begin(), temp_sort.end());
	std::adjacent_difference(temp_sort.begin(), temp_sort.end(), diff_vec.begin());
	return (*std::min_element(diff_vec.begin() + 1, diff_vec.end())); // We start at index 1 because adjacent_diff sets value[0] = origin_container[0]
}

unsigned int	Span::longestSpan(void) const
{
	if (nelem_ < 2)
		throw (std::logic_error("Not enought elements to calculate a span)"));
	return (std::abs(*std::max_element(elements_.begin(), elements_.end()) - *std::min_element(elements_.begin(), elements_.end())));
}

/* NON MEMBER FUNCTIONS */

std::ostream	&operator<<(std::ostream &stream, const Span &rhs)
{
	std::deque<int>::const_iterator elem_it = rhs.getBegin();
	
	for (; elem_it != rhs.getEnd(); elem_it++)
		stream << *elem_it << " ";
	return (stream);
}
