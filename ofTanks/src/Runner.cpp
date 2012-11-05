#include "Runner.h"

#include <vector>

#include "MyStrategy.h"
#include "Strategy.h"

using namespace model;
using namespace std;

//int main(int argc, char* argv[]) {
//	if (argc == 4) {
//		Runner runner(argv[1], argv[2], argv[3]);
//		runner.Run();
//	} else {
//		Runner runner("localhost", "31000", "0000000000000000");
//		runner.Run();
//	}
//
//	return 0;
//}

Runner::Runner(const char* host, const char* port, const char* token) :
        remote_process_client(host, atoi(port)), token(token) {
}

void Runner::Setup() {
    remote_process_client.WriteToken(token);
    team_size = remote_process_client.ReadTeamSize();

    for (int strategy_index = 0; strategy_index < team_size; ++strategy_index) {
        Strategy* strategy = new MyStrategy;
        strategies.push_back(strategy);
        tank_types.push_back(strategy->SelectTank(strategy_index, team_size));
    }

    remote_process_client.WriteSelectedTanks(tank_types);
}

void Runner::Run() {

    PlayerContext* player_context = remote_process_client.ReadPlayerContext();
    // if (player_context == NULL) flag_shutdown = true;

    vector<Tank> player_tanks = player_context->tanks();
    if (player_tanks.size() != team_size) {
        return;
    }

    vector<Move> moves;

    for (int strategy_index = 0; strategy_index < team_size; ++strategy_index) {
        Move move;
        strategies[strategy_index]->Move(player_tanks[strategy_index],
                player_context->world(), move);
        moves.push_back(move);
    }

    remote_process_client.WriteMoves(moves);

    delete player_context;

}

Runner::~Runner() {

    for (int strategy_index = 0; strategy_index < team_size; ++strategy_index) {
        delete strategies[strategy_index];
    }

}
