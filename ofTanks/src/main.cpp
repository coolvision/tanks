#include "ofMain.h"
#include "TanksApp.h"
#include "ofAppGlutWindow.h"

int main() {

    ofAppGlutWindow window;
    ofSetupOpenGL(&window, 800, 600, OF_WINDOW);

    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp(new TanksApp("localhost", "31000", "0000000000000000"));
}
