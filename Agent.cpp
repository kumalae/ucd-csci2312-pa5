//
// Created by User on 12/10/15.
//

#include "Agent.h"
#include "Resource.h"

namespace Gaming {
    const double Agent::AGENT_FATIGUE_RATE = 0.3;

    Agent::Agent(const Game &g, const Position &p, double energy) : Piece(g, p), __energy(energy) {}

    Piece &Agent::operator*(Piece &other) {
        bool valid = false;
        Piece *agent = (Agent *)(&other);
        Piece *resource = (Resource *)(&other);

        if (agent || resource) {
            if ((other.getType() == SIMPLE) || (other.getType() == STRATEGIC) || (other.getType() == FOOD) || (other.getType() == ADVANTAGE))
                return (other.interact(this));
        }

        return *this;
    }

    Piece &Agent::interact(Agent *agent) {
        if (__energy == agent->__energy) {
            agent->finish();
            finish();
        } else if (__energy < agent->__energy) {
            agent->__energy -= __energy;
            finish();
        } else if (__energy > agent->__energy) {
            agent->finish();
            __energy -= agent->__energy;
        }

        return *this;
    }

    Piece &Agent::interact(Resource *resource) {
        addEnergy(resource->consume());

        return *this;
    }

    void Agent::age() {
        __energy -= AGENT_FATIGUE_RATE;
    }
}
