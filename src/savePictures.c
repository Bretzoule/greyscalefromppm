/*! 
 *  \file savePictures.c
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Mar 22 Décembre 2020 - 11:58:53
 *
 *  \brief ensmeble des fonctions permettant de sauvegarder une image
 *
 *
 */

#include "savePictures.h"

void savePPM(sImagePPM myPicToSave, char *str_outputFile)
{
    FILE *fileStream;
    char str_typeFichier[3] = "P3\n";
    /* on ajoute l'extension au fichier */
    if (getExtension(str_outputFile, ".ppm") != 0)
    {
        printf("Ajout de l'extension .ppm au fichier de sortie.\n");
        strcat(str_outputFile, ".ppm");
    }
    fileStream = fopen(str_outputFile, "w+");
    if (fileStream == NULL)
    {
        fprintf(stderr,"Une erreur lors de l'ouverture du fichier s'est produite : %s \n", strerror(errno));
        exit(ERREUR_OUVERTURE);
    }
    printf("Fichier ouvert, sauvegarde en cours... \n");
    /* écriture type de fichier */
    fprintf(fileStream, "%s", str_typeFichier);
    /* écriture longueur, largeur et valeur maximale */
    fprintf(fileStream, "%d %d %d\n", myPicToSave.largeur, myPicToSave.hauteur, myPicToSave.pixelIntensity);
    for (int i = 0; i < myPicToSave.hauteur; i++)
    {
        for (int j = 0; j < myPicToSave.largeur; j++)
        {
            fprintf(fileStream, "%d %d %d\n", myPicToSave.imageMatrix[j][i].R, myPicToSave.imageMatrix[j][i].G, myPicToSave.imageMatrix[j][i].B);
        }
    }
    printf("Sauvegarde terminé ! \n");
    fclose(fileStream);
}

void savePGM(sImagePGM myPicToSave, char *str_outputFile)
{
    FILE *fileStream;
    int errno;
    char str_typeFichier[3] = "P2\n";
    /* on ajoute l'extension au fichier */
    if (getExtension(str_outputFile, ".pgm") != 0)
    {
        printf("Ajout de l'extension .pgm au fichier de sortie.\n");
        strcat(str_outputFile, ".pgm");
    }
    fileStream = fopen(str_outputFile, "w+");
    if (fileStream == NULL)
    {
        fprintf(stderr,"Une erreur lors de l'ouverture du fichier s'est produite : %s \n", strerror(errno));
        exit(ERREUR_OUVERTURE);
    }
    printf("Fichier ouvert, sauvegarde en cours... \n");
    /* écriture type de fichier */
    fprintf(fileStream, "%s", str_typeFichier);
    /* écriture longueur, largeur et valeur maximale */
    fprintf(fileStream, "%d %d %d\n", myPicToSave.largeur, myPicToSave.hauteur, myPicToSave.pixelIntensity);
    for (int i = 0; i < myPicToSave.hauteur; i++)
    {
        for (int j = 0; j < myPicToSave.largeur; j++)
        {
            fprintf(fileStream, "%d\n", myPicToSave.imageMatrix[j][i]);
        }
    }
    printf("Sauvegarde terminé ! \n");
    fclose(fileStream);
}

void savePBM(sImagePBM myPicToSave, char *str_outputFile)
{
    FILE *fileStream;
    int errno;
    char str_typeFichier[3] = "P1\n";
    /* on ajoute l'extension au fichier */
    if (getExtension(str_outputFile, ".pbm") != 0)
    {
        printf("Ajout de l'extension .pbm au fichier de sortie.\n");
        strcat(str_outputFile, ".pbm");
    }
    fileStream = fopen(str_outputFile, "w+");
    if (fileStream == NULL)
    {
        fprintf(stderr,"Une erreur lors de l'ouverture du fichier s'est produite : %s \n", strerror(errno));
        exit(ERREUR_OUVERTURE);
    }
    printf("Fichier ouvert, sauvegarde en cours... \n");
    /* écriture type de fichier */
    fprintf(fileStream, "%s", str_typeFichier);
    /* écriture longueur, largeur */
    fprintf(fileStream, "%d %d\n", myPicToSave.largeur, myPicToSave.hauteur);
    for (int i = 0; i < myPicToSave.hauteur; i++)
    {
        for (int j = 0; j < myPicToSave.largeur; j++)
        {
            fprintf(fileStream, "%d\n", myPicToSave.imageMatrix[j][i]);
        }
    }
    printf("Sauvegarde terminé !\n");
    fclose(fileStream);
}
