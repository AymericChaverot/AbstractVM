/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** CantOpenFileException
*/

#include "CantOpenFileException.hpp"

avm::CantOpenFileException::CantOpenFileException(const std::string &filename)
{
    _filename = filename;
}

const char *avm::CantOpenFileException::what() const noexcept
{
    return (_filename.c_str());
}
