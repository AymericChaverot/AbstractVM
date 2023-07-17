/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** EmptyStackPopException
*/

#ifndef EMPTYSTACKPOPEXCEPTION_HPP_
#define EMPTYSTACKPOPEXCEPTION_HPP_

#include <exception>

namespace avm {
    class EmptyStackPopException : public std::exception {
        public:
            EmptyStackPopException() = default;
            ~EmptyStackPopException() override = default;

            const char *what() const noexcept override;
    };
}

#endif /* !EMPTYSTACKPOPEXCEPTION_HPP_ */
