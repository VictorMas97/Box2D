
#include "Box2DObject.hpp"
#include "Scene.hpp"
#include <memory>
#include <vector>
#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


using namespace sf;
using namespace std;

int main ()
{
    RenderWindow window(VideoMode(800, 600), "Animation Examples: Box2D Rigid Bodies", Style::Titlebar | Style::Close, ContextSettings(32));

    window.setVerticalSyncEnabled (true);

	physics::Scene scene{b2Vec2(0.f, -50.f)};

    bool running = true;
    Clock timer;
    float delta_time = 0.017f;   // ~60 fps

    do
    {
        timer.restart ();

        // Process window events:

        Event event;

        while (window.pollEvent (event))
        {
            if (event.type == Event::Closed)
            {
                running = false;
            }
        }

        // Update:

		scene.Update(delta_time);

        // Render:

        window.clear ();

		scene.Render(window);

        window.display ();

        delta_time = (delta_time + timer.getElapsedTime ().asSeconds ()) * 0.5f;
    }
    while (running);

    return EXIT_SUCCESS;
}
