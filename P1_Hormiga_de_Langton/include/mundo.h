/**
 * AUTOR: Gabriel Alberto Luis Freitas
 * FECHA: 03/03/2021
 * EMAIL: alu0101348421@ull.edu.es
 * VERSION: 1.0
 * PRACTICA: Hormiga de Langton
 * FICHERO: mundo.h
 * COMENTARIOS: Fichero con las cabeceras del objeto mundo
 * ENTIDAD: Universidad de La Laguna
*/

#include <iostream>
#include <vector>


class mundo
{
public:
    mundo(int, int); ///< constructor
    ~mundo(); ///< destructor

    void ChangeColor(std::pair<int, int>); ///< Método para cambiar el color de una posicion
    void Write(); ///< Método para imprimir el mundo
    bool IsOk(std::pair<int, int>); ///< Método para comprobar si una posicion existe en el mundo

    ///getters
    int GetFilas();
    int GetColumnas();
    bool GetColor(std::pair<int, int>);
    bool GetColor(int, int);

private:
    std::vector<std::vector<bool>> matrix_; ///< mapa del mundo identificado por colores (false:white - true:black)
    int filas_; ///< numero de filas del mundo
    int columnas_; ///< numero de columnas del mundo
};