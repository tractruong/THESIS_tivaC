//#include <iostream>
#include "../eFLL/FuzzyRule.hpp"
#include "../eFLL/FuzzyComposition.hpp"
#include "../eFLL/Fuzzy.hpp"
#include "../eFLL/FuzzyRuleConsequent.hpp"
#include "../eFLL/FuzzyOutput.hpp"
#include "../eFLL/FuzzyInput.hpp"
#include "../eFLL/FuzzyIO.hpp"
#include "../eFLL/FuzzySet.hpp"
#include "../eFLL/FuzzyRuleAntecedent.hpp"

//#define TEST_FUZZY

//using namespace std;
void Init_Fuzzy();
int Fuzzy_OutPut(float error, float velocity, float scale_err, float scale_vel, float scale_output, int min_out, int max_out);
int limit_output(int value, int min, int max);
