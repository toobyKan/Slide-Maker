// CommandFactory.cpp
#include "command_factory.hpp"
#include "command.hpp"
#include <stdexcept>

CommandFactory::CommandFactory() {
    // Register commands with their corresponding creators
    registerCommand("add shape", []() { return std::make_unique<AddShapeCommand>(); });
    registerCommand("delete shape", []() { return std::make_unique<DeleteShapeCommand>(); });
}

void CommandFactory::registerCommand(const std::string& name, CommandCreator creator) {
    commandMap[name] = std::move(creator);
}

std::unique_ptr<Command> CommandFactory::createCommand(const std::string& input) {
    auto it = commandMap.find(input);
    if (it != commandMap.end()) {
        return it->second();  // Call the creator function
    }
    throw std::invalid_argument("Invalid command");
}
