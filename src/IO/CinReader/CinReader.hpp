/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** CinReader
*/

#ifndef CINREADER_HPP_
#define CINREADER_HPP_

#include <iostream>
#include <vector>

#include "IO/Exceptions/NoExitException.hpp"
#include "Processing/Exceptions/UnknownInstructionException.hpp"
#include "IO/IOComponent.hpp"

namespace avm {
    class CinReader : public IOComponent {
        public:
            CinReader();
            ~CinReader() = default;

            bool isInput() const override;

            std::string getLine() override;
            void putLine(const std::string &line) override;
        private:
            void checkProgram() const;
            bool isLineOk(const std::string &line) const;
            std::vector<std::string> _lines;
            unsigned int _current_line;
    };
}

#endif /* !CINREADER_HPP_ */
