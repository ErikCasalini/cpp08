#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iterator>


template <typename T>
typename T::iterator	easyfind(T &container, const int value)
{
	return (std::find(container.begin(), container.end(), value));
}

#endif
