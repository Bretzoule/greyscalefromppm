/*! 
 *  \file operationSelector.c
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 21 Décembre 2020 - 14:34:23
 *
 *  \brief ensemble des fonctions associés à la selection de l'opération sur l'image
 *
 *
 */

#include "operationSelector.h"

int convertToGrey(int int_rouge, int int_vert, int int_bleu)
{
    return ((0.299 * int_rouge) + (0.587 * int_vert) + (0.114 * int_bleu));
}

sImagePGM greyLevel(sImagePPM imageAGriser)
{
    sImagePGM myGreyPic; // image au format PGM
    /* on copie les données de taille et d'intensité à l'image en niveau de gris */
    myGreyPic.hauteur = imageAGriser.hauteur;
    myGreyPic.largeur = imageAGriser.largeur;
    myGreyPic.pixelIntensity = convertToGrey(imageAGriser.pixelIntensity, imageAGriser.pixelIntensity, imageAGriser.pixelIntensity);
    /* on alloue notre image en niveau de gris */
    allocMatrix(&myGreyPic.imageMatrix, myGreyPic.hauteur, myGreyPic.largeur);
    for (int i = 0; i < myGreyPic.largeur; i++)
    {
        for (int j = 0; j < myGreyPic.hauteur; j++)
        {
            /* passage d'un pixel en gris */
            myGreyPic.imageMatrix[i][j] = convertToGrey(imageAGriser.imageMatrix[i][j].R, imageAGriser.imageMatrix[i][j].G, imageAGriser.imageMatrix[i][j].B);
        }
    }
    return (myGreyPic);
}

sImagePBM seuillagePGM(sImagePGM myPGMImage, int int_valSeuil)
{
    sImagePBM imageSeuillee; // image au format PBM
    /* on copie les données de taille à l'image en PBM */
    imageSeuillee.hauteur = myPGMImage.hauteur;
    imageSeuillee.largeur = myPGMImage.largeur;
    allocMatrix(&imageSeuillee.imageMatrix, myPGMImage.hauteur, myPGMImage.largeur);
    for (int i = 0; i < imageSeuillee.largeur; i++)
    {
        for (int j = 0; j < imageSeuillee.hauteur; j++)
        {
            /* seuillage d'un pixel */
            imageSeuillee.imageMatrix[i][j] = (myPGMImage.imageMatrix[i][j] >= int_valSeuil) ? 1 : 0;
        }
    }
    return (imageSeuillee);
}

void operationsOnPBM(argsList myArgs)
{
    sImagePBM myPBMImage; // image PBM
    myPBMImage.imageMatrix = NULL;
    /* on charge l'image PBM */
    myPBMImage = loadPBM(myArgs.imageIn);
    createAndSavePBM(myArgs, myPBMImage);
    if (myPBMImage.imageMatrix != NULL)
    {
        freeTab(&myPBMImage.imageMatrix, myPBMImage.hauteur, myPBMImage.largeur);
    }
}

void createAndSavePBM(argsList myArgs, sImagePBM myPBMImage)
{
    /* si aucune image de sortie n'est mentionnée, on en créé une par défaut */
    if (myArgs.imageOut[0] == '\0')
    {
        printf("Création d'une image de sortie par défaut : output.pbm \n");
        strcpy(myArgs.imageOut, "output.pbm");
    }
    printf("Sortie sur : %s \n", myArgs.imageOut);
    /* sauvegarde de l'image */
    savePBM(myPBMImage, myArgs.imageOut);
}

void createAndSavePGM(argsList myArgs, sImagePGM myPGMImage)
{
    /* si aucune image de sortie n'est mentionnée, on en créé une par défaut */
    if (myArgs.imageOut[0] == '\0')
    {
        printf("Création d'une image de sortie par défaut : output.pgm \n");
        strcpy(myArgs.imageOut, "output.pgm");
    }
    printf("Sortie sur : %s \n", myArgs.imageOut);
    /* sauvegarde de l'image */
    savePGM(myPGMImage, myArgs.imageOut);
}

void createAndSavePPM(argsList myArgs, sImagePPM myPPMImage)
{
    /* si aucune image de sortie n'est mentionnée, on en créé une par défaut */
    if (myArgs.imageOut[0] == '\0')
    {
        printf("Création d'une image de sortie par défaut : output.ppm \n");
        strcpy(myArgs.imageOut, "output.ppm");
    }
    printf("Sortie sur : %s \n", myArgs.imageOut);
    /* sauvegarde de l'image */
    savePPM(myPPMImage, myArgs.imageOut);
}

void operationsOnPGM(argsList myArgs)
{
    sImagePGM myPGMImage; // image PGM
    sImagePBM myPBMImage; // image PBM
    myPGMImage.imageMatrix = NULL;
    myPBMImage.imageMatrix = NULL;
    /* chargement image PGM */
    myPGMImage = loadPGM(myArgs.imageIn);
    /* Test seuillage */
    if (myArgs.valSeuil > 0 && myArgs.valSeuil < myPGMImage.pixelIntensity)
    {
        myPBMImage = seuillagePGM(myPGMImage, myArgs.valSeuil);
        createAndSavePBM(myArgs, myPBMImage);
    }
    else
    {
        createAndSavePGM(myArgs, myPGMImage);
    }
    if (myPBMImage.imageMatrix != NULL)
    {
        freeTab(&myPBMImage.imageMatrix, myPBMImage.hauteur, myPBMImage.largeur);
    }
    if (myPGMImage.imageMatrix != NULL)
    {
        freeTab(&myPGMImage.imageMatrix, myPGMImage.hauteur, myPGMImage.largeur);
    }
}

void operationsOnPPM(argsList myArgs)
{
    sImagePPM myPPMImage; // image PPM
    sImagePGM myPGMImage; // image PGM
    sImagePBM myPBMImage; // image PBM
    myPGMImage.imageMatrix = NULL;
    myPPMImage.imageMatrix = NULL;
    myPBMImage.imageMatrix = NULL;
    /* chargement image PPM */
    myPPMImage = loadPPM(myArgs.imageIn);
    if (myArgs.valSeuil > 0 && myArgs.valSeuil < myPPMImage.pixelIntensity)
    {
        myPGMImage = greyLevel(myPPMImage);
        myPBMImage = seuillagePGM(myPGMImage, myArgs.valSeuil);
        createAndSavePBM(myArgs, myPBMImage);
    }
    else if (myArgs.nvGris == 1)
    {
        myPGMImage = greyLevel(myPPMImage);
        createAndSavePGM(myArgs, myPGMImage);
    }
    else
    {
       createAndSavePPM(myArgs, myPPMImage);
    }
    if (myPPMImage.imageMatrix != NULL)
    {
        freeTabRGB(&myPPMImage.imageMatrix, myPPMImage.hauteur, myPPMImage.largeur);
    }
    if (myPGMImage.imageMatrix != NULL)
    {
        freeTab(&myPGMImage.imageMatrix, myPGMImage.hauteur, myPGMImage.largeur);
    }
    if (myPBMImage.imageMatrix != NULL)
    {
        freeTab(&myPBMImage.imageMatrix, myPBMImage.hauteur, myPBMImage.largeur);
    }
}

void callWArgs(argsList myArgs)
{
    /* si il n'y pas d'image en entrée */
    if (myArgs.imageIn[0] == '\0')
    {
        printf("Aucune image en entrée... \n");
    }
    else
    /* si il y a une image */
    {
        if (getExtension(myArgs.imageIn, ".ppm") == 0)
        {
            operationsOnPPM(myArgs);
        }
        else if (getExtension(myArgs.imageIn, ".pbm") == 0)
        {
            operationsOnPBM(myArgs);
        }
        else if (getExtension(myArgs.imageIn, ".pgm") == 0)
        {
            operationsOnPGM(myArgs);
        }
        else
        {
            printf("Format de fichier non suppporté, merci d'utiliser une image en '.ppm', '.pbm' ou '.pgm'.\n");
        }
    }
}

int getExtension(char *str_image, char *str_extensionType)
{
    char str_extension[4]; // stockage extension (".pxm")
    for (int i = 0; i < 4; i++)
    {
        str_extension[i] = str_image[strlen(str_image) - 4 + i];
    }
    return (strcmp(str_extension, str_extensionType));
}

void help()
{
    printf("************** TRAITEMENT D'IMAGE **************\n");
    printf("\n");
    printf("-in nomImage1 : précise l’image en entrée \n");
    printf(" -out nomImage2 : précise l’image en sortie \n");
    printf("-gris : transformation en niveau de gris \n");
    printf("-seuil valeur : seuillage \n ");
    printf("\n");
    printf("Si vous utilisez le seuillage, le passage en niveau de gris est automatique pour toute image en couleur \n");
}

void getArgs(int int_nbArgs, char **tstr_arguments)
{
    int errno; 
    argsList myArgs; // liste arguments
    char *ch_endPtr; // pointeur de fin de chaine
    long lg_tmp; // stockage temporaire de la valeur du seuil
    switch (int_nbArgs) 
    { // si l'utilisateur ne rentre qu'1 ou 2 arguments
    case 1:
    case 2:
        printf("Votre nombre d'arguments est insufisant, voici comment utiliser le programme : \n");
        help();
        break;
    default:
        /* on initialise les valeurs par défaut */
        strcpy(myArgs.imageIn, "\0");
        strcpy(myArgs.imageOut, "\0");
        myArgs.nvGris = 0;
        myArgs.valSeuil = -1;
        /* on traverse la liste complète d'arguments */ 
        for (int i = 0; i < int_nbArgs; i++)
        {
            if (strcmp(tstr_arguments[i], "-in") == 0 && i < (int_nbArgs - 1))
            {
                printf("Chemin de l'image en entrée : %s \n", tstr_arguments[i + 1]);
                strcpy(myArgs.imageIn, tstr_arguments[i + 1]);
            }
            else
            {
                if (strcmp(tstr_arguments[i], "-out") == 0 && i < (int_nbArgs - 1))
                {
                    printf("Chemin de l'image en sortie : %s \n", tstr_arguments[i + 1]);
                    strcpy(myArgs.imageOut, tstr_arguments[i + 1]);
                }
            }
            if (strcmp(tstr_arguments[i], "-gris") == 0)
            {
                myArgs.nvGris = 1;
            }
            else if (strcmp(tstr_arguments[i], "-seuil") == 0 && i < (int_nbArgs - 1))
            {
                /* vérification valeur du seuil */
                lg_tmp = strtol(tstr_arguments[i + 1], &ch_endPtr, 10);
                if (ch_endPtr == tstr_arguments[i + 1])
                {
                    printf("Une erreur s'est produite lors de la conversion : donnée en entrée invalide. \n");
                }
                else
                {
                    printf("Valeur du seuil : %d \n", (int)lg_tmp);
                    myArgs.valSeuil = (int)lg_tmp;
                }
            }
        }
        callWArgs(myArgs);
        break;
    }
}