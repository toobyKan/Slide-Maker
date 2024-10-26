#ifndef PARSER
#define PARSER

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <regex>
#include <stdexcept>

class CommandParser {
public:
    // Validate that tokens contain only allowed characters
    static void validateToken(const std::string& token) {
        static const std::regex validPattern("[A-Za-z0-9_\\-]+");
        if (!std::regex_match(token, validPattern)) {
            throw std::invalid_argument("Invalid token: " + token);
        }
    }

    // Tokenize the input stream and return a vector of valid tokens
    static std::vector<std::string> tokenize(std::istream& input) {
        std::vector<std::string> tokens;
        std::string token;

        while (input >> token) {
            validateToken(token);  // Validate each token
            tokens.push_back(token);
        }

        if (tokens.empty()) {
            throw std::invalid_argument("No valid tokens found.");
        }

        return tokens;
    }
};


#endif 