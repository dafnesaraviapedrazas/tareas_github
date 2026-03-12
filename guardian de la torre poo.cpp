#include <iostream>
using namespace std;

class Torre{
private:
	int fila;
	int columna;
	bool esNegra;
	bool validarMovimiento(int nFila, int nCol){
		if((fila == nFila && columna != nCol) || (columna == nCol && fila != nFila)){
			return true;
		}
		return false;
	}
public:
			Torre(bool color, int fInicial, int cInicial){
				esNegra = color;
				fila = fInicial;
				columna = cInicial;
			}
			string dibujar(){
				if(esNegra)
					return "[##]";
				else
					return "[TT]";
			}
				void mover(int nFila, int nCol){
					if(nFila < 1 || nFila > 8 || nCol < 1 || nCol > 8){
						cout << "Movimiento fuera del tablero" << endl;
						return;
					}
					if(validarMovimiento(nFila, nCol)){
						fila = nFila;
						columna = nCol;
						cout << "Movimiento realizado" << endl;
					}else{
						cout << "Movimiento diagonal no permitido para la Torre" << endl;
					}
				}
					void imprimirEstado(){
						cout << dibujar() << " ";
						if(esNegra)
							cout << "Negra ";
						else
							cout << "Blanca ";
						cout << "en Fila: " << fila << ", Col: " << columna << endl;
					}
};

int main(){
	Torre t1(false,1,1);
	Torre t2(true,8,8);
	cout << "ESTADO ACTUAL DEL TABLERO:" << endl;
	t1.imprimirEstado();
	t2.imprimirEstado();
	int f,c;
	cout << "Ingrese fila destino para la Torre Blanca: ";
	cin >> f;
	cout << "Ingrese columna destino: ";
	cin >> c;
	
	t1.mover(f,c);

	cout << "\nNUEVO ESTADO DEL TABLERO:" << endl;
	t1.imprimirEstado();
	t2.imprimirEstado();
	return 0;
}
