/**
 * AUTOR: Gabriel Alberto Luis Freitas
 * FECHA: 03/03/2021
 * EMAIL: alu0101348421@ull.edu.es
 * VERSION: 1.0
 * PRACTICA: Hormiga de Langton
 * FICHERO: hormiga.cc
 * COMENTARIOS: Fichero con los métodos del objeto hormiga
 * ENTIDAD: Universidad de La Laguna
*/

#include "hormiga.h"

///Constructor por defecto
hormiga::hormiga()
{
    position_.first = 0;
    position_.second = 0;
    last_movement_ = UP;
}

/// Constructor con posicion inicial
hormiga::hormiga(std::pair<int, int> initial_ant_position)
{
    position_ = initial_ant_position;
    last_movement_ = UP;
}

/// Destructor
hormiga::~hormiga(void){
    delete &position_;
    delete &last_movement_;
}

/// Metodo para mover a la hormiga segun un caracter
void hormiga::Move(char movement)
{
    switch (movement)
    {
    case UP:
        position_.second--;
        last_movement_ = UP;
        break;
    case RIGHT:
        position_.first++;
        last_movement_ = RIGHT;
        break;
    case DOWN:
        position_.second++;
        last_movement_ = DOWN;
        break;
    case LEFT:
        position_.first--;
        last_movement_ = LEFT;
        break;

    default:
        last_movement_ = NONE;
        break;
    }
}

/// Metodo para mover a la hormiga dependiendo del color de fondo
void hormiga::MoveByColor(bool black)
{
    if (!black)
    {
        switch (last_movement_)
        {
        case UP:
            last_movement_ = LEFT;
            position_.first--;
            break;
        case RIGHT:
            last_movement_ = UP;
            position_.second--;
            break;
        case DOWN:
            last_movement_ = RIGHT;
            position_.first++;
            break;
        case LEFT:
            last_movement_ = DOWN;
            position_.second++;
            break;

        default:
            break;
        }
    }
    else
    {
        switch (last_movement_)
        {
        case UP:
            last_movement_ = RIGHT;
            position_.first++;
            break;
        case RIGHT:
            last_movement_ = DOWN;
            position_.second++;
            break;
        case DOWN:
            last_movement_ = LEFT;
            position_.first--;
            break;
        case LEFT:
            last_movement_ = UP;
            position_.second--;
            break;
        }
    }
}

///Getter para obtener el ultimo movimiento de la hormiga
char hormiga::GetLastMovement(void)
{
    return last_movement_;
}

/// Getter para obtener la posicion de la hormiga
std::pair<int, int> hormiga::GetPosition(void)
{
    return position_;
}