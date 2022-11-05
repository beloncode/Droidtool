#pragma once

namespace Droidtool {

    class ExceptionBase {
    protected:
        explicit ExceptionBase(const char* errorMessage) : m_exceptionMessage(errorMessage), m_ExceptionThrow(true) {}
        ExceptionBase() = default;

        const char* m_exceptionMessage{};
    private:
        bool m_ExceptionThrow = false;
    public:
        auto existException() const {
            return m_ExceptionThrow;
        }
        virtual const char* whatHappens() const {
            return m_exceptionMessage;
        }
    };

    template <typename T>
class Exception : public T {
    public:
        Exception() {}
        Exception(const char* exceptionMessage) : T(exceptionMessage) {}
    };

}