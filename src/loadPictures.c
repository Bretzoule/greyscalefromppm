/*! 
 *  \file loadPictures.c
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Jeu 17 Décembre 2020 - 10:19:14
 *
 *  \brief ensemble des fonctions permettant de charger les images
 *
 *
 */

#include "loadPictures.h"

int getDatasInt(FILE **imageStream)
{
    int int_tmp = 0;
    int int_retour = 0;
    /* récupère un caractère dans le flux de fichier */
    int_retour = fscanf(*imageStream, "%d", &int_tmp);
    /* si on n'arrive pas à lire dans le fichier c'est qu'une erreur s'est produite */
    if (int_retour == 0)
    {
        fprintf(stderr, "Erreur de lecture dans le fichier, arrêt du programme.\n");
        exit(ERREUR_SAISIE);
    }
    /* on vérifie si la ligne suivante n'est pas un commentaire pour gagner du temps sur une prochaine lecture */
    checkComments(imageStream);
    return (int_tmp);
}

void checkComments(FILE **imageStream)
{
    char c = ' ';
    /* on reforce l'emplacment de la tête de lecture à sa position */
    fseek(*imageStream, 0, SEEK_CUR);
    /* on teste si l'on ne se trouve pas à la fin d'une ligne en lecture ou si on est à la fin du fichier */
    if ((c = fgetc(*imageStream)) != '\n' || c == EOF)
    {
        /* on recule si le dernier caractère n'est pas un marqueur de fin afin de pouvoir relire ce caractère ensuite */
        fseek(*imageStream, -1L, SEEK_CUR);
    }
    /* on test s'il s'agit d'un commentaire (commence par un #) */
    while ((c = fgetc(*imageStream)) == '#')
    {
        /* si c'est un commentaire alors tant que la ligne n'est pas terminé ou que le fichier n'est pas fini on continue d'avancer la tête de lecture */
        while (((c = fgetc(*imageStream)) != '\n') && (c != EOF))
        {
        }
    }
    /* on recule la tete de lecture de 1 pour remettre en place le dernier caractère lu si ce n'était pas un "#" */
    fseek(*imageStream, -1L, SEEK_CUR);
}

/* RGB PICTURES */

void freeTabRGB(sPixel ***image, int int_longueur, int int_largeur)
{
    for (int i = 0; i < int_largeur; i++)
    {
        free((*image)[i]);
    }
    free(*image);
}

void afficheImageRGB(sPixel **image, int int_longueur, int int_largeur)
{
    for (int j = 0; j < int_longueur; j++)
    {
        for (int i = 0; i < int_largeur; i++)
        {
            printf("[ %d %d %d ]", image[i][j].R, image[i][j].G, image[i][j].B);
        }
        printf("\n");
    }
}

void allocMatrixRGB(sPixel ***imageMatrix, int int_longueur, int int_largeur)
{

    (*imageMatrix) = malloc(int_largeur * sizeof(sPixel *));
    if ((*imageMatrix) == NULL)
    {
        fprintf(stderr, "Une erreur d'allocation s'est produite ! \n");
        exit(ERREUR_ALLOCATION);
    }
    for (int k = 0; k < int_largeur; k++)
    {
        (*imageMatrix)[k] = malloc(int_longueur * sizeof(sPixel));
        if ((*imageMatrix)[k] == NULL)
        {
            fprintf(stderr, "Une erreur d'allocation s'est produite ! \n");
            exit(ERREUR_ALLOCATION);
        }
    }
}

/* GREYSCALE PICTURES */

void freeTab(int ***image, int int_longueur, int int_largeur)
{
    for (int i = 0; i < int_largeur; i++)
    {
        free((*image)[i]);
    }
    free(*image);
}

void afficheImage(int **image, int int_longueur, int int_largeur)
{
    for (int j = 0; j < int_longueur; j++)
    {
        for (int i = 0; i < int_largeur; i++)
        {
            printf("[ %d ]", image[i][j]);
        }
        printf("\n");
    }
}

void allocMatrix(int ***imageMatrix, int int_longueur, int int_largeur)
{

    (*imageMatrix) = malloc(int_largeur * sizeof(int *));
    if ((*imageMatrix) == NULL)
    {
        fprintf(stderr, "Une erreur d'allocation s'est produite ! \n");
        exit(ERREUR_ALLOCATION);
    }
    for (int k = 0; k < int_largeur; k++)
    {
        (*imageMatrix)[k] = malloc(int_longueur * sizeof(int));
        if ((*imageMatrix)[k] == NULL)
        {
            fprintf(stderr, "Une erreur d'allocation s'est produite ! \n");
            exit(ERREUR_ALLOCATION);
        }
    }
}

sImagePPM loadPPM(char *str_filePath)
{
    FILE *imageStream = NULL; // flux fichier
    int errno;
    int int_largeur = 0;          // largeur de l'image
    int int_longueur = 0;         // longueur de l'image
    char c;                       // caractère tampon
    char str_line[MAX_LINE_SIZE]; // ligne de fichier
    sImagePPM imageACharger;      // image
    /* ouverture fichier */
    imageStream = fopen(str_filePath, "r");
    if (imageStream == NULL)
    {
        fprintf(stderr, "Erreur d'ouverture du fichier. Erreur : %s \n", strerror(errno));
        exit(ERREUR_OUVERTURE);
    }
    printf("Fichier ouvert, chargement en cours... \n");
    /* en prenant les 3 premiers caractères on vérifie le type de fichier */
    fgets(str_line, 3, imageStream);
    if (str_line[0] != 'P' || str_line[1] != '3')
    {
        fprintf(stderr, "Erreur de format de fichier, on quitte le programme. \n");
        fclose(imageStream);
        exit(ERREUR_FORMAT);
    }
    else
    {
        /* récupération longueur et largeur ainsi que intensité maximale */
        checkComments(&imageStream);
        imageACharger.largeur = getDatasInt(&imageStream);
        imageACharger.hauteur = getDatasInt(&imageStream);
        imageACharger.pixelIntensity = getDatasInt(&imageStream);
        /* allocation matrice */
        allocMatrixRGB(&imageACharger.imageMatrix, imageACharger.hauteur, imageACharger.largeur);
        /* tant que l'on est pas à la fin du fichier et que notre matrice n'est pas complète */
        while (((c = fgetc(imageStream)) != EOF) && (int_longueur < imageACharger.hauteur))
        {
            /* on recule la tete de lecture de 1 pour ne pas absorber le caractère lu par le fgetc lors de la comparaison de la boucle */
            fseek(imageStream, -1L, SEEK_CUR);
            /* Lecture RGB */
            imageACharger.imageMatrix[int_largeur][int_longueur].R = getDatasInt(&imageStream);
            imageACharger.imageMatrix[int_largeur][int_longueur].G = getDatasInt(&imageStream);
            imageACharger.imageMatrix[int_largeur][int_longueur].B = getDatasInt(&imageStream);
            /* une fois le pixel lu, on passe au pixel suivant */
            int_largeur++;
            /* puis a la ligne de pixel suivante une fois que la ligne actuelle est pleine */
            if (int_largeur >= imageACharger.largeur)
            {
                int_largeur = 0;
                int_longueur++;
            }
        }
    }
    /* fermeture flux fichier */
    fclose(imageStream);
    printf("Chargement terminé ! \n");
    //afficheImageRGB(imageACharger.imageMatrix, imageACharger.hauteur, imageACharger.largeur);
    return (imageACharger);
}

sImagePBM loadPBM(char *str_filePath)
{
    FILE *imageStream = NULL; // flux de fichier
    int errno;
    int int_largeur = 0;          // largeur de l'image
    int int_longueur = 0;         // longueur de l'image
    char c;                       // caractère tampon
    char str_line[MAX_LINE_SIZE]; // ligne de fichier
    sImagePBM imageACharger;      // image
    /* ouverture du fichier */
    imageStream = fopen(str_filePath, "r");
    if (imageStream == NULL)
    {
        fprintf(stderr, "Erreur d'ouverture du fichier. Erreur : %s \n", strerror(errno));
        exit(ERREUR_OUVERTURE);
    }
    printf("Fichier ouvert, chargement en cours... \n");
    /* en prenant les 3 premiers caractères on vérifie le type de fichier */
    fgets(str_line, 3, imageStream);
    if (str_line[0] != 'P' || str_line[1] != '1')
    {
        fprintf(stderr, "Erreur de format de fichier, on quitte le programme. \n");
        fclose(imageStream);
        exit(ERREUR_FORMAT);
    }
    else
    {
        /* récupération longueur et largeur */
        checkComments(&imageStream);
        imageACharger.largeur = getDatasInt(&imageStream);
        imageACharger.hauteur = getDatasInt(&imageStream);
        /* allocation matrice */
        allocMatrix(&imageACharger.imageMatrix, imageACharger.hauteur, imageACharger.largeur);
        /* tant que l'on est pas à la fin du fichier et que la matrice n'est pas pleine */
        while (((c = fgetc(imageStream)) != EOF) && (int_longueur < imageACharger.hauteur))
        {
            /* on recule le curseur d'une position pour pouvoir lire le caractère absorbé par le fgetc */
            fseek(imageStream, -1L, SEEK_CUR);
            imageACharger.imageMatrix[int_largeur][int_longueur] = getDatasInt(&imageStream);
            /* une fois notre pixel lu, on avance dans la ligne */
            int_largeur++;
            /* une fois la ligne terminée on passe à la suivante */
            if (int_largeur >= imageACharger.largeur)
            {
                int_largeur = 0;
                int_longueur++;
            }
        }
    }
    fclose(imageStream);
    //afficheImage(imageACharger.imageMatrix, imageACharger.hauteur, imageACharger.largeur);
    return (imageACharger);
}

sImagePGM loadPGM(char *str_filePath)
{
    FILE *imageStream = NULL; // flux de fichier
    int errno;
    int int_largeur = 0;          // largeur de l'image
    int int_longueur = 0;         // longueur de l'image
    char c;                       // caractère tampon
    char str_line[MAX_LINE_SIZE]; // ligne de fichier
    sImagePGM imageACharger;      // image
    /* ouverture fichier */
    imageStream = fopen(str_filePath, "r");
    if (imageStream == NULL)
    {
        fprintf(stderr, "Erreur d'ouverture du fichier. Erreur : %s \n", strerror(errno));
        exit(ERREUR_OUVERTURE);
    }
    printf("Fichier ouvert, chargement en cours... \n");
    /* en prenant les 3 premiers caractères on vérifie le type de fichier */
    fgets(str_line, 3, imageStream);
    if (str_line[0] != 'P' || str_line[1] != '2')
    {
        fprintf(stderr, "Erreur de format de fichier, on quitte le programme. \n");
        fclose(imageStream);
        exit(ERREUR_FORMAT);
    }
    else
    {
        /* récupération longueur, largeur et intensité maximale d'un pixel */
        checkComments(&imageStream);
        imageACharger.largeur = getDatasInt(&imageStream);
        imageACharger.hauteur = getDatasInt(&imageStream);
        imageACharger.pixelIntensity = getDatasInt(&imageStream);
        /* allocation matrice */
        allocMatrix(&imageACharger.imageMatrix, imageACharger.hauteur, imageACharger.largeur);
        /* tant que l'on n'est pas à la fin du fichier ou que notre matrice n'est pas remplie */
        while (((c = fgetc(imageStream)) != EOF) && (int_longueur < imageACharger.hauteur))
        {
            /* on recule la tete de lecture d'un caractère pour remettre en place le caractère absorbé par le fgetc */
            fseek(imageStream, -1L, SEEK_CUR);
            imageACharger.imageMatrix[int_largeur][int_longueur] = getDatasInt(&imageStream);
            /* une fois notre pixel lu on avance dans la ligne */
            int_largeur++;
            /* une fois notre ligne de pixel terminée, on passe à la suivante */
            if (int_largeur >= imageACharger.largeur)
            {
                int_largeur = 0;
                int_longueur++;
            }
        }
    }
    fclose(imageStream);
    //afficheImage(imageACharger.imageMatrix, imageACharger.hauteur, imageACharger.largeur);
    return (imageACharger);
}
