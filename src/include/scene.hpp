#pragma once
#include <general.hpp>

class Game;
class Scene {
    public:
        Scene(shared_ptr<Game>);
        virtual void loop(shared_ptr<Game>);
        virtual void render(shared_ptr<Game>);
        virtual void mouseUp(shared_ptr<Game>, sf::Vector2f, int);
};

class SceneTitle : public Scene {
    public:
        SceneTitle(shared_ptr<Game>);
        virtual void loop(shared_ptr<Game>);
        virtual void render(shared_ptr<Game>);
        virtual void mouseUp(shared_ptr<Game>, sf::Vector2f, int);

};

class SceneLevelSelect : public Scene {
    public:
        SceneLevelSelect(shared_ptr<Game>);
        virtual void loop(shared_ptr<Game>);
        virtual void render(shared_ptr<Game>);
        virtual void mouseUp(shared_ptr<Game>, sf::Vector2f, int);
};

class SceneBattle : public Scene {
    public:
        SceneBattle(shared_ptr<Game>);
        virtual void loop(shared_ptr<Game>);
        virtual void render(shared_ptr<Game>);
        virtual void mouseUp(shared_ptr<Game>, sf::Vector2f, int);
};
