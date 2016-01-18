//
// Created by User on 12/10/15.
//

#include "Exceptions.h"

namespace Gaming {
    std::ostream &operator<<(std::ostream &os, const GamingException &ex) {
        std::cout << ex.__name;

        return os;
    }

    DimensionEx::DimensionEx(unsigned expWidth, unsigned expHeight, unsigned width, unsigned height) {
        __exp_height = expHeight;
        __exp_width = expWidth;

        __width = width;
        __height = height;

        setName("DimensionEx");
    }
}
