#ifndef MYNAT
#define MYNAT

#include <iostream>

namespace ft
{
	class MyNatural
	{
	protected:

		bool		_n[32];
		const int	_bitSize = 32;

	public:

		MyNatural();
		MyNatural(unsigned int n);
		MyNatural(const MyNatural &other);
		MyNatural	&operator=(const MyNatural &other);

		//GETTER

		const bool	*getData() const;
		int	getSize() const;
		unsigned int	getUnsignedInt() const;

		//OPERATORS OVERLOADS

		MyNatural	&operator+=(const MyNatural &rhs);

	};

	std::ostream	&operator<<(std::ostream &o, const MyNatural &n);

}

#endif