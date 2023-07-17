/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** CommandHandler
*/

#ifndef COMMANDHANDLER_HPP_
#define COMMANDHANDLER_HPP_

#include "Processing/Exceptions/UnknownInstructionException.hpp"
#include "Processing/Exceptions/SyntaxException.hpp"

namespace avm {
    enum eCommand {
        PUSH_,
        POP_,
        CLEAR_,
        DUP_,
        SWAP_,
        DUMP_,
        ASSERT_,
        ADD_,
        SUB_,
        MUL_,
        DIV_,
        MOD_,
        LOAD_,
        STORE_,
        PRINT_,
        EXIT_,
        UNKNOWN_COMMAND_
    };

    enum eParamType {
        INT_8,
        INT_16,
        INT_32,
        FLOAT_,
        DOUBLE_,
        UNKNOWN_TYPE_
    };

    typedef struct asm_command_s {
        std::string name;
        std::string value;
    } asm_command_t;

    typedef struct command_param_s {
        int type;
        std::string value;
    } command_param_t;

    typedef struct command_s {
        eCommand type;
        command_param_t param;
    } command_t;

    class CommandHandler {
        public:
            CommandHandler() = default;
            ~CommandHandler() = default;

            command_t run(const asm_command_t &command);
        private:
            int getParamType(const std::string &value);
            std::string getParamValue(const std::string &value);
            command_t push(const asm_command_t &command);
            command_t pop();
            command_t clear();
            command_t dup();
            command_t swap();
            command_t dump();
            command_t assert(const asm_command_t &command);
            command_t add();
            command_t sub();
            command_t mul();
            command_t div();
            command_t mod();
            command_t load(const asm_command_t &command);
            command_t store(const asm_command_t &command);
            command_t print();
            command_t exit();
    };
}

#endif /* !COMMANDHANDLER_HPP_ */
