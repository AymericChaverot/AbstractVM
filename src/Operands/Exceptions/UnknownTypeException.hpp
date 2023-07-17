/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** UnknownTypeException
*/

#pragma once

#include <exception>

namespace avm {
    class UnknownTypeException : public std::exception {
        public:
            const char *what() const noexcept override;
    };
}
