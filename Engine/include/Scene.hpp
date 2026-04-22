#pragma once

class Scene {
    public:
        virtual ~Scene() {};
        
        virtual void onStart() = 0; // Funkcja dziejąca się w momencie aktywowania sceny
        virtual void onUpdate(float dt) = 0; // Funkcja dziejąca się wraz z funkcją update w Engine.cpp
        virtual void onStop() = 0; // Funkcja dziejąca się wraz z usunięciem sceny
};