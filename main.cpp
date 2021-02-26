//Cátedra de Tecnología de Sistemas
//Introducción a la Programación
//Segundo cuatrimestre 2020
//Estudiante: Yesenia Obando Díaz
//               Tarea #1



#include <iostream>
#include <iomanip>
#include <cstdlib> // contiene los prototipos de srand y rand
#include <ctime> // incluye el prototipo de la funcion time

using namespace std;
using std::setw;
using std:: endl;

//declaramos las matrices
int matrizNum [10][10];
string matrizLet [10][10];

//prototipos de las funciones, basado en ejemplo del libro pagina 184
void generaMatriz ();
void imprimeMatriz ();

int main()
{

generaMatriz();
imprimeMatriz();

return 0;
}


void generaMatriz()
{

//Creamos la matriz y la llenamos de numeros aleatorios

srand( time(0) ); // randomiza el generador de numeros aleatorios mediante la hora actual, basado en ejemplo del libro, pagina 175


    for(int i= 0; i < 10; i++)
    {
      for (int j = 0; j < 10; j++)
      {
         matrizNum [i][j] = 1 + rand ()% 499;; // llena la matriz de esos numeros aleatorios (basado en ejemplo del libro, pagina 171)
      }
    cout << "\n";
    }


//Clasificamos numeros. Para esta seccion me base en diferentes videos de Youtube. Para ver detalle, leer el .txt que se adjunta a la tarea

//Declaramos variables
int suma = 0;
int divisor = 0;


    for(int i= 0; i < 10; i++)
    {
       for (int j = 0; j < 10; j++)
       {

        suma=0;
        divisor=matrizNum[i][j]-1;   //esta variable va calculando los divisores de cada numero de la matriz numerica

          for (divisor;divisor>0;divisor--) //la variable empieza en el numero dado y se va devolviendo, para en 0
          {
                if(matrizNum[i][j] % divisor == 0){
                    suma = suma+divisor;  // suma de los divisores del numero
                }

          }
            if (matrizNum[i][j]==suma) //pregunta si el numero es igual a la suma de los divisores, si es asi entonces es perfecto
            {
                matrizLet[i][j]= "P";
            }
            if (matrizNum[i][j]>suma)  //pregunta si el numero es mayor a la suma de los divisores, si es asi entonces es abundante
            {
                matrizLet [i][j]= "A";
            }
            if (matrizNum[i][j]<suma)  //pregunta si el numero es menor a la suma de los divisores, si es asi entonces es deficiente
            {
                matrizLet[i][j]= "D";
            }
        }
    }
}


void imprimeMatriz()
{

cout<< "    ***************************************************************************************************    " << endl;
cout<< "    ***********************************      Matriz numerica       ************************************    " << endl;
cout<< "    ***************************************************************************************************    " << endl;


    for(int i= 0; i < 10; i++)
    {
    for (int j = 0; j < 10; j++)
      {
         cout << setw(10) << matrizNum [i] [j]; //muestra la matriz numerica
      }
    cout << "\n";
    }

cout<< "    ***************************************************************************************************    " << endl;
cout<< "    ****************************       Clasificacion de los numeros         ***************************    " << endl;
cout<< "    **************************** P: perfecto   A: abundante    D: deficiente***************************    " << endl;
cout<< "    ***************************************************************************************************    " << endl;

    for(int i= 0; i < 10; i++)
    {
       for (int j = 0; j < 10; j++)
       {
        cout << setw(10) << matrizLet [i][j]; //muestra la matriz de letras
       }
       cout << "\n";
    }
}


