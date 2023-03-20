#include "CrossWindow/CrossWindow.h"
#include "Renderer.h"


void xmain(int argc, const char** argv) {
    // Создать окно
    xwin::WindowDesc wdesc;
    wdesc.title = "DirectX 12 Seed";
    wdesc.name = "MainWindow";
    wdesc.visible = true;
    wdesc.width = 640;
    wdesc.height = 640;
    wdesc.fullscreen = false;
    xwin::Window window;
    xwin::EventQueue eventQueue;
    if (!window.create(wdesc, eventQueue)) { return; };
    // Создать рендерер
    Renderer renderer(window);
    // Цикл движка
    bool isRunning = true;
    while (isRunning) {
        bool shouldRender = true;
        // Обновить очередь событий
        eventQueue.update();
        // Итерация по этой очереди:
        while (!eventQueue.empty()) {
            // Обновить события
            const xwin::Event& event = eventQueue.front();
            // При изменении размера:
            if (event.type == xwin::EventType::Resize) {
                const xwin::ResizeData data = event.data.resize;
                renderer.resize(data.width, data.height);
                shouldRender = false;
            }
            // При закрытии:
            if (event.type == xwin::EventType::Close) {
                window.close();
                shouldRender = false;
                isRunning = false;
            }
            eventQueue.pop();
        }
        // Обновление визуалов
        if (shouldRender) {
            renderer.render();
        }
    }
}