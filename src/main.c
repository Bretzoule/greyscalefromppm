/*! 
 *  \file main.c
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Jeu 17 Décembre 2020 - 09:55:39
 *
 *  \brief programme du tp10
 *
 *
 */

// Inclusion des entetes de librairies

#include <time.h>
#include "operationSelector.h"

/*!
 *  \fn int main (int argc, char** argv)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Jeu 17 Décembre 2020 - 09:55:49
 *  \brief Programme principal
 *  \param argc : Nombre de paramètres à l'exécution
 *  \param argv : Valeur des paramètres 
 *  \return 0 si tout s'est bien passé
 */
int main(int argc, char **argv)
{
  clock_t begin;          // clock contenant le temps de départ
  clock_t end;            // clock contenant le temps d'arrivée
  double dbl_elapsedTime; // temps écoulé
  /* on initialise l'horloge de départ */
  begin = clock();
  getArgs(argc, argv);
  /* horloge post traitement */
  end = clock();
  /* calcul temps écoulé */
  dbl_elapsedTime = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Temps d'exécution : %lf secondes\n", dbl_elapsedTime);
  return (EXIT_SUCCESS);
}