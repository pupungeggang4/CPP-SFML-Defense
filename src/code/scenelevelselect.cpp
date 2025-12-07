#include <scene.hpp>
#include <res.hpp>
#include <ui.hpp>
#include <func.hpp>
#include <render.hpp>
#include <game.hpp>

SceneLevelSelect::SceneLevelSelect(shared_ptr<Game> game) {
    page = 0;
}

void SceneLevelSelect::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneLevelSelect::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    game->rRect.setOutlineColor(sf::Color::Black);
    Render::renderRect(game->window, game->rRect, UI::UILevelSelect["button_back"], 2);
    Render::renderText(game->window, game->rText, "Select Level", UI::UILevelSelect["text_title"]);
    Render::renderText(game->window, game->rText, "Page: " + std::to_string(page + 1) + "/8", UI::UILevelSelect["text_page"]);

    for (int i = 0; i < 18; i++) {
        int row = i / 6;
        int col = i % 6;
        std::vector<float> rect = {UI::UILevelSelect["button_level_start"][0] + UI::UILevelSelect["button_level_interval"][0] * col, UI::UILevelSelect["button_level_start"][1] + UI::UILevelSelect["button_level_interval"][1] * row, UI::UILevelSelect["button_level_size"][0], UI::UILevelSelect["button_level_size"][1]};
        std::vector<float> pos = {rect[0] + 4, rect[1] + 4};
        Render::renderRect(game->window, game->rRect, rect, 2);
        Render::renderText(game->window, game->rText, std::to_string(i + 1), pos);
    }

    Render::renderSprite(game->window, Res::sprite->at("prev"), UI::UILevelSelect["button_prev"]);Render::renderSprite(game->window, Res::sprite->at("next"), UI::UILevelSelect["button_next"]);
}

void SceneLevelSelect::mouseUp(shared_ptr<Game> game, sf::Vector2f pos, int button) {
    if (button == 0) {
        if (Func::pointInsideRectUI(pos, UI::UILevelSelect["button_back"])) {
            game->scene = make_shared<SceneTitle>(game);
        }
        if (Func::pointInsideRectUI(pos, UI::UILevelSelect["button_prev"])) {
            page = (page + 7) % 8;
        }
        if (Func::pointInsideRectUI(pos, UI::UILevelSelect["button_next"])) {
            page = (page + 1) % 8;
        }

        for (int i = 0; i < 18; i++) {
            int row = i / 6;
            int col = i % 6;
            std::vector<float> rect = {UI::UILevelSelect["button_level_start"][0] + UI::UILevelSelect["button_level_interval"][0] * col, UI::UILevelSelect["button_level_start"][1] + UI::UILevelSelect["button_level_interval"][1] * row, UI::UILevelSelect["button_level_size"][0], UI::UILevelSelect["button_level_size"][1]};
            if (Func::pointInsideRectUI(pos, rect)) {
                game->scene = make_shared<SceneBattle>(game);
            }
        }
    }
}