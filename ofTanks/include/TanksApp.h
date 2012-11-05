#pragma once

#include <ofMain.h>

#include "Runner.h"

class TanksApp: public ofBaseApp {
public:

    TanksApp(const char* host, const char* port, const char* token);

    Runner runner;

    void setup();
    void update();
    void draw();
    void exit();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
};
