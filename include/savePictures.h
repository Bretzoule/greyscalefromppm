#ifndef SAVEPICTURES_H
#define SAVEPICTURES_H
/*! 
 *  \file savePictures.h
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Mar 22 Décembre 2020 - 12:03:16
 *
 *  \brief contient l'ensemble des prototypes associés aux fonctions de savePicture.c
 *
 *
 */

#include "struc.h"
#include "operationSelector.h"

// Inclusion des entetes de librairies
/*!
 *  \fn void savePPM(sImagePPM myPicToSave, char* str_outputFile)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Mar 22 Décembre 2020 - 12:04:35
 *  \brief permet de sauvegarder une image au format .ppm
 *  \param myPicToSAve : image a sauvegarder
 *  \param str_outputFile : nom du fichier de sortie
 *  \remarks 
 */
void savePPM(sImagePPM myPicToSave, char *str_outputFile);

/*!
 *  \fn void savePGM(sImagePGM myPicToSave, char* str_outputFile)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Mar 22 Décembre 2020 - 12:04:35
 *  \brief permet de sauvegarder une image au format .pgm
 *  \param myPicToSAve : image a sauvegarder
 *  \param str_outputFile : nom du fichier de sortie
 *  \remarks 
 */
void savePGM(sImagePGM myPicToSave, char *str_outputFile);

/*!
 *  \fn void savePBM(sImagePBM myPicToSave, char* str_outputFile)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Mar 22 Décembre 2020 - 12:04:35
 *  \brief permet de sauvegarder une image au format .pbm
 *  \param myPicToSAve : image a sauvegarder
 *  \param str_outputFile : nom du fichier de sortie
 *  \remarks 
 */
void savePBM(sImagePBM myPicToSave, char *str_outputFile);

#endif