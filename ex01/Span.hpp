#ifndef SPAN_HPP
# define SPAN_HPP

# include <deque>
# include <iterator>
# include <stdexcept>
# include <cmath>
# include <iostream>

class Span
{

public:

									Span(void);
									Span(const unsigned int N);
									~Span(void);
									Span(const Span &src);
	Span							& operator=(const Span &rhs);
	void							addNumber(int value);
	unsigned int					shortestSpan(void) const;
	unsigned int					longestSpan(void) const;
	unsigned int					getNelem(void) const;
	unsigned int					getMax(void) const;
	std::deque<int>::const_iterator	getBegin(void) const;
	std::deque<int>::const_iterator	getEnd(void) const;

	template <typename T>
	void	addRange(T begin, T end)
	{
		unsigned int	new_elems = std::abs(std::distance(begin, end)) + nelem_;
		if (new_elems > max_)
			throw (std::out_of_range("Not enough space to add range"));
		elements_.insert(elements_.end(), begin, end);
		nelem_ += new_elems;
	}

private:

	std::deque<int>		elements_;
	const unsigned int	max_;
	unsigned int		nelem_;
};

std::ostream	&operator<<(std::ostream &stream, const Span &rhs);

#endif
