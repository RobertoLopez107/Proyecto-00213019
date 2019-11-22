#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> //libreria externa empleada en funcion ConsultaCliente

using namespace std;
//declarando prototipos de las funciones SIEMPRE ANTES DEL MAIN
void Menu(); 
int RegistroCliente();
int habitacion();
int EstadodeHabitaciones();
int ConsultaCliente();
int VaciarHabitaciones();
int habitacionEstado[10];
float aux;

int main(){
    string line;
    int opcion;
    cout<<"Bienvenido al Holiday"<<endl;
    //El menu se ejecuta mientras la opcion sea distinta a cero
    do{
        Menu(); //Mandando a llamar la funcion
        cin>>opcion;
    switch(opcion){
        case 1:
        RegistroCliente();
        break;
        case 2: habitacion(); 
        break;
        case 3: EstadodeHabitaciones();
        break;
        case 4: ConsultaCliente();
        break;
        case 5: VaciarHabitaciones();
        break;
     }
    }while(opcion !=0); //condicion para salir o continuar en el menu

    return 0;
}

//funcion
void Menu(){
    cout<<"1. Registrar cliente . . . "<<endl; //Registra los datos personales del cliente
    cout<<"2. Reservar la habitacion . . ."<<endl;//Reserva la habitacion del cliente
    cout<<"3. Consultar el estado de la habitacion"<<endl;//Si es una habitacion ocupada y otra disponible
    cout<<"4. Consultar cliente"<<endl; //Consultar los datos personales del cliente
    cout<<"5. Vaciar habitacion"<<endl; //Vacia la habitacion cuando termina el tiempo de reserva
    cout<<"0. Salir\t Opcion "<<endl;
}
int RegistroCliente(){
    string nombre, correo;
    int DUI_clientes[100];// 100 es solamente un numero de prueba
    int telefono, DUI;
    ofstream RegistrarCliente("RegistrarCliente2.csv", ios:: app); //se abre el doc para modificarlo "ios:: app" permite que no se destruya la info por cada ejecucion
    cin.ignore(); //Limpia el buffer
    cout<<"Ingrese nombre de cliente: "<<endl;
    getline(cin, nombre);//permite trabajar con espacios
    RegistrarCliente<<nombre<<",";//ingresa el dato al archivo csv
    cout<<endl;
    cout<<"Ingrese el DUI: "<<endl;
    cin>>DUI;
    RegistrarCliente<<DUI<<","; //ingresa el dato al archivo csv
    cout<<endl;
    cout<<"Numero de telefono: "<<endl;
    cin>>telefono;
    RegistrarCliente<<telefono<<",";//ingresa el dato al archivo csv
    cout<<endl;
    cout<<"Correo electronico: "<<endl;
    cin>>correo;
    RegistrarCliente<<correo<<",";//ingresa el dato al archivo csv
    cout<<endl;
    RegistrarCliente.close(); //ciera el csv despues del ingreso de datos


}

int habitacion(){           //Esta funcion es llamada cuando en el menu se presiona 2, para seleccionar habitacion.
    int tipo;
    int num_habitacion, numDui, dias, total;
    float precio1=100, precio2=250;
    EstadodeHabitaciones();// se manda a llamar la funcion para que el cliente conozca de antemano cuales habitaciones se encuentran disponibles ASI COMO EN EL CINE
    cout<<"Tipos de habitaciones:  1.Habitacion normal. 2.suit presidencial.";
    ofstream ReservaHabitacion("ReservaHabitacion.csv", ios:: app); // se crea otro csv pero ahora para la reserva de habitaciones
    cout<<"TIPO DE HABITACIÓN QUE DESEA RESERVAR."<<endl;
    cin>>tipo;
    ReservaHabitacion<<tipo<<",";
    cout<<endl;
    if(tipo==1){ //Este if permite ingresar para hab normales.
    cout<<"Ingrese el numero de la habitación: "<<endl;
    cin>>num_habitacion;
    ReservaHabitacion<<num_habitacion<<",";
    cout<<endl;
        if(num_habitacion<=5){  //Este if es para las habitaciones normales que es 1.
        cout<<"Ingrese DUI del cliente: "<<endl;
        cin>>numDui;
        ReservaHabitacion<<numDui<<",";
        cout<<endl;
        cout<<"Días a reservar: "<<endl;
        cin>>dias;
        ReservaHabitacion<<dias<<",";
        cout<<endl;  
        cout<<"HABITACION RESERVADA. . ."<<endl;
        total=precio1*dias;
        cout<<"MONTO A PAGAR: "<<total<<endl;
        habitacionEstado[num_habitacion-1]=1;
        ReservaHabitacion<<total<<",";
        cout<<endl;
        ReservaHabitacion<<"1"<<",";
        cout<<endl;
        ReservaHabitacion.close();

    }else{	
        cout<<"HABITACION NO DISPONIBLE(habitacion es PRESIDENCIAL)"; //aviso que el numero de la habitacion que ha seleccionado es SUITE PRESIDENCIAL
    }


   }else if(tipo==2){

    cout<<"Ingrese el numero de la habitación: "<<endl;
    cin>>num_habitacion;
    ReservaHabitacion<<num_habitacion<<",";
    cout<<endl;
    if(num_habitacion > 5 && num_habitacion <= 10){ //Este if es para las habitaciones suit, con numero 2, son los cuartos del 6-10.
        cout<<"Ingrese DUI del cliente: "<<endl;
        cin>>numDui;
        ReservaHabitacion<<numDui<<",";
        cout<<endl;
        cout<<"Días a reservar: "<<endl;
        cin>>dias;
        ReservaHabitacion<<dias<<",";
        cout<<endl;
        cout<<"HABITACION RESERVADA. . ."<<endl;
        total=precio2*dias;
        cout<<"MONTO A PAGAR: "<<total<<endl;
        habitacionEstado[num_habitacion-1]=1;
        ReservaHabitacion<<total<<",";
        cout<<endl;
        ReservaHabitacion<<"1"<<",";
        cout<<endl;
        
    }else{
        cout<<"HABITACION NO DISPONIBLE(habitacion es NORMAL)";
    }

   }
}

int ConsultaCliente(){           //Esta funcion es llamada cuando en el menu se presiona 4, para consultar un cliente.
    ifstream RegistroCliente;
    string nombre, DUIbusq, numTelefono, DUI;
    int res =0;
    
    cout<<"Ingrese DUI del cliente a buscar: "<<endl;
    cin>>DUIbusq;
    if(!RegistroCliente.is_open()){
          RegistroCliente.open("RegistrarCliente2.csv", ios::in);
	}
    while(getline(RegistroCliente, DUI)){
    	if(DUI.find(DUIbusq)!= string::npos){
    		cout<<DUI<<endl;
    		getline(RegistroCliente, nombre);
    		cout<<nombre;
    		getline(RegistroCliente, numTelefono);
    		cout<<numTelefono;
    		res = 1;
		}
	}
    if(res ==0){
    	cout<<DUIbusq<<" No encontrado. . ."<<endl;
	}
	system("pause");
}

int EstadodeHabitaciones(){
    for(int i=0; i<5; i++){
        if(habitacionEstado[i]==1){
            cout<<"Habitacion normal "<<i+1<<" esta ocupada"<<endl;

        }else{
            cout<<"Habitacion normal "<<i+1<<" esta vacia"<<endl;
        }
    }

    for(int j=5; j<10;j++){
        if(habitacionEstado[j]==1){
            cout<<"Habitacion suit "<<j+1<<" esta ocupada"<<endl;

        }else{
            cout<<"Habitacion suit "<<j+1<<" esta vacia"<<endl;
        }


    }

}

int VaciarHabitaciones(){
    int hab=0;

    cout<<"Habitacion que desea liberar "<<endl;
    cin>>hab;
    habitacionEstado[hab-1]=0;

}
