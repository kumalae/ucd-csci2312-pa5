//
// Created by User on 12/10/15.
//

#include "Advantage.h"

namespace Gaming {
    const char Advantage::ADVANTAGE_ID = 'D';
    const double Advantage::ADVANTAGE_MULT_FACTOR = 2.0;

    Advantage::Advantage(const Game &g, const Position &p, double capacity) : Resource(g, p, capacity * ADVANTAGE_MULT_FACTOR), __id(generateId()) {}

    void Advantage::print(std::ostream &os) const { os << ADVANTAGE_ID << __id; }

    double Advantage::consume() {
        double advantageCapacity = __capacity * ADVANTAGE_MULT_FACTOR;

        __capacity = 0;

        finish();

        return advantageCapacity;
    }
}
