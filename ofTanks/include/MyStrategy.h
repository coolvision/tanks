#pragma once

#ifndef _MY_STRATEGY_H_
#define _MY_STRATEGY_H_

#include "Strategy.h"

enum MotionState {
    STRAUGHT_AHEAD = 0,
//    RANDOM_TURNING_LEFT,
//    RANDOM_TURNING_RIGHT,
    RANDOM_TURNING_LEFT_MAX,
    RANDOM_TURNING_RIGHT_MAX,
    STATES_NUMBER
};

enum PositionState {
    IN_FIELD = 0,
    ON_BORDER
};

class MyStrategy : public Strategy {
public:
	void Move(model::Tank self, model::World world, model::Move& move);
	model::TankType SelectTank(int tank_index, int team_size);

	float speed;
	float direction;



	float left;
	float right;

	int next_state_tick;


	int state;

};

#endif
