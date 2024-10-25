#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "actions/action_interface.hpp"

#include <list>

namespace ctr {

class Controller {
    public:
        Controller();

    public:
        void runAction(std::shared_ptr<IAction> action);
        void undo();
        void redo();

        void setActiveSlide(ID idx);
        ID getActiveSlideIdx();
    
    private:
        const int maxCount_ = 6;
        std::list<std::shared_ptr<IAction> > actions_;
        std::list<std::shared_ptr<IAction> >::iterator currPosIter_;
        std::shared_ptr<Slide> activeSlide_;
};

}

#endif