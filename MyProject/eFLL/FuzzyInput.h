/*
 * Robotic Research Group (RRG)
 * State University of Piaui (UESPI), Brazil - ­ - Teresina
 *
 * FuzzyInput.h
 *
 *      Author: Msc. Marvin Lemos <marvinlemos@gmail.com>
 *              AJ Alves <aj.alves@zerokol.com>
 *          Co authors: Douglas S. Kridi <douglaskridi@gmail.com>
 *                      Kannya Leal <kannyal@hotmail.com>
 */
#ifndef FUZZYINPUT_H
#define FUZZYINPUT_H

// IMPORTANDO AS BIBLIOTECAS
#include "FuzzyIO.h"

class FuzzyInput : public FuzzyIO {
    public:
        // CONSTRUTORES
        FuzzyInput();
        FuzzyInput(int index);
        // DESTRUTOR
        ~FuzzyInput();

        bool calculateFuzzySetPertinences();
};
#endif
