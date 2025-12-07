#include <render.hpp>
#include <ui.hpp>
#include <game.hpp>

void Render::renderMenu(sf::RenderTarget& rt, shared_ptr<Game> game) {
    game->rRect.setFillColor(sf::Color::White);
    renderRect(game->window, game->rRect, UI::UIMenu["rect"], 0);
    renderRect(game->window, game->rRect, UI::UIMenu["rect"], 2);
    renderText(game->window, game->rText, "Paused", UI::UIMenu["text_paused"]);
    renderRect(game->window, game->rRect, UI::UIMenu["button_resume"], 2);
    renderText(game->window, game->rText, "Resume", UI::UIMenu["text_resume"]);
    renderRect(game->window, game->rRect, UI::UIMenu["button_exit"], 2);
    renderText(game->window, game->rText, "Exit to title.", UI::UIMenu["text_exit"]);
    renderRect(game->window, game->rRect, UI::UIMenu["button_quit"], 2);
    renderText(game->window, game->rText, "Quit game.", UI::UIMenu["text_quit"]);
}

void Render::renderText(sf::RenderTarget& rt, sf::Text& t, sf::String s, std::vector<float> pos) {
    t.setString(s);
    t.setPosition({pos[0], pos[1]});
    rt.draw(t);
}

void Render::renderRect(sf::RenderTarget& rt, sf::RectangleShape& rs, std::vector<float> rect, float thickness) {
    if (thickness > 0) {
        rs.setFillColor(sf::Color::Transparent);
    }
    rs.setOutlineThickness(thickness);
    rs.setPosition({rect[0], rect[1]});
    rs.setSize({rect[2], rect[3]});
    rt.draw(rs);
}

void Render::renderSprite(sf::RenderTarget& rt, sf::Sprite& s, std::vector<float> pos) {
    s.setPosition({pos[0], pos[1]});
    rt.draw(s);
}