#include <iostream>
#include "../eFLL/FuzzyRule.h"
#include "../eFLL/FuzzyComposition.h"
#include "../eFLL/Fuzzy.h"
#include "../eFLL/FuzzyRuleConsequent.h"
#include "../eFLL/FuzzyOutput.h"
#include "../eFLL/FuzzyInput.h"
#include "../eFLL/FuzzyIO.h"
#include "../eFLL/FuzzySet.h"
#include "../eFLL/FuzzyRuleAntecedent.h"

//#define TEST_FUZZY

//using namespace std;
void Init_Fuzzy();
int Fuzzy_OutPut(float error, float velocity, float scale_err, float scale_vel, float scale_output, int min_out, int max_out);
int limit_output(int value, int min, int max);
