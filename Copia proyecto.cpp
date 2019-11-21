
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void Menu(); //declarando prototipo de la funcion SIEMPRE ANTES DEL MAIN
int RegistroCliente();
int habitacion();
int EstadodeHabitaciones();
int ConsultaCliente();
int VaciarHabitaciones();
int habitacionEstado[10];
float aux;

int main(){
    string line;
    int opcion, DUIbusq;
    cout<<"Bienvenido al Holiday"<<endl;
    //El menu se ejecuta mientras la opcion sea distinta a cero
    do{
        Menu(); //Mandando a llamar la funcion
        cin>>opcion;
    switch(opcion){
        case 1:
        RegistroCliente();
        break;
        case 2: habitacion(); //<-- se tiene que poner break por cada case?
        break;
        case 3: EstadodeHabitaciones();
        break;
        case 4: ConsultaCliente();
        break;
        case 5: VaciarHabitaciones();
        break;
     }
    }while(opcion !=0); //condicion linea 17, con el do.

    return 0;
}

//funcion
void Menu(){
    cout<<"1. Registrar cliente . . . "<<endl; //Reservar el cuarto
    cout<<"2. Reservar la habitacion . . ."<<endl;//Numero de la habitacion
    cout<<"3. Consultar el estado de la habitacion"<<endl;//Si es una habitacion ocupada y otra disponible
    cout<<"4. Consultar cliente"<<endl; //Comparar si el cliente ya esta repetido a travez del dui
    cout<<"5. Vaciar habitacion"<<endl; //Vacia la habitacion cuando termina el tiempo de reserva
    cout<<"0. Salir\t Opcion "<<endl;
}
int RegistroCliente(){
    string nombre, correo;
    int DUI, telefono;
    ofstream RegistrarCliente("RegistrarCliente2.csv", ios:: app);
    //RegistrarCliente.open("RegistrarCliente.csv");
    cout<<"Ingrese nombre de cliente: "<<endl;
    cin>>nombre;
    RegistrarCliente<<nombre<<",";
    cout<<endl;
    cout<<"Ingrese el DUI: "<<endl;
    RegistrarCliente<<DUI;
    cout<<endl;
    cout<<"Numero de telefono: "<<endl;
    cin>>telefono;
    cout<<endl;
    cout<<"Correo electronico: "<<endl;
   cin>>correo;
    cout<<endl;
    RegistrarCliente.close();


}

int habitacion(){           //Esta funcion es llamada cuando en el menu se presiona 2, para seleccionar habitacion.
    int tipo;
    int num_habitacion, numDui, dias;
    float precio1=100, precio2=250;
    EstadodeHabitaciones();
    cout<<"Tipos de habitaciones:  1.Habitacion normal. 2.suit presidencial.";
    ofstream ReservaHabitacion("ReservaHabitacion.xlsx");
    cout<<"TIPO DE HABITACIÓN QUE DESEA RESERVAR."<<endl;
    cin>>tipo;
    if(tipo==1){ //Este if se cumple  cuando se selecciona el tipo de habitacion en la linea 60.
    cout<<"Ingrese el numero de la habitación: "<<endl;
    cin>>num_habitacion;
        if(num_habitacion<=5){  //Este if es para las habitaciones normales que es 1.
        cout<<"Ingrese DUI del cliente: "<<endl;
        cin>>numDui;
        cout<<"Días a reservar: "<<endl;
        cin>>dias;
        cout<<"HABITACION RESERVADA. . ."<<endl;
        cout<<"MONTO A PAGAR: "<<precio1*dias<<endl;
        habitacionEstado[num_habitacion-1]=1;


    }else{
        cout<<"HABITACION NO DISPONIBLE(habitacion es NORMAL)";
    }


   }else if(tipo==2){

    cout<<"Ingrese el numero de la habitación: "<<endl;
    cin>>num_habitacion;
    if(num_habitacion > 5 && num_habitacion <= 10){ //Este if es para las habitaciones suit, con numero 2, son los cuartos del 6-10.
        cout<<"Ingrese DUI del cliente: "<<endl;
        cin>>numDui;
        cout<<"Días a reservar: "<<endl;
        cin>>dias;
        cout<<"HABITACION RESERVADA. . ."<<endl;
        cout<<"MONTO A PAGAR: "<<precio2*dias<<endl;
        habitacionEstado[num_habitacion-1]=1;
    }else{
        cout<<"HABITACION NO DISPONIBLE(habitacion es NORMAL)";
    }

   }
}

int ConsultaCliente(){           //Esta funcion es llamada cuando en el menu se presiona 4, para consultar un cliente.
     ifstream RegistrarCliente;
     RegistrarCliente.open("C:/Users/Roberto/Desktop/xxx");

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
