#include "ofMain.h"

#include "MyStrategy.h"

#define _USE_MATH_DEFINES
#include <cmath>

using namespace model;

#define WORLD_SCALE 0.5

void MyStrategy::Move(Tank self, World world, model::Move& move) {

    static bool init = false;

    if (!init) {
        init = true;
        left = 1.0;
        right = 1.0;
        next_state_tick = 20;
        state = STRAUGHT_AHEAD;
    }

    cout << "world tick " << world.tick() << " next_state_tick " << next_state_tick << endl;

    if (world.tick() > next_state_tick) {

        if (state == STRAUGHT_AHEAD) {
            state = floor(ofRandom(1., STATES_NUMBER - 0.0001));
            next_state_tick = world.tick() + 100;
        } else {
            state = STRAUGHT_AHEAD;
            next_state_tick = world.tick() + 100;
        }

        cout << "state change " << state << " " << world.tick() << " "
                << next_state_tick << endl;
    }



    if (state == STRAUGHT_AHEAD) {
        right = left = 1.0;
//    } else if (state == RANDOM_TURNING_LEFT) {
//        left = -0.5 + ofRandom(-0.5, 1.);
//        right = 0.7 + ofRandom(-0.1, 0.3);
//    } else if (state == RANDOM_TURNING_RIGHT) {
//        right = -0.5 + ofRandom(-0.5, 1.);
//        left = 0.7 + ofRandom(-0.1, 0.3);
    } else if (state == RANDOM_TURNING_LEFT_MAX) {
        right = 1.0;
        left = -1.0;
    } else if (state == RANDOM_TURNING_RIGHT_MAX) {
        right = -1.0;
        left = 1.0;
    }

    // change motion state randomly
    //cout << "tick " << world.tick() << endl;

//    if (left > 10.0) left = 10.0;
//    if (right > 10.0) right = 10.0;
//
//    if (left < -10.0) left = -10.0;
//    if (right < -10.0) right = -10.0;
//
//    left += ofRandom(-0.01, 0.01);
//    right += ofRandom(-0.01, 0.01);

    move.set_left_track_power(left);
    move.set_right_track_power(right);

    //move.set_turret_turn(M_PI);

    move.set_turret_turn(ofRandom(0, M_PI * 2));

    move.set_fire_type(PREMIUM_PREFERRED);

    std::vector<Tank> tanks = world.tanks();

    ofNoFill();
    ofRect(0, 0, world.width() * WORLD_SCALE, world.height() * WORLD_SCALE);

    for (int i = 0; i < tanks.size(); i++) {

        ofPushMatrix();
        ofPushStyle();

        ofSetRectMode (OF_RECTMODE_CENTER);

        ofTranslate(
                ofPoint(tanks[i].x() * WORLD_SCALE,
                        tanks[i].y() * WORLD_SCALE));
        ofRotate(tanks[i].angle() * RAD_TO_DEG);

        ofRect(0, 0, tanks[i].width() * WORLD_SCALE,
                tanks[i].height() * WORLD_SCALE);

        ofSetColor(ofColor::green);

        ofRotate(tanks[i].turret_relative_angle() * RAD_TO_DEG);
        ofSetLineWidth(4.0f);
        ofLine(0, 0, 50, 0);

        ofPopStyle();
        ofPopMatrix();
    }

    std::vector<Shell> shells = world.shells();

    for (int i = 0; i < shells.size(); i++) {

        ofPushMatrix();
        ofPushStyle();

        ofSetRectMode (OF_RECTMODE_CENTER);
        ofSetColor(ofColor::red);

        ofTranslate(
                ofPoint(shells[i].x() * WORLD_SCALE,
                        shells[i].y() * WORLD_SCALE));
        ofRotate(shells[i].angle() * RAD_TO_DEG);

        ofRect(0, 0, shells[i].width() * WORLD_SCALE,
                shells[i].height() * WORLD_SCALE);

        ofPopStyle();
        ofPopMatrix();
    }

}

TankType MyStrategy::SelectTank(int tank_index, int team_size) {
    return MEDIUM;
}
