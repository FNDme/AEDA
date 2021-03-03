/**
 * AUTOR: Gabriel Alberto Luis Freitas
 * FECHA: 03/03/2021
 * EMAIL: alu0101348421@ull.edu.es
 * VERSION: 1.0
 * PRACTICA: Hormiga de Langton
 * FICHERO: main.cc
 * COMENTARIOS: Fichero con la función main que desarrolla la Hormiga de Langton
 * ENTIDAD: Universidad de La Laguna
*/

#include <iostream>
#include <stdlib.h>
#include "mundo.h"
#include "hormiga.h"

int main(void)
{
    /// Solicitud de elementos necesarios para la construccion del mundo y la hormiga
    std::cout << "Introduzca el numero de filas del mundo: ";
    int filas;
    std::cin >> filas;
    std::cout << "Introduzca el numero de columnas del mundo: ";
    int columnas;
    std::cin >> columnas;

    std::pair<int, int> initialAntPosition;
    std::cout << "Introduzca la fila inicial de la hormiga: ";
    std::cin >> initialAntPosition.first;
    std::cout << "Introduzca la columna inicial de la hormiga: ";
    std::cin >> initialAntPosition.second;

    ///Comprobaciones necesarias para evitar malos funcionamientos

    if (filas < 0 || columnas < 0)
    {
        std::cout << "Error: el numero de filas o columnas indicado del mundo no es correcto\n";
        return 1;
    }

    if (initialAntPosition.first < 0 || initialAntPosition.second < 0 || initialAntPosition.first > filas || initialAntPosition.second > columnas)
    {
        std::cout << "Error: la posicion inicial de la hormiga no es correcto\n";
        return 2;
    }

    /// Objetos
    mundo world(filas, columnas);
    hormiga ant(initialAntPosition);

    /// Bucle de desarrollo del mundo y la hormiga
    while (world.IsOk(ant.GetPosition()))
    {
        std::cout << "Hormiga de Langton\n\n";
        for (int i = 0; i < world.GetFilas(); i++)
        {
            std::cout << '\n';
            for (int j = 0; j < world.GetColumnas(); j++)
            {
                if (ant.GetPosition().first == j && ant.GetPosition().second == i)
                    std::cout << ant.GetLastMovement();
                else
                {
                    if(world.GetColor(j, i))
                        std::cout << " ";
                    else
                        std::cout << "█";
                }
            }
        }
        std::cout << "\n\n\n";
        world.ChangeColor(ant.GetPosition());
        ant.MoveByColor(world.GetColor(ant.GetPosition()));
        std::cin.ignore();
        system("clear");
    }

    /// Fin del juego
    std::cout << "Fin del Juego\n\n";
    std::cin.ignore();
}