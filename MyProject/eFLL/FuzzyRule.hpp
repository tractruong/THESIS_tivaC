/*
 * Robotic Research Group (RRG)
 * State University of Piaui (UESPI)
 *
 * FuzzyRule.h
 *
 *      Author: Msc. Marvin Lemos <marvinlemos@gmail.com>
 *              AJ Alves <aj.alves@zerokol.com>
 *          Co authors: Douglas S. Kridi <douglaskridi@gmail.com>
 *                      Kannya Leal <kannyal@hotmail.com>
 */
#ifndef FUZZYRULE_H
#define FUZZYRULE_H

// IMPORTANDO AS BIBLIOTECAS
#include "FuzzyRuleAntecedent.h"
#include "FuzzyRuleConsequent.h"

class FuzzyRule {
    public:
        // CONSTRUTORES
        FuzzyRule();
        FuzzyRule(int index, FuzzyRuleAntecedent* fuzzyRuleAntecedent, FuzzyRuleConsequent* fuzzyRuleConsequent);

        int getIndex();
        bool evaluateExpression();
        bool isFired();

    private:

        int index;
        bool fired;
        FuzzyRuleAntecedent* fuzzyRuleAntecedent;
        FuzzyRuleConsequent* fuzzyRuleConsequent;
};
#endif
