#include "ofMain.h"

#include "MyStrategy.h"

#define _USE_MATH_DEFINES
#include <cmath>

using namespace model;

#define WORLD_SCALE 0.5

void MyStrategy::Move(Tank self, World world, model::Move& move) {

    move.set_left_track_power(-1.0);
    move.set_right_track_power(1.0);
    move.set_turret_turn(M_PI);
    move.set_fire_type(PREMIUM_PREFERRED);

    std::vector<Tank> tanks = world.tanks();

    ofNoFill();
    ofRect(0, 0, world.width() * WORLD_SCALE, world.height() * WORLD_SCALE);

    for (int i = 0; i < tanks.size(); i++) {

        ofPushMatrix();
        ofPushStyle();

        ofSetRectMode(OF_RECTMODE_CENTER);

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

        ofSetRectMode(OF_RECTMODE_CENTER);
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
