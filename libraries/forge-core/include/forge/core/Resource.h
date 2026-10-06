#pragma once

namespace forge
{
    class Resource {
        private:
            int value;

        public:
            Resource();
            ~Resource();

            void SetValue(int x){value = x}
            int GetValue(){return value}
    };
}