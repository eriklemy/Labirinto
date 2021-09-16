#ifndef LABIRINTO_H
#define LABIRINTO_H

#include <string>
#include <vector>

class Labirinto {
    private:
        vector<string> labirinto;
    public:
        Labirinto(vector<string> lab)
            :labirinto(lab){ } // CONSTRUTOR
        bool solve(int x, int y);
        bool available(int x, int y);
        void showLab();
        auto getLabSize() { return labirinto; }
};

#endif // !LABIRINTO_H