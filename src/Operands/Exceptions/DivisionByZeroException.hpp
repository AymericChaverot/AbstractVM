/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** DivisionByZeroException
*/

#pragma once

#include <exception>

namespace avm {
    class DivisionByZeroException : public std::exception {
        public:
            const char *what() const noexcept override;
    };
}
