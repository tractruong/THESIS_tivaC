/*
 * Robotic Research Group (RRG)
 *
 *
 * FuzzyRuleConsequent.h
 *
 *      Author: Msc. Marvin Lemos <marvinlemos@gmail.com>
 *              AJ Alves <aj.alves@zerokol.com>
 *          Co authors: Douglas S. Kridi <douglaskridi@gmail.com>
 *                      Kannya Leal <kannyal@hotmail.com>
 */
#ifndef FUZZYRULECONSEQUENT_H
#define FUZZYRULECONSEQUENT_H

//
#include <stdlib.h>
#include "FuzzySet.h"

// Estrutura de uma lista de FuzzySet
struct fuzzySetOutputArray{
    FuzzySet* fuzzySet;
    fuzzySetOutputArray* next;
};

class FuzzyRuleConsequent {
    public:
        // CONSTRUTORES
        FuzzyRuleConsequent();
        // DESTRUTOR
        ~FuzzyRuleConsequent();

        bool addOutput(FuzzySet* fuzzySet);
        bool evaluate(float power);

    private:

        fuzzySetOutputArray* fuzzySetOutputsCursor;
        fuzzySetOutputArray* fuzzySetOutputs;

        void cleanFuzzySets(fuzzySetOutputArray* aux);
};
#endif
