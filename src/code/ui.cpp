#include <ui.hpp>

std::unordered_map<std::string, std::vector<float>> UI::UITitle = {
    {"text_title", {20, 20}},
    {"button_start", {160, 160, 960, 80}},
    {"text_start", {180, 180}},
    {"button_collection", {160, 240, 960, 80}},
    {"text_collection", {180, 260}},
    {"button_erase", {160, 320, 960, 80}},
    {"text_erase", {180, 340}},
    {"button_quit", {160, 400, 960, 80}},
    {"text_quit", {180, 420}}
};

std::unordered_map<std::string, std::vector<float>> UI::UILevelSelect = {
    {"text_title", {20, 20}},
    {"text_page", {20, 60}},
    {"button_back", {1180, 20, 80, 80}},
    {"button_level_start", {180, 140}},
    {"button_level_size", {120, 120}},
    {"button_level_interval", {160, 160}},
    {"button_prev", {20, 320, 80, 80}},
    {"button_next", {1180, 320, 80, 80}}
};

std::unordered_map<std::string, std::vector<float>> UI::UIBattle = {

};

std::unordered_map<std::string, std::vector<float>> UI::UIMenu = {

};

std::unordered_map<std::string, std::vector<float>> UI::UICollection = {
    {"text_title", {20, 20}},
    {"button_back", {1180, 20, 80, 80}},
};
