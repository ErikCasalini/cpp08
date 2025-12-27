#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template < typename type, typename container = std::deque<type> >
class MutantStack : public std::stack<type, container>
{

public:

	MutantStack(void)
	{}

	~MutantStack(void)
	{}

	MutantStack(const MutantStack &src)
	: std::stack<type, container>(src)
	{}

	MutantStack	&operator=(const MutantStack &rhs)
	{
		if (this != &rhs)
			std::stack<type, container>::operator=(rhs);
		return (*this);
	}

	typedef typename container::iterator iterator;
	typedef typename container::const_iterator const_iterator;
	typedef typename container::reverse_iterator reverse_iterator;
	typedef typename container::const_reverse_iterator const_reverse_iterator;

	iterator	begin(void)
	{
		return (this->c.begin());
	}
	const_iterator	begin(void) const
	{
		return (this->c.begin());
	}

	iterator	end(void)
	{
		return (this->c.end());
	}
	const_iterator	end(void) const
	{
		return (this->c.end());
	}

	reverse_iterator	rbegin()
	{
		return (this->c.rbegin());
	}
	const_reverse_iterator	rbegin() const
	{
		return (this->c.rbegin());
	}

	reverse_iterator	rend()
	{
		return (this->c.rend());
	}
	const_reverse_iterator	rend() const
	{
		return (this->c.rend());
	}
};

#endif
