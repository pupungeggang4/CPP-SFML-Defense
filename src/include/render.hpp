#pragma once
#include <general.hpp>

class Game;
class Render {
    public:
        static void renderMenu(sf::RenderTarget&, shared_ptr<Game>);
        static void renderText(sf::RenderTarget&, sf::Text&, sf::String, std::vector<float>);
        static void renderRect(sf::RenderTarget&, sf::RectangleShape&, std::vector<float>, float);
        static void renderSprite(sf::RenderTarget&, sf::Sprite&, std::vector<float>);
};
