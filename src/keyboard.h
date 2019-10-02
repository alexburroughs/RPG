#ifndef KEYBOARD_H
#define KEYBOARD_H

const int NUM_KEYS = 322;

class Keyboard {
    private:
        bool KEYS[NUM_KEYS];
        bool closed;
    public:
        Keyboard();
        void update();
        bool isUp(int index);
        bool isDown(int index);
        bool isClosed();
};

#endif