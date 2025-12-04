#pragma once
#include <general.hpp>

class Render {
    public:
        static void renderText(sf::RenderTarget&, sf::Text&, sf::String, std::vector<float>);
        static void renderRect(sf::RenderTarget&, sf::RectangleShape&, std::vector<float>, float);
        static void renderSprite(sf::RenderTarget&, sf::Sprite&, std::vector<float>);
};
