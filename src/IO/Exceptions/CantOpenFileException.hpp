/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** CantOpenFileException
*/

#ifndef CANTOPENFILEEXCEPTION_HPP_
#define CANTOPENFILEEXCEPTION_HPP_

#include <exception>
#include <string>

namespace avm {
    class CantOpenFileException : public std::exception {
        public:
            CantOpenFileException(const std::string &filename);
            ~CantOpenFileException() = default;

            const char *what() const noexcept override;

        private:
            std::string _filename;
    };
}

#endif /* !CANTOPENFILEEXCEPTION_HPP_ */
