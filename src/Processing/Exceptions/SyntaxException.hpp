/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** SyntaxException
*/

#ifndef SYNTAXEXCEPTION_HPP_
#define SYNTAXEXCEPTION_HPP_

#include <exception>
#include <string>

namespace avm {
    class SyntaxException : public std::exception {
        public:
            SyntaxException(const std::string &instruction);
            ~SyntaxException() = default;

            const char *what() const noexcept override;

        private:
            std::string _instruction;
    };
}

#endif /* !SYNTAXEXCEPTION_HPP_ */
