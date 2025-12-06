#pragma once
#include <general.hpp>

class Game;
class Scene {
    public:
        Scene();
        virtual void loop(shared_ptr<Game>);
        virtual void render(shared_ptr<Game>);
        virtual void mouseUp(shared_ptr<Game>, sf::Vector2f, int);
};

class SceneTitle : public Scene {
    public:
        SceneTitle(shared_ptr<Game>);
        void loop(shared_ptr<Game>) override;
        void render(shared_ptr<Game>) override;
        void mouseUp(shared_ptr<Game>, sf::Vector2f, int) override;

};

class SceneLevelSelect : public Scene {
    public:
        SceneLevelSelect(shared_ptr<Game>);
        void loop(shared_ptr<Game>) override;
        void render(shared_ptr<Game>) override;
        void mouseUp(shared_ptr<Game>, sf::Vector2f, int) override;
        int page = 0;
};

class SceneBattle : public Scene {
    public:
        SceneBattle(shared_ptr<Game>);
        void loop(shared_ptr<Game>) override;
        void render(shared_ptr<Game>) override;
        void mouseUp(shared_ptr<Game>, sf::Vector2f, int) override;
};

class SceneCollection : public Scene {
    public:
        SceneCollection(shared_ptr<Game>);
        void loop(shared_ptr<Game>) override;
        void render(shared_ptr<Game>) override;
        void mouseUp(shared_ptr<Game>, sf::Vector2f, int) override;
};
