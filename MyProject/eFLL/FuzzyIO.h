/*
 * Robotic Research Group (RRG)
 * State University of Piaui (UESPI), Brazil - ­ - Teresina
 *
 * FuzzyIO.h
 *
 *      Author: Msc. Marvin Lemos <marvinlemos@gmail.com>
 *              AJ Alves <aj.alves@zerokol.com>
 *          Co authors: Douglas S. Kridi <douglaskridi@gmail.com>
 *                      Kannya Leal <kannyal@hotmail.com>
 */
#ifndef FUZZYIO_H
#define FUZZYIO_H

// IMPORTANDO AS BIBLIOTECAS
#include <stdlib.h>
#include "FuzzySet.h"


#ifdef __cplusplus
extern "C"
{
#endif
// Estrutura de uma lista de FuzzySet
struct fuzzySetArray{
    FuzzySet* fuzzySet;
    fuzzySetArray* next;
};

class FuzzyIO {
    public:
        // CONSTRUTORES
        FuzzyIO();
        FuzzyIO(int index);
        // DESTRUTOR
        ~FuzzyIO();

        int getIndex();
        void setCrispInput(float crispInput);
        float getCrispInput();
        bool addFuzzySet(FuzzySet* fuzzySet);
        void resetFuzzySets();

    protected:

        int index;
        float crispInput;
        fuzzySetArray* fuzzySets;
        fuzzySetArray* fuzzySetsCursor;

        void cleanFuzzySets(fuzzySetArray* aux);
};

#ifdef __cplusplus
}
#endif
#endif
