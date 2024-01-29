#include "../includes/booleFunctions.hpp"

using namespace ft;

int main()
{

	while (true)
	{
		std::cout << "insert a boolean formula : ";
		std::string	input;
		if (!getline(std::cin, input))
		{
			std::cin.clear();
			clearerr(stdin);
		}
		if (input == "quit" || input == "exit" || input == "end" || input == "tg")
			break;
		std::string	ficelle = conjunctiveNormalForm(input);
		if (!ficelle.empty())
		{
			std::cout << ficelle;
			if (_hasUpperCase(ficelle)) {
				std::cout << " which has as truth table : \n";
				printTruthTable(ficelle);
			}
			else
			{
				std::cout << " which has as boolean evaluation : ";
				std::pair<bool, bool>	result = booleanEvaluation(ficelle);
				if (result.first)
					std::cout << "true.\n";
				else
					std::cout << "false.\n";
			}
		}
		else
			std::cout << "your formula \"" << input << "\" has incorrect syntax.\nOperator allowed are \"&|=^>\",\n"
													   "negation term allowed is '!'"
													   "numbers allowed are '1' or '0'\n"
													   "variables allowed are uppercase between 'A' and 'Z' (both included)\n"
													   "then, beware having one operator less than numbers + variables\n"
													   "example : AP!|B10&!=^!!! is an ugly but correct syntax\n";
	}

	return 0;
}