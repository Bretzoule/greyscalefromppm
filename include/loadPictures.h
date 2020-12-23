#ifndef LOADPICTURES_H
#define LOADPICTURES_H
/*! 
 *  \file loadPictures.h
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Jeu 17 Décembre 2020 - 10:19:25
 *
 *  \brief ensemble des prototypes des fonctions de loadPictures.c
 *
 *
 */

// Inclusion des entetes de librairies
#include "struc.h"
#include <string.h>
#include <errno.h>

/*! 
 \def ERREUR_OUVERTURE
  Code d'erreur attestant qu'une erreur d'ouverture de fichier s'est produite
*/
#define ERREUR_OUVERTURE -1

/*! 
 \def MAX_LINE_SIZE
  Longueur maximale d'une ligne
*/
#define MAX_LINE_SIZE 70

/*! 
 \def ERREUR_FORMAT
  Code d'erreur attestant qu'une erreur de format de fichier s'est produite
*/
#define ERREUR_FORMAT -1

/*! 
 \def ERREUR_ALLOCATION
  Code d'erreur attestant qu'une erreur d'allocation s'est produite
*/
#define ERREUR_ALLOCATION -1

/*!
 *  \fn void checkComments(FILE **imageStream)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Jeu 17 Décembre 2020 - 13:14:20
 *  \brief permet d'ignorer les commentaires
 *  \param **imageStream : pointeur vers le pointeur du fichier
 */
void checkComments(FILE **imageStream);

/*!
 *  \fn int getDataAsInt(FILE **imageStream)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Jeu 17 Décembre 2020 - 11:08:28
 *  \brief permet de récupérer une valeur dans le fichier et de la retourner
 *  \param imageStream : flux de fichier
 *  \return valeur lue dans le fichier
 *  \remarks 
 */
int getDatasInt(FILE **imageStream);

/*!
 *  \fn void freeTabRGB(sPixel ***image, int int_longueur, int int_largeur)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Mer 09 Décembre 2020 - 14:42:18
 *  \brief permet de libérer le tableau de jeu
 *  \param image : tableau à libérer
 *  \param int_longueur : longueur du tableau à libérer
 *  \param int_largeur : largeur du tableau à libérer
 */
void freeTabRGB(sPixel ***image, int int_longueur, int int_largeur);

/*!
 *  \fn void afficheImageRGB(sPixel **image, int int_longueur, int int_largeur)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Dim 20 Décembre 2020 - 11:48:09
 *  \brief permet d'afficher le tableau 
 *  \param **image : image a afficher
 *  \param int_longueur : longueur de l'image
 *  \param int_largeur : largeur de l'image
 */
void afficheImageRGB(sPixel **image, int int_longueur, int int_largeur);

/*!
 *  \fn void allocMatrixRGB(sPixel ***imageMatrix, int int_longueur, int int_largeur)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Dim 20 Décembre 2020 - 14:57:32
 *  \brief permet de malloc l'image
 *  \param imageMatrix : matrice à allouer
 *  \param int_longueur : longueur de la matrice
 *  \param int_largeur : largeur de la matrice
 *  \remarks utilisé uniquement à des fins de deverminage elle ne présente aucun interet particulier
 */
void allocMatrixRGB(sPixel ***imageMatrix, int int_longueur, int int_largeur);

/*!
 *  \fn sImagePPM loadPPM(char *str_filePath)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Jeu 17 Décembre 2020 - 10:22:24
 *  \brief permet de charger une image PPM
 *  \param str_filePath : chemin du fichier
 *  \return retourne une structure contenant la taille de l'image et l'image
 */
sImagePPM loadPPM(char *str_filePath);

/*!
 *  \fn void freeTab(int ***image, int int_longueur, int int_largeur)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Mer 09 Décembre 2020 - 14:42:18
 *  \brief permet de libérer le tableau de jeu
 *  \param image : tableau à libérer
 *  \param int_longueur : longueur du tableau à libérer
 *  \param int_largeur : largeur du tableau à libérer
 */
void freeTab(int ***image, int int_longueur, int int_largeur);

/*!
 *  \fn void afficheImage(int **image, int int_longueur, int int_largeur)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Dim 20 Décembre 2020 - 11:48:09
 *  \brief permet d'afficher le tableau 
 *  \param **image : image a afficher
 *  \param int_longueur : longueur de l'image
 *  \param int_largeur : largeur de l'image
 *  \remarks utilisé uniquement à des fins de deverminage elle ne présente aucun interet particulier
 */
void afficheImage(int **image, int int_longueur, int int_largeur);

/*!
 *  \fn void allocMatrix(int ***imageMatrix, int int_longueur, int int_largeur)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Dim 20 Décembre 2020 - 14:57:32
 *  \brief permet de malloc l'image
 *  \param imageMatrix : matrice à allouer
 */
void allocMatrix(int ***imageMatrix, int int_longueur, int int_largeur);

/*!
 *  \fn sImagePGM loadPGM(char *str_filePath)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Jeu 17 Décembre 2020 - 10:22:24
 *  \brief permet de charger une image PGM
 *  \param str_filePath : chemin du fichier
 *  \return retourne une structure contenant la taille de l'image et l'image
 */
sImagePGM loadPGM(char *str_filePath);

/*!
 *  \fn sImagePBM loadPBM(char *str_filePath)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Jeu 17 Décembre 2020 - 10:22:24
 *  \brief permet de charger une image PBM
 *  \param str_filePath : chemin du fichier
 *  \return retourne une structure contenant la taille de l'image et l'image
 */
sImagePBM loadPBM(char *str_filePath);

#endif