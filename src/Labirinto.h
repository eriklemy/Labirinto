#ifndef LABIRINTO_H
#define LABIRINTO_H
#include <vector>
#include <string>

class Labirinto {
    private:
        std::vector<std::string> labirinto;
    public:
        Labirinto(const std::vector<std::string> &lab);
        bool solve(int x, int y);
        bool availablePath(int x, int y);
        void showLab();
};

#endif // !LABIRINTO_H