#ifndef OPERATIONSELECTOR_H
#define OPERATIONSELECTOR_H
/*! 
 *  \file operationSelector.h
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 21 Décembre 2020 - 14:36:51
 *
 *  \brief ensemble des déclarations des fonctions de operationSelector.c
 *
 *
 */

#include "loadPictures.h"
#include "savePictures.h"

/*!
 *  \fn int convertToGrey(int int_rouge, int int_vert, int int_bleu)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 21 Décembre 2020 - 17:03:57
 *  \brief permet d'appliquer la formule du niveau de gris sur 3 composantes de pixel
 *  \param int_rouge : valeur de rouge
 *  \param int_vert : valeur de vert
 *  \param int_bleu : valeur de bleu
 *  \return valeur du pixel gris
 *  \remarks 
 */
int convertToGrey(int int_rouge, int int_vert, int int_bleu);

/*!
 *  \fn sImagePGM greyLevel(sImagePPM imageAGriser)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 21 Décembre 2020 - 16:52:46
 *  \brief permet de passer une image en niveau de gris en la transformant en image PGM
 *  \param imageAGriser : image a griser
 *  \return image PGM crée a partir de l'image PPM
 *  \remarks 
 */
sImagePGM greyLevel(sImagePPM imageAGriser);

/*!
 *  \fn sImagePBM seuillagePGM(sImagePGM myPGMImage, argsList myArgs.valSeuil)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Mar 22 Décembre 2020 - 15:15:59
 *  \brief permet de seuiller une image PGM
 *  \param myPGMImage : image à seuiller
 *  \param int_valSeuil : valeur du seuil.
 *  \return une image PBM seuillée.
 */
sImagePBM seuillagePGM(sImagePGM myPGMImage, int int_valSeuil);

/*!
 *  \fn void createAndSavePBM(argsList myArgs, sImagePBM myPBMImage)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Mer 23 Décembre 2020 - 14:55:29
 *  \brief permet de créer le fichier de sauvegarde s'il n'existe pas et de sauvegarder l'image au format PBM
 *  \param myArgs : arguments d'entrée
 *  \param myPBMImage : image PBM à sauvegarder
 */
void createAndSavePBM(argsList myArgs, sImagePBM myPBMImage);

/*!
 *  \fn void createAndSAvePGM(argsList myArgs, sImagePGM myPGMImage)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Mer 23 Décembre 2020 - 14:58:28
 *  \brief permet de créer le fichier de sauvegarde s'il n'existe pas et de sauvegarder l'image au fomat PGM
 *  \param myArgs : arguments d'entrée de l'image
 *  \param myPGMImage : image PGM à sauvegarder
 *  \remarks 
 */
void createAndSavePGM(argsList myArgs, sImagePGM myPGMImage);

/*!
 *  \fn void createAndSAvePPM(argsList myArgs, sImagePPM myPPMImage)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Mer 23 Décembre 2020 - 14:58:28
 *  \brief permet de créer le fichier de sauvegarde s'il n'existe pas et de sauvegarder l'image au fomat PPM
 *  \param myArgs : arguments d'entrée de l'image
 *  \param myPGMImage : image PPM à sauvegarder
 *  \remarks 
 */
void createAndSavePPM(argsList myArgs, sImagePPM myPPMImage);

/*!
*  \fn void operationsOnPPM(argsList myArgs)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 21 Décembre 2020 - 16:16:35
 *  \brief permet d'effectuer des opérations sur une image en .ppm
 *  \param myArgs : arguments d'entrée
 */
void operationsOnPPM(argsList myArgs);

/*!
*  \fn void operationsOnPBM(argsList myArgs)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 21 Décembre 2020 - 16:16:35
 *  \brief permet d'effectuer des opérations sur une image en .pbm
 *  \param myArgs : arguments d'entrée
 */
void operationsOnPBM(argsList myArgs);

/*!
*  \fn void operationsOnPGM(argsList myArgs)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 21 Décembre 2020 - 16:16:35
 *  \brief permet d'effectuer des opérations sur une image en .pgm
 *  \param myArgs : arguments d'entrée
 */
void operationsOnPGM(argsList myArgs);

/*!
 *  \fn void callWArgs(argsList myArgs)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 21 Décembre 2020 - 15:58:46
 *  \brief permet de lancer les fonctions en fonction du type de fichier
 *  \param myArgs : liste des arguments
 */
void callWArgs(argsList myArgs);

/*!
 *  \fn void getArgs(int int_nbArgs, char** tstr_arguments)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 21 Décembre 2020 - 15:05:44
 *  \brief permet de récupérer les arguments et de rediriger en fonction de leur nombre
 *  \param int_nbArgs : nombre d'args
 *  \param tstr_arguments : tableau d'arguments
 */
void getArgs(int int_nbArgs, char **tstr_arguments);

/*!
 *  \fn int getExtension(char *str_image, char* str_extensionType)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 21 Décembre 2020 - 21:06:19
 *  \brief permet de récupérer l'extension d'une image (aka ses 4 derniers caractères)
 *  \param str_image : image en entrée
 *  \param str_extensionType : extension
 *  \return retourne le resultat de la comparaison entre l'extension et l'extension du fichier.
 */
int getExtension(char *str_image, char* str_extensionType);

/*!
 *  \fn void help()
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 21 Décembre 2020 - 21:41:23
 *  \brief permet d'afficher l'aide
 */
void help();

#endif