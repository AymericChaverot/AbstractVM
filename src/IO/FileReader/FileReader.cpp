/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** FileReader
*/

#include "FileReader.hpp"

avm::FileReader::FileReader(const std::string &filename)
{
    _file.open(filename);
    if (!_file.is_open())
        throw CantOpenFileException("Could not open " + filename);
}

bool avm::FileReader::isInput() const
{
    return true;
}

std::string avm::FileReader::getLine()
{
    if (_lines.empty()) {
        std::string line;

        while (std::getline(_file, line)) {
            if (line == ";;" || _file.eof())
                break;
            if (line != "" && isLineOk(line))
                _lines.push_back(line);
        }
        _current_line = 0;
        checkProgram();
    }
    return (_lines[_current_line++]);
}

void avm::FileReader::putLine(const std::string &line)
{
    (void)line;
}

void avm::FileReader::checkProgram() const
{
    bool isExit = false;

    if (_lines.size() == 0)
        throw avm::NoExitException();
    for (auto &lines : _lines) {
        if (lines == "exit")
            isExit = true;
    }
    if (!isExit)
        throw avm::NoExitException();
}

bool avm::FileReader::isLineOk(const std::string &line) const
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
