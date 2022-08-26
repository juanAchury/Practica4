
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

string cos();
void menu();
void imprimir();
void imprimirC();
void llamar();
void llamr1();

struct Enrutador{      //Declaracion del objeto Enrutador con dos tipos de variables
    string nombre;
    int costo;
};

// Mapa contodos los datos de los enrutadores
map<string,vector<Enrutador>> cargarDatos(map<string,vector<Enrutador>> contenedor){
   Enrutador enrutador;

   enrutador.nombre="A";
   enrutador.costo=0;
   contenedor["A"].push_back(enrutador);

   enrutador.nombre="B";
   enrutador.costo=4;
   contenedor["A"].push_back(enrutador);

   enrutador.nombre="C";
   enrutador.costo=7;
   contenedor["A"].push_back(enrutador);

   enrutador.nombre="D";
   enrutador.costo=5;
   contenedor["A"].push_back(enrutador);

   enrutador.nombre="A";
   enrutador.costo=4;
   contenedor["B"].push_back(enrutador);

   enrutador.nombre="B";
   enrutador.costo=0;
   contenedor["B"].push_back(enrutador);

   enrutador.nombre="C";
   enrutador.costo=3;
   contenedor["B"].push_back(enrutador);

   enrutador.nombre="D";
   enrutador.costo=1;
   contenedor["B"].push_back(enrutador);

   enrutador.nombre="A";
   enrutador.costo=7;
   contenedor["C"].push_back(enrutador);

   enrutador.nombre="B";
   enrutador.costo=3;
   contenedor["C"].push_back(enrutador);

   enrutador.nombre="C";
   enrutador.costo=0;
   contenedor["C"].push_back(enrutador);

   enrutador.nombre="D";
   enrutador.costo=2;
   contenedor["C"].push_back(enrutador);

   enrutador.nombre="A";
   enrutador.costo=5;
   contenedor["D"].push_back(enrutador);

   enrutador.nombre="B";
   enrutador.costo=1;
   contenedor["D"].push_back(enrutador);

   enrutador.nombre="C";
   enrutador.costo=2;
   contenedor["D"].push_back(enrutador);

   enrutador.nombre="D";
   enrutador.costo=0;
   contenedor["D"].push_back(enrutador);




   return contenedor;
}

// Inserta el vector ya ordenado
vector<Enrutador> insertarOrdenado(vector<Enrutador> v, Enrutador p){
    auto elemento = begin(v);
    while ((elemento != end(v)) and ((*elemento).costo <= p.costo)){
        elemento++;
    }
    v.insert(elemento, p);

    return v;
}

//Mira donde poner los costos
vector<Enrutador> filtrarCostos(vector<Enrutador> CostosNodo){
    vector<Enrutador> nuevo;
    for (auto emp = begin(CostosNodo); emp != end(CostosNodo); emp++){
        nuevo=insertarOrdenado(nuevo, (*emp));
    }
    return nuevo;
}

//Imprime los costos
void imprimirC(vector<Enrutador> contenedor){

    for (auto emp = begin(contenedor); emp != end(contenedor); emp++){
        cout << "Hasta : " << emp->nombre << " | Cuesta: " << emp->costo << endl;
    }
}

int main()
{
   menu();

   return 0;
}



//Funcion que me imprime toda la red con los valores
void imprimir(map<string,vector<Enrutador>> contenedor){
    for (auto par = begin(contenedor); par != end(contenedor); par++){
        cout << endl << "------- " << par->first<<" --------" << endl;
        for (auto emp = begin(par->second); emp != end(par->second); emp++){
            cout << "Nodo: " << emp->nombre << " | Costo: " << emp->costo << endl;
        }
    }
}


//Llamar la funcion que muestra toda la tabla
void llamar(){
    map<string,vector<Enrutador>> Red;
    Red=cargarDatos(Red);
    imprimir(Red);
}

//Llamar la funcion para mostrar los vectores ordenados
void llamar1(){
    map<string,vector<Enrutador>> cos;
    cos=cargarDatos(cos);
    vector<Enrutador> filtrado;
    string nodo;
    do{

        cout << "Nodo a filtrar: ";
        cin >> nodo;

       } while (cos.find(nodo) == end(cos));


    filtrado=filtrarCostos(cos[nodo]);
    cout<<"----------"<<nodo<<"----------"<<endl;
    imprimirC(filtrado);

}
// Menu para las diferentes funciones
void menu(){
    int opcion;

    do{


        cout<<"   [____MENU____]"<<endl;
        cout<<"1. Visualizar Tabla "<<endl;
        cout<<"2. Costos de Enlaces "<<endl;

        cout<<"4. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;

        switch(opcion){

            case 1: llamar();

                    cout<<"\n";
                    system("pause");
                    break;
            case 2: llamar1();
                    cout<<"\n";
                    system("pause");
                    break;

        }
        system("cls");
    }while(opcion!=4);
}






/*#include <iostream>

using namespace std;

class enrutador{
private: //Atributos
    int distancia;
    string nombre;

public: //Metodos

    enrutador(nombre,distancia); //constructor
    void mostrar enrutador();

};

// Constructor de la clase enrutador
enrutador::enrutador(int _distancia, string _nombre){

    distancia = _distancia;
    nombre  = _nombre;


}

void enrutador :: mostrarenrutador(){
    cout<<"Enrutaor"<<nombre<<endl;
    cout<<"Distancia"<<distancia<<endl;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
*/
