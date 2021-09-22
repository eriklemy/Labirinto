#include <iostream>
#include <vector>
#include <chrono> // std::chrono::microseconds
#include <thread> // std::this_thread::sleep_for

using namespace std;

class Labirinto {
    private:
        vector<string> labirinto;
    public:
        Labirinto(vector<string> lab)
            :labirinto(lab){ } // CONSTRUTOR

        bool solve(int x, int y) {
            if (labirinto[x][y] == 'S'){
                labirinto[x][y] = '*';
                cout << "Saida   (" << x << ", " << y << ") " << endl;
                return true; // saida encontrada
            } 
            
            // showLab();
            // this_thread::sleep_for(chrono::milliseconds(10));
            // system("CLS");
            // marca o caminho
            labirinto[x][y] = '*';
            
            // checa as direções - se retornar true é pq encontrou um caminho
            if (available(x - 1, y) && solve(x - 1, y)) // para cima
                return true; //  px.push() py.push()
            if (available(x + 1, y) && solve(x + 1, y)) // para baixo
                return true;
            if (available(x, y - 1) && solve(x, y - 1)) // para esquerda
                 return true;
            if (available(x, y + 1) && solve(x, y + 1)) // para direita
				return true;

            // se nenhum caminho for encontrado retorna falso
            // remarca a passagem que n leva a saida
            labirinto[x][y] = ' ';
            return false;
        }

        bool available(int x, int y) {
            return (x >= 0 && x < labirinto.size()
                 && y >= 0 && y < labirinto[x].size()
                 && (labirinto[x][y] == ' ' || labirinto[x][y] == 'S'));
        }

        void showLab(){
            for(int x = 0; x < labirinto.size(); ++x) {
                for(int y = 0; y < labirinto[x].size(); y++)
                  	if(labirinto[x][y] == '-'){
                    	cout << ' ';
                    	continue;
                  	}else{
						if(labirinto[x][y] == '*')
							cout << "\033[1;31m*\033[0m";
						else
                    		cout << labirinto[x][y];
                  	}
                cout << endl;
            }
        }

        auto getLabSize() { return labirinto; }
};

void Start(){
	cout << "===================================" << endl;
	cout << "|         PROJETO LABIRINTO       |" << endl;
	cout << "|            PATH FINDER          |" << endl;
	cout << "| ERICK LEMMY DOS SANTOS OLIVEIRA |" << endl;
	cout << "===================================" << endl;
	this_thread::sleep_for(chrono::milliseconds(1500));
}

int main(){
    Labirinto labirinto({
                    "XXXXXXXXXXXXXXXXXXXXX",
                    "X     X     X     X X",
                    "XX XX XXXXX X X X   X",
                    "X   X       XXX XXX X",
                    "X X X XXXXXXX   X   X",
                    "X X   X   X X X   X X",
                    "X XXXXX X X   XXXXX X",
                    "X X     X XXX  X    X",
                    "X X X X X   XX XX XXX",
                    "X X XXX X X     X   X",
                    "E X X X X XXXXX XXX X",
                    "X     X X   X X X   X",
                    "X XXXXX XXX X XXX X X",
                    "X X       X X   X X X",
                    "X   XXX X X XXX X X X",
                    "XXX X X X X X X X XXX",
                    "X X   X X   X   X   X",
                    "X XXX XXXXXXXXX XXX X",
                    "X                 X X",
                    "XXXXXXXXXXXXXXXXXXXSX"
                });

    Start();
    cout << "\033[1;31m	ENTRADA (10, 0)\033[0m" << endl;
    if(labirinto.solve(10, 0)) {         
      	labirinto.showLab();
        cout << "\033[1;31mCAMINHO ENCONTRADO!!\033[0m\n";
	} else 
        cout << "NENHUM CAMINHO ENCONTRADO!!" << endl;
}
