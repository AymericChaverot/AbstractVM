/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** AssertFailException
*/

#ifndef ASSERTFAILEXCEPTION_HPP_
#define ASSERTFAILEXCEPTION_HPP_

#include <exception>

namespace avm {
    class AssertFailException : public std::exception {
        public:
            AssertFailException() = default;
            ~AssertFailException() override = default;

            const char *what() const noexcept override;
    };
}

#endif /* !ASSERTFAILEXCEPTION_HPP_ */
