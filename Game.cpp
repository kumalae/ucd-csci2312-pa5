//
// Created by User on 12/10/15.
//

#include "Game.h"
#include "Exceptions.h"

namespace Gaming {
    const unsigned int Game::NUM_INIT_AGENT_FACTOR = 4;
    const unsigned int Game::NUM_INIT_RESOURCE_FACTOR = 2;
    const unsigned Game::MIN_WIDTH = 3;
    const unsigned Game::MIN_HEIGHT = 3;
    const double Game::STARTING_AGENT_ENERGY = 20;
    const double Game::STARTING_RESOURCE_CAPACITY = 10;

    Game::Game() : __numInitAgents(0), __numInitResources(0), __width(3), __height(3), __verbose(true), __round(0), __status(NOT_STARTED) {
        __grid.reserve(getNumPieces());

        for (int i=0; i<getNumPieces(); i++)
            __grid[i] = nullptr;
    }

    Game::Game(const Game &another) : __numInitAgents(another.__numInitAgents), __numInitResources(another.__numInitResources), __width(another.__width), __height(another.__height), __verbose(another.__verbose), __round(another.__round), __status(another.__status) {}

    Game::Game(unsigned width, unsigned height, bool manual) : __round(0), __status(NOT_STARTED), __verbose(true) {
        __grid.reserve(getNumPieces());

        if ((width >= MIN_WIDTH) || (height >= MIN_HEIGHT)) {
            __width = width;
            __height = height;
        } else {
            InsufficientDimensionsEx exception(MIN_WIDTH, MIN_HEIGHT, width, height);
            throw exception;
        }

        if (manual) {
            __numInitAgents = 0;
            __numInitResources = 0;
        } else
            populate();

        __grid.reserve(getNumPieces());
        for (int i=0; i<getNumPieces(); i++)
            __grid[i] = nullptr;
    }

    Game::~Game() : __status(OVER), __verbose(false) {
        for (int i=0; i<getNumPieces(); i++)
            __grid[i] = nullptr;

        __grid.clear();
    }

    void Game::populate() {
    }
}
