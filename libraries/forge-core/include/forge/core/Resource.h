#pragma once

namespace forge
{
    enum class ConsumeResult
    {
        Success,
        InvalidAmount,
        InsufficientResource,
        Overflow
    };

    class Resource
    {
    private:
        int value;

    public:
        Resource(int initialValue);
        ~Resource();

        void SetValue(int x);
        int GetValue() const;

        ConsumeResult Add(int amount);
        ConsumeResult Consume(int amount);
    };
}