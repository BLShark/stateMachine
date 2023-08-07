#ifndef GAMESTATES_H
#define GAMESTATES_H
#include <memory>
#include <variant>
#include <optional>

#include "Idle.h"
#include "MGReeling.h"
#include "IdlePlus.h"


using State = std::variant<Idle, IdlePlus, MGReeling>;
class Slot;
using slot_ptr = std::weak_ptr<Slot>;
/*------------------- Events --------------------------*/
struct StartNewGame {};
struct EndGame {
	int winAmount = 0;
	bool FGWin = false;
	int numberOfFGLeft = 0;
};

struct StartGamble {};
using gameEvents = std::variant<StartNewGame, EndGame, StartGamble>;
/*-----------------------------------------------------*/


/* -------------------------------  Transitions ---------------------------------------- */
struct Transitions {

	Transitions(slot_ptr slot) : slot(slot){}
	std::optional<State> operator()(Idle &, const StartNewGame &e) {
		IdlePlus p;
		p.Print();
		return p;
	}

	std::optional<State> operator()(MGReeling &, const EndGame &) {

		return IdlePlus{};
	}

	std::optional<State> operator()(MGReeling &s, const StartGamble &) {

		return Idle{};
	}

	std::optional<State> operator()(IdlePlus &s, const StartNewGame &e) {
		return IdlePlus{};
	}

	template <typename State_t, typename Event_t>
	std::optional<State> operator()(State_t &, const Event_t &) const {
		return std::nullopt;
	}

	slot_ptr slot;
};


#endif // GAMESTATES_H
