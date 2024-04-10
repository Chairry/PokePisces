#ifndef GUARD_BATTLE_TENT_H
#define GUARD_BATTLE_TENT_H

enum TentLeagues {
    BATTLE_TENT_LEAGUE_MINOR,
    BATTLE_TENT_LEAGUE_MAJOR,
    BATTLE_TENT_LEAGUE_CHAMP,
};

bool8 InSlateportBattleTent(void);
u32 GetBattleTentLevel(u32 league);
u32 SetBattleTentMonsTrainers(u32 league);
u32 GetBattleTentLeague(void);
u32 SetBattleTentTrainers(u32 league);

#endif //GUARD_BATTLE_TENT_H
