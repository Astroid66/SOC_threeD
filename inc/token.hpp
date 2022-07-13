#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <string>

namespace Lex
{

class Token
{

public:
	std::string lexeme;
	Token(const std::string str1 ) { lexeme = str1;}

	~Token() = default;

	std::string stringRepresentation() const { return lexeme; }
};

}

#endif // _TOKEN_H_
