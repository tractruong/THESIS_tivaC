/*
 * Robotic Research Group (RRG)
 * State University of Piaui (UESPI), Brazil - ­ - Teresina
 *
 * FuzzyOutput.h
 *
 *      Author: Msc. Marvin Lemos <marvinlemos@gmail.com>
 *              AJ Alves <aj.alves@zerokol.com>
 *          Co authors: Douglas S. Kridi <douglaskridi@gmail.com>
 *                      Kannya Leal <kannyal@hotmail.com>
 */


#ifndef FUZZYOUTPUT_H
#define FUZZYOUTPUT_H

// IMPORTANDO AS BIBLIOTECAS
#include "FuzzyComposition.h"
#include "FuzzyIO.h"


#ifdef __cplusplus
extern "C"
{
#endif

// Estrutura de uma linha
struct line{
    float xBegin;
    float yBegin;
    float xEnd;
    float yEnd;
};

class FuzzyOutput : public FuzzyIO {
    public:
        // CONSTRUTORES
        FuzzyOutput();
        FuzzyOutput(int index);
        // DESTRUTOR
        ~FuzzyOutput();
        //
        bool truncate();
        float getCrispOutput();
        bool order();

    private:
        //
        FuzzyComposition fuzzyComposition;
        //
        bool swap(fuzzySetArray* fuzzySetA, fuzzySetArray* fuzzySetB);
        bool rebuild(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float* point, float* pertinence);
};

#ifdef __cplusplus
}
#endif
#endif
