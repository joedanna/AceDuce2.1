#ifndef POT_H
#define POT_H

class Pot {
public:
    int potValue;
    Pot() : potValue(100) {}
    void adjustPot(int amount) { potValue += amount; }
};

#endif // POT_H
