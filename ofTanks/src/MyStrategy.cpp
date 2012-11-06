#include "ofMain.h"

#include "MyStrategy.h"

#define _USE_MATH_DEFINES
#include <cmath>

using namespace model;

#define W_S 1.0
#define WORLD_OFFSET 0.15

class Point {
public:
	float x;
	float y;
};

#define POINTS_N 20

#define GOAL_RADIUS 100



Point plan[POINTS_N];

Point world_min;
Point world_max;
float field_width;
float field_height;

void MyStrategy::Move(Tank self, World world, model::Move& move) {

	float min_angle = M_PI / 10.0;

    static bool init = false;

    if (!init) {
    	world_min.x = world.width() * WORLD_OFFSET;
    	world_max.x = world.width() - world.width() * WORLD_OFFSET;
    	world_min.y = world.height() * WORLD_OFFSET;
    	world_max.y = world.height() - world.height() * WORLD_OFFSET;

    	field_width = world_max.x - world_min.x;
    	field_height = world_max.y - world_min.y;

        init = true;
        left = 1.0;
        right = 1.0;

        // create movement plan
        // randomly select the first point
        plan[0].x = ofRandom(world_min.x, world_max.x);
        plan[0].y = ofRandom(world_min.y, world_max.y);

        for (int i = 1; i < POINTS_N; i++) {
            plan[i].x = ofRandom(world_min.x, world_max.x);
            plan[i].y = ofRandom(world_min.y, world_max.y);
        }
    }


    // if reached next goal point, add one more point to the planned list
    if (ofDist(self.x(), self.y(), plan[0].x, plan[0].y) < GOAL_RADIUS) {

        for (int i = 0; i < POINTS_N-1; i++) {
            plan[i].x = plan[i+1].x;
            plan[i].y = plan[i+1].y;
        }

        plan[POINTS_N-1].x = ofRandom(world_min.x, world_max.x);
        plan[POINTS_N-1].y = ofRandom(world_min.y, world_max.y);
    }


    // execute action for moving towards current goal point
	double angle_to_point = self.GetAngleTo(plan[0].x, plan[0].y);

	if (angle_to_point > min_angle) {
		left = 1.0;
		right = 0.5;
	} else if (angle_to_point < -min_angle) {
		left = 0.5;
		right = 1.0;
	} else {
		left = 1.0;
		right = 1.0;
	}

	// probably should change proportional to the angle difference
    move.set_left_track_power(left);
    move.set_right_track_power(right);


    // execute shooting actions

    //move.set_turret_turn(M_PI);

    //move.set_turret_turn(ofRandom(0, M_PI * 2));

    //move.set_fire_type(PREMIUM_PREFERRED);








    // use 100px grid?


    ofFill();
    ofSetColor(ofColor::green);
    ofCircle(plan[0].x, plan[0].y, 5.0f);

    ofNoFill();
    ofSetLineWidth(1.0f);
    ofSetColor(ofColor::red);
    for (int i = 0; i < POINTS_N-1; i++) {
    	ofSetColor(ofColor::red);
    	ofLine(plan[i].x, plan[i].y, plan[i+1].x, plan[i+1].y);
    	ofSetColor(ofColor::gray);
    	ofCircle(plan[i].x, plan[i].y, 100.0f);
    }

    std::vector<Tank> tanks = world.tanks();

    ofNoFill();
    ofRect(0, 0, world.width(), world.height());
    ofSetColor(ofColor::blue);
    ofRect(world_min.x, world_min.y, (world_max.x - world_min.x), (world_max.y - world_min.y));


    for (int i = 0; i < tanks.size(); i++) {

        ofPushMatrix();
        ofPushStyle();

        ofSetRectMode (OF_RECTMODE_CENTER);

        ofTranslate(
                ofPoint(tanks[i].x(),
                        tanks[i].y()));
        ofRotate(tanks[i].angle() * RAD_TO_DEG);

        ofRect(0, 0, tanks[i].width(),
                tanks[i].height());

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
                ofPoint(shells[i].x(),
                        shells[i].y()));
        ofRotate(shells[i].angle() * RAD_TO_DEG);

        ofRect(0, 0, shells[i].width(),
                shells[i].height());

        ofPopStyle();
        ofPopMatrix();
    }

}

TankType MyStrategy::SelectTank(int tank_index, int team_size) {
    return MEDIUM;
}
