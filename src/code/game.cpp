#include <general.hpp>
#include <game.hpp>
#include <scene.hpp>

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
    scene = make_shared<SceneTitle>(self);
}

void Game::run() {
    while (running) {
        handleInput();
        handleScene();
        window.display();
    }
}

void Game::handleInput() {
    while (std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            running = false;
        }

        if (const auto* mouseUp = event->getIf<sf::Event::MouseButtonReleased>()) {
            int button = int(mouseUp->button);
            sf::Vector2f pos = sf::Vector2f({mouseUp->position.x * 1280.0f / width, mouseUp->position.y * 720.0f / height});
            self->scene->mouseUp(self, pos, button);
        }
    }
}

void Game::handleScene() {
    self->scene->loop(self);
}
