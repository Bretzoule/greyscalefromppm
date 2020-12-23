#ifndef STRUC_H
#define STRUC_H
/*! 
 *  \file struc.h
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Jeu 17 Décembre 2020 - 09:54:53
 *
 *  \brief ensemble des structures du programme
 *
 *
 */

// Inclusion des entetes de librairies
#include <stdlib.h>
#include <stdio.h>
/*! 
 \def EXIT_SUCCESS
  Code confirmant la bonne exécution du programme
*/
#define EXIT_SUCCESS 0
/*! 
 \def ERREUR_SAISIE
  Code d'erreur attestant qu'une erreur de saisie s'est produite
*/
#define ERREUR_SAISIE -1

/*! 
 \def MAX_PATH_SIZE
  Taille maximale d'un chemin vers une image
*/
#define MAX_PATH_SIZE 50

/*!
 *  \struct sPixel
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Jeu 17 Décembre 2020 - 10:02:52
 *  \brief stocke un pixel
 *  \param R : intensité pixel rouge (0-max)
 *  \param G : intensité pixel vert (0-max)
 *  \param B : intensité pixel bleu (0-max)
 */
typedef struct sPixel
{
    int R;
    int G;
    int B;
} sPixel;

/*!
 *  \struct sImagePPM
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Jeu 17 Décembre 2020 - 10:10:08
 *  \brief permet de stocker les données associées a une image PPM
 *  \param largeur : largeur de l'image
 *  \param hauteur : hauteur de l'image
 *  \param pixelIntensity : intensité maximale d'un pixel
 *  \param imageMatrix : matrice de l'image
 */
typedef struct sImagePPM
{
    int largeur;
    int hauteur;
    int pixelIntensity;
    sPixel **imageMatrix;
} sImagePPM;

/*!
 *  \struct sImagePGM
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Jeu 17 Décembre 2020 - 10:10:08
 *  \brief permet de stocker les données associées a une image PGM
 *  \param largeur : largeur de l'image
 *  \param hauteur : hauteur de l'image
 *  \param pixelIntensity : intensité maximale d'un pixel
 *  \param imageMatrix : matrice de l'image
 */
typedef struct sImagePGM
{
    int largeur;
    int hauteur;
    int pixelIntensity;
    int **imageMatrix;
} sImagePGM;

/*!
 *  \struct sImagePBM
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Jeu 17 Décembre 2020 - 10:10:08
 *  \brief permet de stocker les données associées a une image PBM
 *  \param largeur : largeur de l'image
 *  \param hauteur : hauteur de l'image
 *  \param imageMatrix : matrice de l'image
 */
typedef struct sImagePBM
{
    int largeur;
    int hauteur;
    int **imageMatrix;
} sImagePBM;

/*!
 *  \struct argsList
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 21 Décembre 2020 - 14:44:16
 *  \brief stocke les arguments et les valeurs associées
 *  \param imageIn[MAX_PATH_SIZE] : chemin de l'image d'entrée, taille max du chemin : 50 chars
 *  \param imageOut[MAX_PATH_SIZE] : chemin de l'image de sortie, taille max du chemin : 50 chars
 *  \param nvGris : passer l'image en niveau de gris ou non
 *  \param valSeuil : valeur du seuil utilisé, -1 si on ne souhaite pas seuiller l'image
 *  \remarks 
 */

typedef struct argsList {
     char imageIn[MAX_PATH_SIZE];
     char imageOut[MAX_PATH_SIZE];
     int nvGris;
     int valSeuil;
}argsList;

#endif