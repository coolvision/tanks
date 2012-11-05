#pragma once

#ifndef _RUNNER_H_
#define _RUNNER_H_

#include <string>
#include <vector>

#include "MyStrategy.h"
#include "Strategy.h"

using namespace model;
using namespace std;

#include "RemoteProcessClient.h"

class Runner {
private:
	RemoteProcessClient remote_process_client;
	std::string token;
public:
	Runner(const char*, const char*, const char*);
	~Runner();

	void Setup();

	void Run();

    int team_size;

    vector<Strategy*> strategies;
    vector<TankType> tank_types;
};

#endif
