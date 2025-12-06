#include <scene.hpp>
#include <ui.hpp>
#include <func.hpp>
#include <res.hpp>
#include <render.hpp>
#include <game.hpp>

SceneTitle::SceneTitle(shared_ptr<Game> game) {

}

void SceneTitle::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneTitle::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    game->rRect.setOutlineColor(sf::Color::Black);
    Render::renderText(game->window, game->rText, "Defense Game", UI::UITitle["text_title"]);
    Render::renderRect(game->window, game->rRect, UI::UITitle["button_start"], 2);
    Render::renderText(game->window, game->rText, "Start Game", UI::UITitle["text_start"]);
    Render::renderRect(game->window, game->rRect, UI::UITitle["button_collection"], 2);
    Render::renderText(game->window, game->rText, "Collection", UI::UITitle["text_collection"]);
    Render::renderRect(game->window, game->rRect, UI::UITitle["button_erase"], 2);
    Render::renderText(game->window, game->rText, "Erase Data", UI::UITitle["text_erase"]);
    Render::renderRect(game->window, game->rRect, UI::UITitle["button_quit"], 2);
    Render::renderText(game->window, game->rText, "Quit Game", UI::UITitle["text_quit"]);
}

void SceneTitle::mouseUp(shared_ptr<Game> game, sf::Vector2f pos, int button) {
    if (button == 0) {
        if (Func::pointInsideRectUI(pos, UI::UITitle["button_start"])) {
            game->scene = make_shared<SceneLevelSelect>(game);
        } else if (Func::pointInsideRectUI(pos, UI::UITitle["button_collection"])) {
            game->scene = make_shared<SceneCollection>(game);
        } else if (Func::pointInsideRectUI(pos, UI::UITitle["button_quit"])) {
            game->running = false;
        }
    }
}
