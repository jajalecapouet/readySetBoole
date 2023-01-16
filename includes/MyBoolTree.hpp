#ifndef MYBOOL
#define MYBOOl

namespace ft
{

	class	BoolOperator
	{
	public:
		char op;

		BoolOperator(char c) : op(c) {}


	};

	struct	nodeBool
	{
		nodeBool	*father;
		nodeBool	*right;
		nodeBool	*left;
		bool		val;
		char 		boolOperator;
	};


}

#endif