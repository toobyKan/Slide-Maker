#ifndef COMMAND_FACTORY_HPP
#define COMMAND_FACTORY_HPP

#include <memory>
#include <string>
#include <string>
#include <unordered_map>
#include <functional>

#include "command.hpp"

class CommandFactory {
public:
    using CommandCreator = std::function<std::unique_ptr<Command>()>;

    CommandFactory();
    std::unique_ptr<Command> createCommand(const std::string& input);

private:
    std::unordered_map<std::string, CommandCreator> commandMap;
    void registerCommand(const std::string& name, CommandCreator creator);
};

#endif
