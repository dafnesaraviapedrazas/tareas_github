#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria{
private: 
	int id;
	string nroCuenta;
	double saldo;
	
public: 
	string propietario;
	CuentaBancaria(int di, string nro, string prop){
		id=di;
		nroCuenta=nro;
		saldo=0;
		propietario=prop;
	}
	void depositar(double monto){
		if(monto<=0){
			saldo+=monto;
			cout<<"Deposito realizado";
		}
		else{
			cout<<"Monto inválido";
		}
	}
		
	bool retirar(double monto){
		if (monto <=0){
			cout<<"Monto inválido"<< endl;
		return false;
	}
		if (monto>saldo){
			cout<<"Fondos insuficientes"<<endl;
			return false;
		}
	    saldo -=monto;
		return true;
	}
		
	void transferir(CuentaBancaria &destino, double monto){
		if(retirar(monto)){
			destino.depositar(monto);
			cout<<"Transferencia exitosa"<<endl;
		}
		else{
			cout<<"No se pudo transferir"<<endl;
		}
	}
			
	void verEstado(){
		cout<<"ID: "<<id<<endl;
		cout<<"Nro Cuenta: "<<nroCuenta<<endl;
		cout<<"Propietario: "<<propietario<<endl;
		cout<<"Saldo: "<<saldo<<endl;
		cout<<"----------------"<<endl;
		}
};
int main(int argc, char *argv[]) {
	CuentaBancaria cuentaA(1,"A001","Sally Hawkins");
	CuentaBancaria cuentaB(2,"B001","Billy Barratt");

	cuentaA.depositar(1000);
	
	cuentaA.retirar(2000);
	
	cuentaA.transferir(cuentaB,500);
	
	cuentaA.verEstado();
	cuentaB.verEstado();
	
	
	return 0;
}

