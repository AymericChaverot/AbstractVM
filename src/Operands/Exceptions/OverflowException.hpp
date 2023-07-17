/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** Overflow
*/

#pragma once

#include <exception>

namespace avm {
    class OverflowException : public std::exception {
        public:
            const char *what() const noexcept override;
    };
}
