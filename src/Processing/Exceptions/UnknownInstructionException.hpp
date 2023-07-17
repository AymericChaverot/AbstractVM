/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** UnknownInstructionException
*/

#ifndef UNKNOWNINSTRUCTIONEXCEPTION_HPP_
#define UNKNOWNINSTRUCTIONEXCEPTION_HPP_

#include <exception>
#include <string>

namespace avm {
    class UnknownInstructionException : public std::exception {
        public:
            UnknownInstructionException(const std::string &instruction);
            ~UnknownInstructionException() = default;

            const char *what() const noexcept override;

        private:
            std::string _instruction;
    };
}

#endif /* !UNKNOWNINSTRUCTIONEXCEPTION_HPP_ */
