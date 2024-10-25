#ifndef GRAPHICS_RENDERER_HPP
#define GRAPHICS_RENDERER_HPP

class IGraphicsRenderer {
public:
    virtual ~IGraphicsRenderer() {}

    virtual bool initialize() = 0;
    virtual void render() = 0;
    virtual void clearScreen() = 0;
    virtual void presentScreen() = 0;
};

#endif
