#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
#include "maraton.h"
#include <cstdlib>

#define CLS system("cls")
#define PAUSE system("pause")
using namespace std;


int main()
{
    char p[]="huelvapro.dat", r[]="huelva.dat";
    Maraton Huelva(p,r);
    char opcion;

    do
    {
        CLS;
        cout << "Maraton de Huelva"<<endl
             << "------------------------------"<<endl
             << "Atletas: "<<Huelva.getNumAtletas()<<endl
             << "\n\t1. Consulta de inscripciones\n\t2. Inscripciones a la maraton\n\t3. Modificar una inscripcion\n\t4. Eliminar una inscripcion\n\t5. Mostrar clasificacion\n\t6. Salir\n\nIndique la opcion deseada: ";

        opcion = getche();

        switch(opcion)
        {
            case '1':
            {
                CLS;
                cadena consulta;
                cout<<"Introduce pais a consultar (Todos: *) -> ";
                cin>>consulta;

                Huelva.consultar(consulta);
                break;
            }

            case '2':
            {
                CLS;
                cin.clear();
                cadena pais, nombre, apellido;
                int dorsal;
                Atleta Ainsertar;

                cout << "Introduce dorsal -> ";
                cin >> dorsal;


                cout << "\nIntroduce pais -> ";
                cin >> pais;
                cout <<"\nIntroduce nombre -> ";
                cin >> nombre;
                cout <<"\nIntroduce apellidos -> ";
                cin>>apellido;

                Ainsertar.dorsal = dorsal;
                strcpy(Ainsertar.apellidos,apellido);
                strcpy(Ainsertar.nombre,nombre);
                strcpy(Ainsertar.pais,pais);
                Ainsertar.marca=0;
                Ainsertar.posicion=0;

                Huelva.insertar(Ainsertar);

                break;
            }
            case '3':
                {
                    int dorsal;
                    CLS;
                    cout << "\nIntroduce dorsal a modificar -> ";
                    cin >> dorsal;
                    Huelva.modificar(dorsal);
                    break;
                }

            case '4':
                {
                    int dorsal;
                    CLS;
                    cout << "\nIntroduce dorsal a eliminar -> ";
                    cin >> dorsal;
                    cin.get();
                    Huelva.eliminar(dorsal);
                    break;
                }
            case '5':
                {
                    CLS;
                    Huelva.mostrarClasificacion();
                    break;
                }
            case '6':
                cout <<"\nSaliendo...";
                break;

            default:
                cout<<"\nOpcion no valida!";
                break;
        }
        cout <<endl<<endl;
        PAUSE;
    }while(opcion!='6');


    return 0;


}
