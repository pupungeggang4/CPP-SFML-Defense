#pragma once
#include <general.hpp>

class Game : public std::enable_shared_from_this<Game> {
    public:
        shared_ptr<Game> self;
        sf::RenderWindow window; unsigned int width, height;
        sf::View view;
        bool running = true;

        Game();
        void init();
        void run();
        void handleInput();
        void handleScene();
};
