#include <scene.hpp>
#include <render.hpp>
#include <game.hpp>

SceneBattle::SceneBattle(shared_ptr<Game> game) {

}

void SceneBattle::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneBattle::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
}

void SceneBattle::mouseUp(shared_ptr<Game> game, sf::Vector2f pos, int button) {

}
