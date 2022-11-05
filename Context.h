#pragma once

#include <memory>

#include "Event/Event_Ctrl.h"

static Droidtool::Event::EventAttr defaultEventAttr = {
        .eventLogName = "Droidtool",
        .logNameDsp = true
};

namespace Droidtool {
    class Context {
    public:
        /* Default tool context, here will be declared most resources needed by all execution application time
         * (while droidtool is alive) */
        Context() {
            m_MainEvent = std::make_shared<Event::EventCtrl>(defaultEventAttr);
        }
        auto getDefaultEvent() {
            return std::move(m_MainEvent);
        }
    private:
        std::shared_ptr<Event::EventCtrl> m_MainEvent;
    };
}

