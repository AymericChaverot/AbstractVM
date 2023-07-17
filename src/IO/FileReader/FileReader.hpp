/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** FileReader
*/

#ifndef FILEREADER_HPP_
#define FILEREADER_HPP_

#include <fstream>
#include <vector>

#include "IO/IOComponent.hpp"
#include "IO/Exceptions/CantOpenFileException.hpp"
#include "IO/Exceptions/NoExitException.hpp"
#include "Processing/Exceptions/UnknownInstructionException.hpp"

namespace avm {
    class FileReader : public IOComponent {
        public:
            FileReader(const std::string &filename);
            ~FileReader() = default;

            bool isInput() const override;

            std::string getLine() override;
            void putLine(const std::string &line) override;

        private:
            void checkProgram() const;
            bool isLineOk(const std::string &line) const;
            std::vector<std::string> _lines;
            unsigned int _current_line;
            std::ifstream _file;
    };
}

#endif /* !FILEREADER_HPP_ */
