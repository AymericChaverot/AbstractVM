/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** Underflow
*/

#pragma once

#include <exception>

namespace avm {
    class UnderflowException : public std::exception {
        public:
            const char *what() const noexcept override;
    };
}
