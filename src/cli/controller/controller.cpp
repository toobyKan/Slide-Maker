#include "controller.hpp"
#include <iostream>

namespace cli {

Controller::Controller() : factory{std::make_unique<CommandFactory>()} {}

void Controller::start(std::istream& stream) {
    try {
        while (true) {
            auto command = fetch(stream);
            execute(command);
        }
    } catch (const std::exception& err) {
        std::cerr << err.what() << "\n";
    }
}

Controller::CommandPtr Controller::fetch(std::istream& stream) {
    std::string input;
    std::getline(stream, input);
    return factory->createCommand(input);
}

void Controller::execute(CommandPtr& command) {
    command->execute();
}

}  // namespace cli
