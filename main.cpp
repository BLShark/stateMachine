#include <memory>
#include "SlotStateContext.h"
#include "GameStates.h"

class Slot : public std::enable_shared_from_this<Slot>
{
public:
	Slot() : context(shared_from_this()) {}
	SlotStateContext<State, gameEvents, Transitions> context;
};


int main()
{
	Slot s;
  return 0;
}
