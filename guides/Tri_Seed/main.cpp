// Cross platform window managing library.
#include "CrossWindow/CrossWindow.h"

// Renderer barebones boostrap.
#include "Renderer.hpp"



// This is cross-window's main function, it called on the platform dependent entrypoint.
void xmain(int argc, const char** argv)
{
    std::cout << "Entered CrossWindow execution: xmain" << std::endl;

    using Backend::VKGPU;

    xwin::EventQueue eventQueue;   // Window event queue.
    xwin::WindowDesc wdesc     ;   // Window description.
    xwin::Window     window    ;   // Window object.

    // Setup the window creation parameters. 
    wdesc.title      = "VT Guide: Hello Triangle";
    wdesc.name       = "MainWindow";
    wdesc.visible    = true;
    wdesc.width      = 640;
    wdesc.height     = 64;
    wdesc.fullscreen = false;

    try
    {
        // 🖼 Create Window
        if (!window.create(wdesc, eventQueue))
            return;   // Exit if window fails to create.
        else std::cout << "Window created." << std::endl;

        VKGPU gpu(window);

        // Engine Loop
        std::cout << "Entering engine loop." << std::endl;

        bool isRunning = true;   // Sentinel for engine loop.

        while (isRunning)
        {
             bool shouldRender = true;

            // Update the event queue for the window.
            eventQueue.update();   

            // Process events.
            while (!eventQueue.empty())   
            {
                // Get the latest event.
                const xwin::Event& event = eventQueue.front();   

                // Handle window resizing.
                if (event.type == xwin::EventType::Resize)
                {
                    const xwin::ResizeData data = event.data.resize;

                    //  gpu.Recalibrate(data.width, data.height);

                     shouldRender = false;                
                }

                // Handle window closing.
                if (event.type == xwin::EventType::Close)
                {
                    window.close();

                    shouldRender = false;

                    isRunning = false;
                }

                // Remove the event from the queue.
                eventQueue.pop();
            }   

            // Process Rendering
            // gpu.render();     
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
}