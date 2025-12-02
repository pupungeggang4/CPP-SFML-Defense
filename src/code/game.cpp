#include <general.hpp>
#include <game.hpp>

Game::Game() {
    unsigned int mWidth = sf::VideoMode::getDesktopMode().size.x;
    if (mWidth > 2560) {
        width = 2560; height = 1440;
    } else if (mWidth > 1920) {
        width = 1920; height = 1080;
    } else {
        width = 1080; height = 720;
    }
    window = sf::RenderWindow(sf::VideoMode({width, height}), "Defense Game");
    view = sf::View({640, 360}, {1280, 720});
    window.setView(view);
}

void Game::init() {
    self = shared_from_this();
}

void Game::run() {
    while (running) {
        handleInput();
        handleScene();
        window.clear();
        window.display();
    }
}

void Game::handleInput() {
    while (std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            running = false;
        }
    }
}

void Game::handleScene() {

}
