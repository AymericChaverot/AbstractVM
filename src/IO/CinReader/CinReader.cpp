/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** CinReader
*/

#include "CinReader.hpp"

avm::CinReader::CinReader()
{
    _lines.clear();
    _current_line = 0;
}

bool avm::CinReader::isInput() const
{
    return true;
}

std::string avm::CinReader::getLine()
{
    if (_lines.empty()) {
        std::string line;
        std::vector<std::string> lines;

        while (1) {
            std::getline(std::cin, line);
            if (line == ";;" || std::cin.eof())
                break;
            if (line != "" && isLineOk(line))
                lines.push_back(line);
        }
        _current_line = 0;
        _lines = lines;
        checkProgram();
    }
    if (_current_line == _lines.size())
        throw NoExitException();
    return (_lines[_current_line++]);
}

void avm::CinReader::putLine(const std::string &line)
{
    (void)line;
}

void avm::CinReader::checkProgram() const
{
    bool isExit = false;

    for (auto &lines : _lines) {
        if (lines == "exit")
            isExit = true;
    }
    if (!isExit)
        throw avm::NoExitException();
}

bool avm::CinReader::isLineOk(const std::string &line) const
{
    if (line.find("push") != std::string::npos ||
        line.find("pop") != std::string::npos ||
        line.find("clear") != std::string::npos ||
        line.find("dup") != std::string::npos ||
        line.find("swap") != std::string::npos ||
        line.find("dump") != std::string::npos ||
        line.find("assert") != std::string::npos ||
        line.find("add") != std::string::npos ||
        line.find("sub") != std::string::npos ||
        line.find("mul") != std::string::npos ||
        line.find("div") != std::string::npos ||
        line.find("mod") != std::string::npos ||
        line.find("load") != std::string::npos ||
        line.find("store") != std::string::npos ||
        line.find("print") != std::string::npos ||
        line.find("exit") != std::string::npos ||
        line == "\n" ||
        line[0] == ';')
        return true;
    throw UnknownInstructionException(line + " is not a valid instruction");
}
