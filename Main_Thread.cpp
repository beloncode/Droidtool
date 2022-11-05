#include "Context.h"

int main() {
    auto mainContext = Droidtool::Context();
    auto mainEvent = mainContext.getDefaultEvent();
    auto eventRet = mainEvent->eventDo();
    try {
        std::printf("It's OK %d\n", eventRet.resolve());
    } catch(Droidtool::Event::EventException exception) {
        std::printf("Error found: %s\n", exception.whatHappens());
    }
        return 0;
}
