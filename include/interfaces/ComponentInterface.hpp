#pragma once

class ComponentInterface
{
    public:
        virtual ~ComponentInterface() {};
        virtual void receive(int message) = 0;
};