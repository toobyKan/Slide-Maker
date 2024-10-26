#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <iostream>
#include <memory>
#include <string>

#include "../commands/command.hpp"
#include "../commands/command_factory.hpp"


namespace cli {

    class Controller {
    public:
        using CommandPtr = std::unique_ptr<Command>;

        Controller();
        void start(std::istream& stream);

    private:
        std::unique_ptr<CommandFactory> factory;
        CommandPtr fetch(std::istream& stream);

        void execute(CommandPtr& command);
    };
} 


#endif