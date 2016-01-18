//
// Created by User on 12/10/15.
//

#include "Food.h"

namespace Gaming {
    const char Food::FOOD_ID = 'F';

    Food::Food(const Game &g, const Position &p, double capacity): Resource(g, p, capacity), __capacity(capacity), __id(generateID()) {}

    void Food::print(std::ostream &os) const { os << FOOD_ID << __id; }
}
