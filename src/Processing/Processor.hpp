/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** Processor
*/

#ifndef PROCESSOR_HPP_
#define PROCESSOR_HPP_

#include <ctime>
#include <unistd.h>
#include "CommandHandler/CommandHandler.hpp"

namespace avm {
    class Processor {
        public:
            Processor(const unsigned int &frequency = 0);
            ~Processor() = default;

            command_t run(const std::string &line);
        private:
            void applyFrequency();
            CommandHandler _command_handler;
            struct timespec _time_start;
            struct timespec _time_end;
            unsigned int _frequency;
            long long int _loop_nb;
    };
}

#endif /* !PROCESSOR_HPP_ */
