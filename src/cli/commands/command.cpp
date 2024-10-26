#include "command.hpp"


void AddShapeCommand::execute() {
    std::cout << "Shape added.\n";
}

void DeleteShapeCommand::execute() {
    std::cout << "Shape deleted.\n";
}

AddSlideCommand::AddSlideCommand(std::shared_ptr<doc::Document> doc)
    : document(std::move(doc)) {}

void AddSlideCommand::execute() {
    auto newSlide = std::make_shared<Slide>(); 
    document->add(newSlide);
    std::cout << "New slide added.\n";
}