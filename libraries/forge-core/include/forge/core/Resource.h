#pragma once

namespace forge
{
    class Resource {
        private:
            int value;

        public:
            Resource(int initialValue);
            ~Resource();

            void SetValue(int x);
            int GetValue() const;
    };
}