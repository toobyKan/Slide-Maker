#ifndef COMMAND_HPP
#define COMMAND_HPP
#include <iostream>
#include <memory>
#include "../../document/document.hpp"
#include "../../document/slide.hpp"


class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

class AddShapeCommand : public Command {
public:
    void execute() override;
};

class DeleteShapeCommand : public Command {
public:
    void execute() override;
};

class DeleteSlideCommand : public Command {
public:
    DeleteSlideCommand(std::shared_ptr<doc::Document> doc, size_t slideId);
    void execute() override;

private:
    std::shared_ptr<doc::Document> document;
    size_t id;
};

class AddSlideCommand : public Command {
public:
    explicit AddSlideCommand(std::shared_ptr<doc::Document> doc);
    void execute() override;

private:
    std::shared_ptr<doc::Document> document;
};

#endif