#pragma once

namespace conf
{
    sf::Vector2u const window_size = {2560, 1440};
    sf::Vector2f const window_size_f = static_cast<sf::Vector2f>(window_size);
    uint32_t const max_framate = 144;
    float const dt = 1.0f / static_cast<float>(max_framate);


    uint32_t const count = 10000;
    float const radius = 40.0f;
    float const far = 10.0f;
    float const near = 0.1f;
    float const speed = 1.0f;
}