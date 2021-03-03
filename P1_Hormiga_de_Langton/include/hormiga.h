/**
 * AUTOR: Gabriel Alberto Luis Freitas
 * FECHA: 03/03/2021
 * EMAIL: alu0101348421@ull.edu.es
 * VERSION: 1.0
 * PRACTICA: Hormiga de Langton
 * FICHERO: hormiga.h
 * COMENTARIOS: Fichero con las cabeceras del objeto hormiga
 * ENTIDAD: Universidad de La Laguna
*/

#include <iostream>
#include <utility>

#define UP '^'
#define RIGHT '>'
#define DOWN 'v'
#define LEFT '<'
#define NONE ' '

class hormiga
{
public:
    /// Constructores
    hormiga();
    hormiga(std::pair<int, int>);

    ~hormiga(); ///< Destructor

    void Move(char); ///< Metodo para mover a la hormiga
    void MoveByColor(bool); ///< Metodo para mover a la hormiga dependiendo del fondo de la cuadricula

    /// Getters
    char GetLastMovement();
    std::pair<int, int> GetPosition();

private:
    std::pair<int, int> position_; ///< Posicion de la hormiga
    char last_movement_; ///< Ultimo movimiento
};