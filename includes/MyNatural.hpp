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

		MyNatural() {
			for (int i = 0; i < _bitSize; ++i)
				_n[i] = false;
		}
		MyNatural(unsigned int n) {
			unsigned int	compareTo = 1;
			for (int i = 0; i < _bitSize; ++i)
			{
				_n[_bitSize - 1 - i] = n & compareTo;
				compareTo <<= 1;
			}
		}
		MyNatural(const MyNatural &other) {*this = other;}
		MyNatural	&operator=(const MyNatural &other)
		{
			for (int i = 0; i < _bitSize; ++i)
				_n[i] = other._n[i];
			return *this;
		}

		//GETTER

		const bool	*getData() const {return _n;}
		const int	getSize() const {return _bitSize;}
		unsigned int	getUnsignedInt() const
		{
			unsigned int	displayable = 0;
			unsigned int	constructor = 1;
			for (int i = 0; i < _bitSize; ++i)
			{
				if (_n[_bitSize - 1 - i])
					displayable |= constructor;
				constructor <<= 1;
			}
			return displayable;
		}

		//OPERATORS OVERLOADS

		MyNatural	&operator+=(const MyNatural &rhs)
		{
			for (int i = _bitSize - 1; i >= 0; --i)
			{
				if (rhs._n[i])
				{
					if (!_n[i])
						_n[i] = true;
					else
					{
						int j = i;
						while (_n[j] && j >= 0)
						{
							_n[j] = false;
							--j;
						}
						if (j >= 0)
							_n[j] = true;
					}
				}
			}
			return *this;
		}

	};

	std::ostream	&operator<<(std::ostream &o, const MyNatural &n)
	{
		unsigned int	displayable = 0;
		unsigned int	constructor = 1;
		int	bitSize = n.getSize();
		const bool	*data = n.getData();
		o << '[';
		for (int i = 0; i < bitSize; ++i)
		{
			if (i && (!(i % 4)))
				o << ' ';
			o << data[i];
			if (data[bitSize - 1 - i])
				displayable |= constructor;
			constructor <<= 1;
		}
		o << "] = " << displayable;
		return o;
	}

}

#endif