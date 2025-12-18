#ifndef SPAN_HPP
# define SPAN_HPP

# include <deque>
# include <iterator>
# include <stdexcept>
# include <cmath>

class Span
{

public:

					Span(void);
					Span(const unsigned int N);
					~Span(void);
					Span(const Span &src);
	Span			& operator=(const Span &rhs);
	void			addNumber(int value);
	unsigned int	shortestSpan(void) const;
	unsigned int	longestSpan(void) const;
	unsigned int	getNelem(void) const;
	unsigned int	getMax(void) const;

	template <typename T>
	void	addRange(typename T::iterator begin, typename T::iterator end)
	{
		if (std::abs(std::distance(begin, end)) + nelem_ > max_)
			throw (std::out_of_range("Not enought space to add range"));
		elements_.insert(elements_.end(), begin, end);
	}

private:

	std::deque<int>		elements_;
	const unsigned int	max_;
	unsigned int		nelem_;
};

#endif
