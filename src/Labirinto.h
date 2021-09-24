#ifndef LABIRINTO_H
#define LABIRINTO_H
#include <vector>
#include <string>

class Labirinto {
    private:
        std::vector<std::string> labirinto;
        int sizeX = labirinto.size();
		int sizeY = labirinto[0].size();
    public:
        Labirinto(const std::vector<std::string> &lab);
        bool solve(int x, int y);
        bool available(int x, int y);
        void showLab();
		auto getsizeX() { return sizeX; }
        auto getsizeY() { return sizeY; }
};

#endif // !LABIRINTO_H