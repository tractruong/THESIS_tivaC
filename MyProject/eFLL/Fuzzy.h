/*
 * Robotic Research Group (RRG)
 * State University of Piaui (UESPI), Brazil - ­ - Teresina
 *
 * Fuzzy.h
 *
 *      Author: Msc. Marvin Lemos <marvinlemos@gmail.com>
 *              AJ Alves <aj.alves@zerokol.com>
 *          Co authors: Douglas S. Kridi <douglaskridi@gmail.com>
 *                      Kannya Leal <kannyal@hotmail.com>
 */
#ifndef FUZZY_H
#define FUZZY_H

// IMPORTANDO AS BIBLIOTECAS
#include <inttypes.h>
#include "FuzzyInput.h"
#include "FuzzyOutput.h"
#include "FuzzyRule.hpp"

// Estrutura de uma matriz de fuzzyInputArray
struct fuzzyInputArray{
    FuzzyInput* fuzzyInput;
    fuzzyInputArray* next;
};

// Estrutura de uma matriz de fuzzyOutputArray
struct fuzzyOutputArray{
    FuzzyOutput* fuzzyOutput;
    fuzzyOutputArray* next;
};

// Estrutura de uma lista de FuzzyRule
struct fuzzyRuleArray{
    FuzzyRule* fuzzyRule;
    fuzzyRuleArray* next;
};

class Fuzzy {
    public:
        // CONSTRUTORES
        Fuzzy();
        // DESTRUTOR
        ~Fuzzy();

        bool addFuzzyInput(FuzzyInput* fuzzyInput);
        bool addFuzzyOutput(FuzzyOutput* fuzzyOutput);
        bool addFuzzyRule(FuzzyRule* fuzzyRule);
        bool setInput(int fuzzyInputIndex, float crispValue);
        bool fuzzify();
        bool isFiredRule(int fuzzyRuleIndex);
        float defuzzify(int fuzzyOutputIndex);

    private:
        //
        // ponteiros para gerenciar os arrays de FuzzyInput
        fuzzyInputArray* fuzzyInputsCursor;
        fuzzyInputArray* fuzzyInputs;
        // ponteiros para gerenciar os arrays de FuzzyOutput
        fuzzyOutputArray* fuzzyOutputsCursor;
        fuzzyOutputArray* fuzzyOutputs;
        // ponteiros para gerenciar os arrays de FuzzyRule
        fuzzyRuleArray* fuzzyRulesCursor;
        fuzzyRuleArray* fuzzyRules;


        void cleanFuzzyInputs(fuzzyInputArray* aux);
        void cleanFuzzyOutputs(fuzzyOutputArray* aux);
        void cleanFuzzyRules(fuzzyRuleArray* aux);
};
#endif
