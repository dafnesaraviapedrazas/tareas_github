#include <iostream>
#include <string>
using namespace std;

class Player {
	
private:
	short opcionJugada;
	int puntaje;
	
	int evaluar(Player contrario){
		if(opcionJugada == contrario.opcionJugada)
			return 0;
		if(
		   (opcionJugada == 1 && contrario.opcionJugada == 3) ||
		   (opcionJugada == 2 && contrario.opcionJugada == 1) ||
		   (opcionJugada == 3 && contrario.opcionJugada == 2)
		   )
			return 1;
		
		return -1;
	}
		
public:
			string nombre;
			Player(){
				puntaje = 0;
			}
				Player(int puntajeInicial){
					puntaje = puntajeInicial;
				}
					void seleccionar(){
						cout << nombre << " seleccione jugada (1:()iedra 2:[]Papel 3: 8< Tijera): ";
						cin >> opcionJugada;
					}
						string traducir(){
							if(opcionJugada == 1) return "Piedra";
							if(opcionJugada == 2) return "Papel";
							if(opcionJugada == 3) return "Tijera";
							return "?";
						}
							void jugar(Player &contrario){
								int resultado = evaluar(contrario);
								cout << nombre << " (" << traducir() << ") VS "
									<< contrario.nombre << " (" << contrario.traducir() << ")" << endl;
								if(resultado == 1){
									puntaje++;
									cout << "Gana la ronda: " << nombre << endl;
								}
								else if(resultado == -1){
									contrario.puntaje++;
									cout << "Gana la ronda: " << contrario.nombre << endl;
								}
								else{
									cout << "Empate" << endl;
								}
								cout << endl;
							}
								float obtenerEficiencia(int nroPartidas){
									return (puntaje / (float)nroPartidas) * 100.0;
								}
};

int main(){
	Player p1, p2, p3;
	p1.nombre = "William";
	p2.nombre = "Damaris";
	p3.nombre = "Dafne";
	
	for(int i = 0; i < 3; i++){
		cout << "------ RONDA " << i+1 << " ------" << endl;
		p1.seleccionar();
		p2.seleccionar();
		p1.jugar(p2);
		p2.seleccionar();
		p3.seleccionar();
		p2.jugar(p3);
	}
	cout << "------ RESULTADOS ------" << endl;
	cout << p1.nombre << " eficiencia: " << p1.obtenerEficiencia(3) << "%" << endl;
	cout << p2.nombre << " eficiencia: " << p2.obtenerEficiencia(3) << "%" << endl;
	cout << p3.nombre << " eficiencia: " << p3.obtenerEficiencia(3) << "%" << endl;
	
	return 0;
}

