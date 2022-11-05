#include <utility>

#include <cstring>

#include "Exception.h"

template <typename T>
constexpr auto eventPtrTo(auto ptrToConvert){
    return reinterpret_cast<T>(ptrToConvert);
}

template <typename T, typename E>
class SafeResult {
public:
    using Exception = Droidtool::Exception<E>;
    SafeResult(T retValueResult, Exception exceptionResult = {}) :
        m_resultPair(retValueResult, exceptionResult) {}
    explicit SafeResult(const SafeResult& copyResult) : m_resultPair(copyResult.m_resultPair) {}
    auto isOK() const {
        return m_resultPair.second.existException() == false;
    }
    auto resolve() const {
        if (isOK() == false) {
            throw m_resultPair.second;
        }
        return m_resultPair.first;
    }
private:
    std::pair<T, Exception> m_resultPair;
};

namespace Droidtool::Event {
    using EventResponseValue = int32_t;

    class EventException : public ExceptionBase {
    public:
        EventException() = default;
        EventException(const char* errorMessage) : ExceptionBase(errorMessage) {}
    };

    using EventResult = SafeResult<EventResponseValue, EventException>;
    struct EventAttr {
        /* Program name that event will display on, if enabled, every log message will be dispatched with this name */
        const char* eventLogName = nullptr;
        bool logNameDsp = false;
    };
    
    class EventCtrl {
    public:
        explicit EventCtrl(EventAttr &event_Attr) {
            memcpy(eventPtrTo<void*>(&m_EventAttrs), eventPtrTo<void*>(&event_Attr), sizeof(m_EventAttrs));
        }

        EventResult eventDo();
    private:
        EventAttr m_EventAttrs{};
    };
}
