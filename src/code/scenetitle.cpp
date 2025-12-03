#include <scene.hpp>
#include <game.hpp>

SceneTitle::SceneTitle(shared_ptr<Game> game) : Scene(game) {

}

void SceneTitle::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneTitle::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
}

void SceneTitle::mouseUp(shared_ptr<Game> game, sf::Vector2f pos, int button) {

}
