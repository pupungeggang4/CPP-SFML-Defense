#include <scene.hpp>
#include <ui.hpp>
#include <func.hpp>
#include <render.hpp>
#include <game.hpp>

SceneCollection::SceneCollection(shared_ptr<Game> game) {

}

void SceneCollection::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneCollection::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    game->rRect.setOutlineColor(sf::Color::Black);
    Render::renderText(game->window, game->rText, "Collection", UI::UICollection["text_title"]);
    Render::renderRect(game->window, game->rRect, UI::UICollection["button_back"], 2);
}

void SceneCollection::mouseUp(shared_ptr<Game> game, sf::Vector2f pos, int button) {
    if (button == 0) {
        if (Func::pointInsideRectUI(pos, UI::UICollection["button_back"])) {
            game->scene = make_shared<SceneTitle>(game);
        }
    }
}
