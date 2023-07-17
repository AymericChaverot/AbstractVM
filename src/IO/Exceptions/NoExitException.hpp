/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** NoExitException
*/

#ifndef NOEXITEXCEPTION_HPP_
#define NOEXITEXCEPTION_HPP_

#include <exception>

namespace avm {
    class NoExitException : public std::exception {
        public:
            const char *what() const noexcept override;
    };
}

#endif /* !NOEXITEXCEPTION_HPP_ */
