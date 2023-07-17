/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** CantLoadException
*/

#ifndef CANTLOADEXCEPTION_HPP_
#define CANTLOADEXCEPTION_HPP_

#include <exception>

namespace avm {
    class CantLoadException : public std::exception {
        public:
            const char *what() const noexcept override;
    };
}

#endif /* !CANTLOADEXCEPTION_HPP_ */
