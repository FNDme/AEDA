/**
 * AUTOR: Gabriel Alberto Luis Freitas
 * FECHA: 03/03/2021
 * EMAIL: alu0101348421@ull.edu.es
 * VERSION: 1.0
 * PRACTICA: Hormiga de Langton
 * FICHERO: mundo.cc
 * COMENTARIOS: Fichero con los métodos del objeto mundo
 * ENTIDAD: Universidad de La Laguna
*/

#include "mundo.h"

/// Constructor
mundo::mundo(int filas, int columnas)
{
    filas_ = filas;
    columnas_ = columnas;
    matrix_ = std::vector<std::vector<bool>>(columnas, std::vector<bool>(filas, false));
}

/// Destructor
mundo::~mundo(void){
    delete[] &matrix_;
    delete &filas_;
    delete &columnas_;
}

/// Metodo para cambiar el color de una posicion
void mundo::ChangeColor(std::pair<int, int> position)
{
    matrix_[position.first][position.second] = !matrix_[position.first][position.second];
}

/// Metodo para imprimir el mapa
void mundo::Write()
{
    for (int j = 0; j < filas_; j++)
    {
        for (int k = 0; k < columnas_; k++)
        {
            std::cout << " - ";
        }
        std::cout << '\n';
        for (int k = 0; k < columnas_; k++)
        {
            std::cout << "|" << GetColor(j, k) << "|";
        }
        std::cout << '\n';
    }
    

    for (int i = 0; i < columnas_; i++)
    {
        std::cout << " - ";
    }
    std::cout << '\n';
}

/// Metodo para la comprobacion de una posicion en el mapa
bool mundo::IsOk(std::pair<int, int> position)
{
    if (position.first > columnas_ || position.first < 0 || position.second > filas_ || position.second < 0)
        return 0;
    else
        return 1;
}

///Getters
bool mundo::GetColor(std::pair<int, int> position)
{
    return matrix_.at(position.first).at(position.second);
}

bool mundo::GetColor(int X, int Y)
{
    return matrix_.at(X).at(Y);
}

int mundo::GetFilas(void)
{
    return filas_;
}

int mundo::GetColumnas(void)
{
    return columnas_;
}