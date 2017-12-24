#include "../eFLL/fuzzy_ball_and_plate.h"

Fuzzy* fuzzy = new Fuzzy();
void Init_Fuzzy()
{
    // input
    FuzzyInput* error_in_postion = new FuzzyInput(1);
    FuzzyInput* change_in_error = new FuzzyInput(2);

    // Output
    FuzzyOutput* angle = new FuzzyOutput(1);


    // variables for input : error in postion ===============================
    FuzzySet* err_NL = new FuzzySet(-1, -1, -0.75, -0.25);
    error_in_postion->addFuzzySet(err_NL);

    FuzzySet* err_NS = new FuzzySet(-0.75, -0.25, -0.25, -0.05);
    error_in_postion->addFuzzySet(err_NS);

    FuzzySet* err_Z = new FuzzySet(-0.25, -0.05, 0.05, 0.25);
    error_in_postion->addFuzzySet(err_Z);

    FuzzySet* err_PS = new FuzzySet(0.05, 0.25, 0.25, 0.75);
    error_in_postion->addFuzzySet(err_PS);

    FuzzySet* err_PL = new FuzzySet(0.25, 0.75, 1, 1);
    error_in_postion->addFuzzySet(err_PL);

    fuzzy->addFuzzyInput(error_in_postion); // Adding FuzzyInput to fuzzy

    // variables for input : change in errors ===============================
    FuzzySet* vel_NL = new FuzzySet(-1, -1, -0.85, -0.4);
    change_in_error->addFuzzySet(vel_NL);

    FuzzySet* vel_NS = new FuzzySet(-0.85, -0.4, -0.4, -0.08);
    change_in_error->addFuzzySet(vel_NS);

    FuzzySet* vel_Z = new FuzzySet(-0.4, -0.08, 0.08, 0.4);
    change_in_error->addFuzzySet(vel_Z);

    FuzzySet* vel_PS = new FuzzySet(0.08, 0.4, 0.4, 0.85);
    change_in_error->addFuzzySet(vel_PS);

    FuzzySet* vel_PL = new FuzzySet(0.4, 0.85, 1, 1);
    change_in_error->addFuzzySet(vel_PL);

    fuzzy->addFuzzyInput(change_in_error); // Adding FuzzyInput to fuzzy

    // variables for output : angle of plate ===============================
    FuzzySet* angle_NL = new FuzzySet(-1, -1, -0.75, -0.5);
    angle->addFuzzySet(angle_NL);

    FuzzySet* angle_NM = new FuzzySet(-0.75, -0.5, -0.5, -0.25);
    angle->addFuzzySet(angle_NM);

    FuzzySet* angle_NS = new FuzzySet(-0.5, -0.25, -0.25, 0);
    angle->addFuzzySet(angle_NS);

    FuzzySet* angle_Z = new FuzzySet(-0.25, 0, 0, 0.25);
    angle->addFuzzySet(angle_Z);

    FuzzySet* angle_PS = new FuzzySet(0, 0.25, 0.25, 0.5);
    angle->addFuzzySet(angle_PS);

    FuzzySet* angle_PM = new FuzzySet(0.25, 0.5, 0.5, 0.75);
    angle->addFuzzySet(angle_PM);

    FuzzySet* angle_PL = new FuzzySet(0.5, 0.75, 1, 1);
    angle->addFuzzySet(angle_PL);

    fuzzy->addFuzzyOutput(angle); // Adding FuzzyOutput to fuzzy


    // Defining FuzzyRule

    FuzzyRuleAntecedent* if_errNL_and_vel_NL = new FuzzyRuleAntecedent();
    FuzzyRuleAntecedent* if_errNL_and_vel_NS = new FuzzyRuleAntecedent();
    FuzzyRuleAntecedent* if_errNL_and_vel_Z = new FuzzyRuleAntecedent();
    FuzzyRuleAntecedent* if_errNL_and_vel_PS = new FuzzyRuleAntecedent();
    FuzzyRuleAntecedent* if_errNL_and_vel_PL = new FuzzyRuleAntecedent();

    FuzzyRuleAntecedent* if_errNS_and_vel_NL = new FuzzyRuleAntecedent();
    FuzzyRuleAntecedent* if_errNS_and_vel_NS = new FuzzyRuleAntecedent();
    FuzzyRuleAntecedent* if_errNS_and_vel_Z = new FuzzyRuleAntecedent();
    FuzzyRuleAntecedent* if_errNS_and_vel_PS = new FuzzyRuleAntecedent();
    FuzzyRuleAntecedent* if_errNS_and_vel_PL = new FuzzyRuleAntecedent();

    FuzzyRuleAntecedent* if_errZ_and_vel_NL = new FuzzyRuleAntecedent();
    FuzzyRuleAntecedent* if_errZ_and_vel_NS = new FuzzyRuleAntecedent();
    FuzzyRuleAntecedent* if_errZ_and_vel_Z = new FuzzyRuleAntecedent();
    FuzzyRuleAntecedent* if_errZ_and_vel_PS = new FuzzyRuleAntecedent();
    FuzzyRuleAntecedent* if_errZ_and_vel_PL = new FuzzyRuleAntecedent();

    FuzzyRuleAntecedent* if_errPS_and_vel_NL = new FuzzyRuleAntecedent();
    FuzzyRuleAntecedent* if_errPS_and_vel_NS = new FuzzyRuleAntecedent();
    FuzzyRuleAntecedent* if_errPS_and_vel_Z = new FuzzyRuleAntecedent();
    FuzzyRuleAntecedent* if_errPS_and_vel_PS = new FuzzyRuleAntecedent();
    FuzzyRuleAntecedent* if_errPS_and_vel_PL = new FuzzyRuleAntecedent();

    FuzzyRuleAntecedent* if_errPL_and_vel_NL = new FuzzyRuleAntecedent();
    FuzzyRuleAntecedent* if_errPL_and_vel_NS = new FuzzyRuleAntecedent();
    FuzzyRuleAntecedent* if_errPL_and_vel_Z = new FuzzyRuleAntecedent();
    FuzzyRuleAntecedent* if_errPL_and_vel_PS = new FuzzyRuleAntecedent();
    FuzzyRuleAntecedent* if_errPL_and_vel_PL = new FuzzyRuleAntecedent();

    FuzzyRuleConsequent* then_angle_NL = new FuzzyRuleConsequent();
    FuzzyRuleConsequent* then_angle_NM = new FuzzyRuleConsequent();
    FuzzyRuleConsequent* then_angle_NS = new FuzzyRuleConsequent();
    FuzzyRuleConsequent* then_angle_Z = new FuzzyRuleConsequent();
    FuzzyRuleConsequent* then_angle_PS = new FuzzyRuleConsequent();
    FuzzyRuleConsequent* then_angle_PM = new FuzzyRuleConsequent();
    FuzzyRuleConsequent* then_angle_PL = new FuzzyRuleConsequent();


    if_errNL_and_vel_NL->joinWithAND(err_NL, vel_NL);
    if_errNL_and_vel_NS->joinWithAND(err_NL, vel_NS);
    if_errNL_and_vel_Z->joinWithAND(err_NL, vel_Z);
    if_errNL_and_vel_PS->joinWithAND(err_NL, vel_PS);
    if_errNL_and_vel_PL->joinWithAND(err_NL, vel_PL);

    if_errNS_and_vel_NL->joinWithAND(err_NS, vel_NL);
    if_errNS_and_vel_NS->joinWithAND(err_NS, vel_NS);
    if_errNS_and_vel_Z->joinWithAND(err_NS, vel_Z);
    if_errNS_and_vel_PS->joinWithAND(err_NS, vel_PS);
    if_errNS_and_vel_PL->joinWithAND(err_NS, vel_PL);

    if_errZ_and_vel_NL->joinWithAND(err_Z, vel_NL);
    if_errZ_and_vel_NS->joinWithAND(err_Z, vel_NS);
    if_errZ_and_vel_Z->joinWithAND(err_Z, vel_Z);
    if_errZ_and_vel_PS->joinWithAND(err_Z, vel_PS);
    if_errZ_and_vel_PL->joinWithAND(err_Z, vel_PL);

    if_errPS_and_vel_NL->joinWithAND(err_PS, vel_NL);
    if_errPS_and_vel_NS->joinWithAND(err_PS, vel_NS);
    if_errPS_and_vel_Z->joinWithAND(err_PS, vel_Z);
    if_errPS_and_vel_PS->joinWithAND(err_PS, vel_PS);
    if_errPS_and_vel_PL->joinWithAND(err_PS, vel_PL);

    if_errPL_and_vel_NL->joinWithAND(err_PL, vel_NL);
    if_errPL_and_vel_NS->joinWithAND(err_PL, vel_NS);
    if_errPL_and_vel_Z->joinWithAND(err_PL, vel_Z);
    if_errPL_and_vel_PS->joinWithAND(err_PL, vel_PS);
    if_errPL_and_vel_PL->joinWithAND(err_PL, vel_PL);

    then_angle_NL->addOutput(angle_NL);
    then_angle_NM->addOutput(angle_NM);
    then_angle_NS->addOutput(angle_NS);
    then_angle_Z ->addOutput(angle_Z );
    then_angle_PS->addOutput(angle_PS);
    then_angle_PM->addOutput(angle_PM);
    then_angle_PL->addOutput(angle_PL);

    FuzzyRule* fuzzyRule1 = new FuzzyRule(1, if_errNL_and_vel_NL, then_angle_NL);
    FuzzyRule* fuzzyRule2 = new FuzzyRule(2, if_errNL_and_vel_NS, then_angle_NL);
    FuzzyRule* fuzzyRule3 = new FuzzyRule(3, if_errNL_and_vel_Z , then_angle_NM);
    FuzzyRule* fuzzyRule4 = new FuzzyRule(4, if_errNL_and_vel_PS, then_angle_Z );
    FuzzyRule* fuzzyRule5 = new FuzzyRule(5, if_errNL_and_vel_PL, then_angle_PS);

    FuzzyRule* fuzzyRule6 = new FuzzyRule(6, if_errNS_and_vel_NL, then_angle_NL);
    FuzzyRule* fuzzyRule7 = new FuzzyRule(7, if_errNS_and_vel_NS, then_angle_NM);
    FuzzyRule* fuzzyRule8 = new FuzzyRule(8, if_errNS_and_vel_Z , then_angle_NM);
    FuzzyRule* fuzzyRule9 = new FuzzyRule(9, if_errNS_and_vel_PS, then_angle_PS);
    FuzzyRule* fuzzyRule10 = new FuzzyRule(10, if_errNS_and_vel_PL, then_angle_PM);

    FuzzyRule* fuzzyRule11 = new FuzzyRule(11, if_errZ_and_vel_NL, then_angle_NM);
    FuzzyRule* fuzzyRule12 = new FuzzyRule(12, if_errZ_and_vel_NS, then_angle_NM);
    FuzzyRule* fuzzyRule13 = new FuzzyRule(13, if_errZ_and_vel_Z , then_angle_Z );
    FuzzyRule* fuzzyRule14 = new FuzzyRule(14, if_errZ_and_vel_PS, then_angle_PM);
    FuzzyRule* fuzzyRule15 = new FuzzyRule(15, if_errZ_and_vel_PL, then_angle_PM);

    FuzzyRule* fuzzyRule16 = new FuzzyRule(16, if_errPS_and_vel_NL, then_angle_NM);
    FuzzyRule* fuzzyRule17 = new FuzzyRule(17, if_errPS_and_vel_NS, then_angle_NS);
    FuzzyRule* fuzzyRule18 = new FuzzyRule(18, if_errPS_and_vel_Z , then_angle_PM);
    FuzzyRule* fuzzyRule19 = new FuzzyRule(19, if_errPS_and_vel_PS, then_angle_PM);
    FuzzyRule* fuzzyRule20 = new FuzzyRule(20, if_errPS_and_vel_PL, then_angle_PL);

    FuzzyRule* fuzzyRule21 = new FuzzyRule(21, if_errPL_and_vel_NL, then_angle_NS);
    FuzzyRule* fuzzyRule22 = new FuzzyRule(22, if_errPL_and_vel_NS, then_angle_Z );
    FuzzyRule* fuzzyRule23 = new FuzzyRule(23, if_errPL_and_vel_Z , then_angle_PM);
    FuzzyRule* fuzzyRule24 = new FuzzyRule(24, if_errPL_and_vel_PS, then_angle_PL);
    FuzzyRule* fuzzyRule25 = new FuzzyRule(25, if_errPL_and_vel_PL, then_angle_PL);


    fuzzy->addFuzzyRule(fuzzyRule1);
    fuzzy->addFuzzyRule(fuzzyRule2);
    fuzzy->addFuzzyRule(fuzzyRule3);
    fuzzy->addFuzzyRule(fuzzyRule4);
    fuzzy->addFuzzyRule(fuzzyRule5);
    fuzzy->addFuzzyRule(fuzzyRule6);
    fuzzy->addFuzzyRule(fuzzyRule7);
    fuzzy->addFuzzyRule(fuzzyRule8);
    fuzzy->addFuzzyRule(fuzzyRule9);
    fuzzy->addFuzzyRule(fuzzyRule10);
    fuzzy->addFuzzyRule(fuzzyRule11);
    fuzzy->addFuzzyRule(fuzzyRule12);
    fuzzy->addFuzzyRule(fuzzyRule13);
    fuzzy->addFuzzyRule(fuzzyRule14);
    fuzzy->addFuzzyRule(fuzzyRule15);
    fuzzy->addFuzzyRule(fuzzyRule16);
    fuzzy->addFuzzyRule(fuzzyRule17);
    fuzzy->addFuzzyRule(fuzzyRule18);
    fuzzy->addFuzzyRule(fuzzyRule19);
    fuzzy->addFuzzyRule(fuzzyRule20);
    fuzzy->addFuzzyRule(fuzzyRule21);
    fuzzy->addFuzzyRule(fuzzyRule22);
    fuzzy->addFuzzyRule(fuzzyRule23);
    fuzzy->addFuzzyRule(fuzzyRule24);
    fuzzy->addFuzzyRule(fuzzyRule25);
}

int Fuzzy_OutPut(float error, float velocity, float scale_err, float scale_vel, float scale_output, int min_out, int max_out)
{
	float err =  error *  scale_err;
	float vel =  velocity *  scale_vel;

    fuzzy->setInput(1, err);
    fuzzy->setInput(2, vel);

    fuzzy->fuzzify();

	float output = fuzzy->defuzzify(1);
    //cout << " Err : "<< err_NL->getPertinence() << " " << err_NS->getPertinence() << " " << err_Z->getPertinence() << " " << err_PS->getPertinence() << " " << err_PL->getPertinence() << " " << endl;
    //cout << " Vel : "<< vel_NL->getPertinence() << " " << vel_NS->getPertinence() << " " << vel_Z->getPertinence() << " " << vel_PS->getPertinence() << " " << vel_PL->getPertinence() << " " << endl;
    //cout << " Angle: "<< output << endl;


    return limit_output((int)(output*scale_output), min_out, max_out);
}
int limit_output(int value, int min, int max)
{
    if (value > max)
    {
        return max;
    }
    else if (value < min)
    {
        return min;
    }
    else
    {
        return value;
    }
}

//#ifdef TEST_FUZZY
//    // Implement test
//int main(int argc, char *argv[]) {
//    Init_Fuzzy();
//    int error = 0;
//    int pre_error = -200;
//    int velocity = error - pre_error;
//    cout << Fuzzy_OutPut(error,velocity,200,200,30,-10,10);
//    return 0;
//}
//
//#endif
