#ifndef _LEXER_H_
#define _LEXER_H_

#include <vector>
#include "token.hpp"
#include<string>
#include<cstring>
#include<iostream>

using namespace std;
namespace Lex
{

class Lexer
{
public:
	string str;
	int pos;
	Lexer() = default;
	~Lexer() = default;

	void setTranslationUnit(const std::string& translationUnit) {	str = translationUnit; pos=0;}
	Token lexNextToken();
	Token identifier_or_type();
	Token number();
    Token string_lit();
    Token ret();

	bool eof() const { 
		if(str[pos]=='\0')
			return true;
		return false;
	}
};

bool is_space(char c) noexcept {
  switch (c) {
    case ' ':
    case '\t':
    case '\r':
    case '\n':
      return true;
    default:
      return false;
  }
}

bool is_char(char c) noexcept {
  switch (c) {
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
    case 'I':
    case 'J':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'O':
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '_':
    case '*':
    case '\"':
      return true;
    default:
      return false;
  }
}

bool is_digit(char c) noexcept {
  switch (c) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      return true;
    default:
      return false;
  }
}

Token Lexer::lexNextToken(){
    while (is_space(str[pos++]));

    switch (str[pos-1]) {
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
        case 'h':
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'o':
        case 'p':
        case 'q':   
        case 'r':  
        case 's':
        case 't':
        case 'u':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
        case 'z':
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'H':
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
        case 'O':
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
        case 'T':
        case 'U':
        case 'V':
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':   return identifier_or_type();      
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':   return number();
        case '/':
                if (str[pos] == '/')
                    while( str[pos] != '\n'){
                        pos++;
                    };
                return Token("");
        case '(':   return Token("OPARA (");
        case ')':   return Token("CPARA )");
        case '[':   return Token("OSQUARE [");
        case ']':   return Token("CSQUARE ]");
        case '{':   return Token("OBRACE {");
        case '}':   return Token("CBRACE }");
        case '=':   return Token("OP_EQ =");
        case '+':   return Token("OP_PLUS +");
        case '-':   return Token("OP_MINUS -");
        case ',':   return Token("OP_COMMA ,");
        case ':':   return Token("COLON :");
        case ';':   return Token("SEMICOLON ;");
        case '\"':  return string_lit();
		default :   return Token("invalid ");
    }   
}

Token Lexer::identifier_or_type() {
	string word;
	int i=0;
    pos--;
	while(is_char(str[pos]))   { word+=str[pos++];}
	i=0;
	switch(word[i++]){
		case 'i': switch(word[i++]){
					case 'n': switch(word[i++]){
								case 't': return Token("TYPE int");			
								default : return Token("IDENT " + word);
							}
					default : return Token( "IDENT " + word);
				}
		case 'f': switch(word[i++]){
					case 'l': switch(word[i++]){
								case 'o':switch(word[i++]){
											case 'a': switch(word[i++]){
														case 't': return Token( "TYPE float");			
														default : return Token( "IDENT " + word);
													}		
											default : return Token( "IDENT " + word);
										}		
								default : return Token( "IDENT " + word);
							}
					default : return Token( "IDENT " + word);
				}
		case 'd': switch(word[i++]){
					case 'o': switch(word[i++]){
								case 'u':switch(word[i++]){
											case 'b': switch(word[i++]){
														case 'l': switch(word[i++]){
																	case 'e': return Token( "TYPE double");		
																	default : return Token( "IDENT " + word);
																}		  break;
														default : return Token( "IDENT " + word);
													}		
											default : return Token( "IDENT " + word);
										}		
								default : return Token( "IDENT " + word);
							}			
					default : return Token( "IDENT " + word);
				}
        case 'r': switch(word[i++]){
					case 'e': switch(word[i++]){
								case 't':switch(word[i++]){
											case 'u': switch(word[i++]){
														case 'r': switch(word[i++]){
																	case 'n': return Token( "RET return");		
																	default : return Token( "IDENT " + word);
																}		  break;
														default : return Token( "IDENT " + word);
													}		
											default : return Token( "IDENT " + word);
										}		
								default : return Token( "IDENT " + word);
							}			
					default : return Token( "IDENT " + word);
				}
		case 'c':switch(word[i++]){
					case 'h': switch(word[i++]){
								case 'a':switch(word[i++]){
											case 'r': switch(word[i++]){
                                                        case '*': return Token("TYPE char*");		
											            default : return Token( "IDENT " + word);
										            }
                                            default : return Token( "IDENT " + word);
                                        }
                                default : return Token( "IDENT " + word);
							}	
					case 'o':switch(word[i++]){
								case 'n': switch(word[i++]){
											case 's':switch(word[i++]){
														case 't': return Token( "CONST const");			
														default : return Token( "IDENT " + word);
													}		
											default : return Token( "IDENT " + word);
										}		
							}	
					default : return Token( "IDENT " + word);
				} 
		default : return Token( "IDENT " + word);
	}
}

Token Lexer::string_lit() {
    string word;
	int i=0;
    pos--;
	while(is_char(str[pos])) {  word+=str[pos++];}
    string word1 = "STRING_LITERAL ";
    word1.append(word);
	return Token(word1);
}

Token Lexer::number() {
	string word;
	int i=0;
    pos--;
	while(is_digit(str[pos]))   {   word+=str[pos++];}
    string word1 = "INT_LITERAL ";
    word1.append(word);
	return Token(word1);
}


}


#endif // _LEXER_H_