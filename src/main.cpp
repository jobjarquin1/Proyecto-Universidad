#include <SFML/Graphics.hpp>
#include "events.hpp"
#include <random>
#include <algorithm>
#include "configuration.hpp"
#include "star.hpp"

std::vector<Star> createStars(uint32_t count, float scale)
{
    std::vector<Star> stars;
    stars.reserve(count);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);

    sf::Vector2f const window_world_size(conf::window_size_f.x * conf::near, conf::window_size_f.y * conf::near);
    sf::FloatRect const star_free_zone(
        sf::Vector2f(-0.5f * window_world_size.x, -0.5f * window_world_size.y),
        window_world_size
    );

    for (uint32_t i{count}; i--;) {
        float const x = (dist(gen) - 0.5f) * conf::window_size_f.x * scale;
        float const y = (dist(gen) - 0.5f) * conf::window_size_f.y * scale;
        float const z = dist(gen) * conf::far;

        if (star_free_zone.contains(sf::Vector2f(x, y))) 
        {
            ++i;
            continue;
        }
        stars.push_back({{x, y}, z});
    }

    std::sort(stars.begin(), stars.end(), [](Star const& s_1, Star const& s_2) {
        return s_1.z < s_2.z;
    });

    return stars;
}

void updateGeometry(uint32_t idx, Star const& s, sf::VertexArray& va)
{
    float const scale = 1.0f / s.z;
    float const depth_ratio = (s.z - conf::near) / (conf::far - conf::near);
    float const color_ratio = 1.0f - depth_ratio;
    auto const c = static_cast<uint8_t>(color_ratio * 255.0f);

    sf::Vector2f const p = s.position * scale;
    float const r = conf::radius * scale;
    uint32_t const i = 4 * idx;

    va[i + 0].position = {p.x - r, p.y - r};
    va[i + 1].position = {p.x + r, p.y - r};
    va[i + 2].position = {p.x + r, p.y + r};
    va[i + 3].position = {p.x - r, p.y + r};

    sf::Color const color {c, c, c};
    va[i + 0].color = color;
    va[i + 1].color = color;
    va[i + 2].color = color;
    va[i + 3].color = color;
}

int main() {
    sf::RenderWindow window(
        sf::VideoMode(conf::window_size, 32),
        "CMake SFML Project",
        sf::Style::Default
    );
    window.setFramerateLimit(conf::max_framate);
    window.setMouseCursorVisible(false);

    sf::Texture texture;
    texture.loadFromFile("res/img.jpg");
    texture.setSmooth(true);
    texture.generateMipmap();

    std::vector<Star> stars = createStars(conf::count, conf::far);
    sf::VertexArray va((sf::PrimitiveType)4, 4 * conf::count);

    auto const texture_size_f = static_cast<sf::Vector2f>(texture.getSize());
    for (uint32_t idx{conf::count}; idx--;) {
        uint32_t const i = 4 * idx;
        va[i + 0].texCoords = {0.0f, 0.0f};
        va[i + 1].texCoords = {texture_size_f.x, 0.0f};
        va[i + 2].texCoords = {texture_size_f.x, texture_size_f.y};
        va[i + 3].texCoords = {0.0f, texture_size_f.y};
    }

    uint32_t first = 0;
    while (window.isOpen()) {
        processEvents(window);
        for (uint32_t i{conf::count}; i--;) {
            Star& s = stars[i];
            s.z -= conf::speed * conf::dt;
            if (s.z < conf::near) {
                s.z = conf::far - (conf::near - s.z);
                first = i;
            }
        }
        window.clear();
        sf::CircleShape shape{conf::radius};
        shape.setOrigin(sf::Vector2f(conf::radius, conf::radius));
        for(uint32_t i{0}; i < conf::count; ++i) {
            uint32_t const idx = (i + first) % conf::count;
            Star const& s = stars[idx];
            if(s.z >= conf::near) {
                float const scale = 1.0f / s.z;
                shape.setPosition(sf::Vector2f(
                    s.position.x * scale + conf::window_size_f.x * 0.5f,
                    s.position.y * scale + conf::window_size_f.y * 0.5f
                ));
                shape.setScale(sf::Vector2f(scale, scale));
                float const depth_ratio = (s.z - conf::near) / (conf::far - conf::near);
                float const color_ratio = 1.0f - depth_ratio;
                auto const c = static_cast<uint8_t>(color_ratio * 255.0f);
                shape.setFillColor(sf::Color(c, c, c));
                window.draw(shape);
            }
        }
        sf::RenderStates states{};
        states.transform.translate(sf::Vector2f(
            conf::window_size_f.x * 0.5f,
            conf::window_size_f.y * 0.5f
        ));
        states.texture = &texture;
        window.draw(va, states);
        window.display();
    }
}