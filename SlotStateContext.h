#pragma once

#include <memory>
#include <optional>
#include <utility>
#include <variant>


class Slot;
using slot_ptr = std::weak_ptr<Slot>;


template<typename StateVariant, typename EventVariant, typename Transitions>
class SlotStateContext {

public:
	SlotStateContext (slot_ptr slot) : slot(slot){}

	void dispatch(const EventVariant &Event) {
		std::optional<StateVariant> new_state = visit(Transitions{slot}, m_curr_state, Event);
		if (new_state)
			m_curr_state = *move(new_state);
	}

private:
	slot_ptr slot;
	StateVariant m_curr_state;

};

