/*
 * Robotic Research Group (RRG)
 * State University of Piaui (UESPI), Brazil - ­ - Teresina
 *
 * FuzzyComposition.h
 *
 *      Author: Msc. Marvin Lemos <marvinlemos@gmail.com>
 *              AJ Alves <aj.alves@zerokol.com>
 *          Co authors: Douglas S. Kridi <douglaskridi@gmail.com>
 *                      Kannya Leal <kannyal@hotmail.com>
 */
#ifndef FUZZYCOMPOSITION_H
#define FUZZYCOMPOSITION_H

// IMPORTANDO AS BIBLIOTECAS
#include <stdlib.h>

// CONSTANTES
#define EPS 1.0E-3

// Estrutura de uma lista para guardar os pontos
struct pointsArray{
    pointsArray* previous;
    float point;
    float pertinence;
    pointsArray* next;
};

class FuzzyComposition{
    public:
        // CONSTRUTORES
        FuzzyComposition();
        // DESTRUTOR
        ~FuzzyComposition();

        bool addPoint(float point, float pertinence);
        bool checkPoint(float point, float pertinence);
        bool build();
        float avaliate();
        bool empty();

    private:

        pointsArray* pointsCursor;
        pointsArray* points;


        void cleanPoints(pointsArray* aux);
        bool rebuild(pointsArray* aSegmentBegin, pointsArray* aSegmentEnd, pointsArray* bSegmentBegin, pointsArray* bSegmentEnd);
        bool rmvPoint(pointsArray* point);
};
#endif
