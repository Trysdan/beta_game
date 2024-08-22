#pragma once

#include <filesystem>
#include <string>
#include <unordered_map>

namespace fs = std::filesystem;

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

struct Settings
{
    static const fs::path ASSETS_PATH;
    static const fs::path GRAPHICS_PATH;
    static const fs::path SOUNDS_PATH;
    static const fs::path FONTS_PATH;
    
    static constexpr int WINDOW_WIDTH{960};
    static constexpr int WINDOW_HEIGHT{540};
    static constexpr float PLAYER_WIDTH{48.f};
    static constexpr float PLAYER_HEIGHT{48.f};
    static constexpr int FPS{60};
};