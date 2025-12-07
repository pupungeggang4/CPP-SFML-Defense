#include <scene.hpp>
#include <ui.hpp>
#include <func.hpp>
#include <render.hpp>
#include <game.hpp>

SceneBattle::SceneBattle(shared_ptr<Game> game) {
    game->menu = false;
}

void SceneBattle::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneBattle::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    game->rRect.setOutlineColor(sf::Color::Black);
    Render::renderRect(game->window, game->rRect, UI::UIBattle["button_menu"], 2);

    if (game->menu == true) {
        Render::renderMenu(game->window, game);
    }
}

void SceneBattle::mouseUp(shared_ptr<Game> game, sf::Vector2f pos, int button) {
    if (button == 0) {
        if (game->menu == false) {
            if (Func::pointInsideRectUI(pos, UI::UIBattle["button_menu"])) {
                game->menu = true;
            }
        } else {
            if (Func::pointInsideRectUI(pos, UI::UIBattle["button_menu"])) {
                game->menu = false;
            } else if (Func::pointInsideRectUI(pos, UI::UIMenu["button_resume"])) {
                game->menu = false;
            } else if (Func::pointInsideRectUI(pos, UI::UIMenu["button_exit"])) {
                game->scene = make_shared<SceneTitle>(game);
            } else if (Func::pointInsideRectUI(pos, UI::UIMenu["button_quit"])) {
                game->running = false;
            }
        }
    }
}
