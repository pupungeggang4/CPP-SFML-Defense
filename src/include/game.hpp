#pragma once
#include <general.hpp>

class Scene;
class Game : public std::enable_shared_from_this<Game> {
    public:
        shared_ptr<Game> self;
        shared_ptr<Scene> scene;
        sf::RenderWindow window; unsigned int width, height;
        sf::View view;
        sf::RectangleShape rRect; sf::Font font; sf::Text rText = sf::Text(font, "", 32);
        bool running = true;

        Game();
        void init();
        void run();
        void handleInput();
        void handleScene();
};
