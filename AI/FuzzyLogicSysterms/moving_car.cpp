#include <iostream>
//--------------------------------------------------------------------------------
// Code generated by jFuzzyLogic
// jFuzzyLogic Version : JFuzzyLogic 3.3 (build 2015-04-09), by Pablo Cingolani 
// jFuzzyLogic creted by Pablo Cingolani
//--------------------------------------------------------------------------------


#include <stdio.h>

#include <stdlib.h>
double ruleAccumulationMethod_max(double defuzzifierValue, double valueToAggregate) { return (defuzzifierValue > valueToAggregate ? defuzzifierValue : valueToAggregate); }

double ruleActivationMethod_min(double degreeOfSupport, double membership) { return (degreeOfSupport < membership ? degreeOfSupport : membership); }

double ruleConnectionMethod_and(double antecedent1, double antecedent2) { return (antecedent1 < antecedent2 ? antecedent1 : antecedent2); }

class FunctionBlock_zad6 {

public:
	// VAR_INPUT
	double dystans;
	double predkosc;

	// VAR_OUTPUT
	double przyspieszenie;

private:
	// FUZZIFY dystans
	double dystans_dlugi;
	double dystans_krotki;
	double dystans_sredni;

	// FUZZIFY predkosc
	double predkosc_duza;
	double predkosc_mala;
	double predkosc_srednia;


	// DEFUZZIFY przyspieszenie
	double defuzzify_przyspieszenie[1000];


public:
	FunctionBlock_zad6();
	void calc();
	void print();

private:
	void defuzzify();
	void fuzzify();
	void reset();
	double membership_dystans_dlugi(double x);
	double membership_dystans_krotki(double x);
	double membership_dystans_sredni(double x);
	double membership_predkosc_duza(double x);
	double membership_predkosc_mala(double x);
	double membership_predkosc_srednia(double x);
	double membership_przyspieszenie_utrzymaj(double x);
	double membership_przyspieszenie_zredukuj(double x);
	double membership_przyspieszenie_zwiekszaj(double x);
	void calc_No1();

};

// Constructor
FunctionBlock_zad6::FunctionBlock_zad6() {
	przyspieszenie = 0.0;
}

// Calculate function block
void FunctionBlock_zad6::calc() {
	reset();
	fuzzify();
	calc_No1();
	defuzzify();
}

// RULEBLOCK No1
void FunctionBlock_zad6::calc_No1() {
	// RULE 1 : IF (dystans IS krotki) AND (predkosc IS mala) THEN przyspieszenie IS zredukuj;
	double degreeOfSupport_1 = 1.0 * (ruleConnectionMethod_and(dystans_krotki, predkosc_mala));
	if (degreeOfSupport_1 > 0) {
		for (int i = 0; i < 1000; i++) {
			double x = -20.0 + i * 0.04;
			double membership = membership_przyspieszenie_zredukuj(x);
			double y = ruleActivationMethod_min(degreeOfSupport_1, membership);
			defuzzify_przyspieszenie[i] += ruleAccumulationMethod_max(defuzzify_przyspieszenie[i], y);
		}
	}

	// RULE 2 : IF (dystans IS dlugi) AND (predkosc IS mala) THEN przyspieszenie IS zwiekszaj;
	double degreeOfSupport_2 = 1.0 * (ruleConnectionMethod_and(dystans_dlugi, predkosc_mala));
	if (degreeOfSupport_2 > 0) {
		for (int i = 0; i < 1000; i++) {
			double x = -20.0 + i * 0.04;
			double membership = membership_przyspieszenie_zwiekszaj(x);
			double y = ruleActivationMethod_min(degreeOfSupport_2, membership);
			defuzzify_przyspieszenie[i] += ruleAccumulationMethod_max(defuzzify_przyspieszenie[i], y);
		}
	}

	// RULE 3 : IF (dystans IS dlugi) AND (predkosc IS duza) THEN przyspieszenie IS utrzymaj;
	double degreeOfSupport_3 = 1.0 * (ruleConnectionMethod_and(dystans_dlugi, predkosc_duza));
	if (degreeOfSupport_3 > 0) {
		for (int i = 0; i < 1000; i++) {
			double x = -20.0 + i * 0.04;
			double membership = membership_przyspieszenie_utrzymaj(x);
			double y = ruleActivationMethod_min(degreeOfSupport_3, membership);
			defuzzify_przyspieszenie[i] += ruleAccumulationMethod_max(defuzzify_przyspieszenie[i], y);
		}
	}

	// RULE 4 : IF (dystans IS sredni) AND (predkosc IS mala) THEN przyspieszenie IS zwiekszaj;
	double degreeOfSupport_4 = 1.0 * (ruleConnectionMethod_and(dystans_sredni, predkosc_mala));
	if (degreeOfSupport_4 > 0) {
		for (int i = 0; i < 1000; i++) {
			double x = -20.0 + i * 0.04;
			double membership = membership_przyspieszenie_zwiekszaj(x);
			double y = ruleActivationMethod_min(degreeOfSupport_4, membership);
			defuzzify_przyspieszenie[i] += ruleAccumulationMethod_max(defuzzify_przyspieszenie[i], y);
		}
	}

	// RULE 5 : IF (dystans IS sredni) AND (predkosc IS duza) THEN przyspieszenie IS zredukuj;
	double degreeOfSupport_5 = 1.0 * (ruleConnectionMethod_and(dystans_sredni, predkosc_duza));
	if (degreeOfSupport_5 > 0) {
		for (int i = 0; i < 1000; i++) {
			double x = -20.0 + i * 0.04;
			double membership = membership_przyspieszenie_zredukuj(x);
			double y = ruleActivationMethod_min(degreeOfSupport_5, membership);
			defuzzify_przyspieszenie[i] += ruleAccumulationMethod_max(defuzzify_przyspieszenie[i], y);
		}
	}

	// RULE 6 : IF (dystans IS dlugi) AND (predkosc IS srednia) THEN przyspieszenie IS zwiekszaj;
	double degreeOfSupport_6 = 1.0 * (ruleConnectionMethod_and(dystans_dlugi, predkosc_srednia));
	if (degreeOfSupport_6 > 0) {
		for (int i = 0; i < 1000; i++) {
			double x = -20.0 + i * 0.04;
			double membership = membership_przyspieszenie_zwiekszaj(x);
			double y = ruleActivationMethod_min(degreeOfSupport_6, membership);
			defuzzify_przyspieszenie[i] += ruleAccumulationMethod_max(defuzzify_przyspieszenie[i], y);
		}
	}

	// RULE 7 : IF (dystans IS sredni) AND (predkosc IS srednia) THEN przyspieszenie IS utrzymaj;
	double degreeOfSupport_7 = 1.0 * (ruleConnectionMethod_and(dystans_sredni, predkosc_srednia));
	if (degreeOfSupport_7 > 0) {
		for (int i = 0; i < 1000; i++) {
			double x = -20.0 + i * 0.04;
			double membership = membership_przyspieszenie_utrzymaj(x);
			double y = ruleActivationMethod_min(degreeOfSupport_7, membership);
			defuzzify_przyspieszenie[i] += ruleAccumulationMethod_max(defuzzify_przyspieszenie[i], y);
		}
	}

	// RULE 8 : IF (dystans IS krotki) AND (predkosc IS duza) THEN przyspieszenie IS zredukuj;
	double degreeOfSupport_8 = 1.0 * (ruleConnectionMethod_and(dystans_krotki, predkosc_duza));
	if (degreeOfSupport_8 > 0) {
		for (int i = 0; i < 1000; i++) {
			double x = -20.0 + i * 0.04;
			double membership = membership_przyspieszenie_zredukuj(x);
			double y = ruleActivationMethod_min(degreeOfSupport_8, membership);
			defuzzify_przyspieszenie[i] += ruleAccumulationMethod_max(defuzzify_przyspieszenie[i], y);
		}
	}

	// RULE 9 : IF (dystans IS krotki) AND (predkosc IS srednia) THEN przyspieszenie IS zredukuj;
	double degreeOfSupport_9 = 1.0 * (ruleConnectionMethod_and(dystans_krotki, predkosc_srednia));
	if (degreeOfSupport_9 > 0) {
		for (int i = 0; i < 1000; i++) {
			double x = -20.0 + i * 0.04;
			double membership = membership_przyspieszenie_zredukuj(x);
			double y = ruleActivationMethod_min(degreeOfSupport_9, membership);
			defuzzify_przyspieszenie[i] += ruleAccumulationMethod_max(defuzzify_przyspieszenie[i], y);
		}
	}

}

// Defuzzify 
void FunctionBlock_zad6::defuzzify() {
	double sum_przyspieszenie = 0.0;
	double wsum_przyspieszenie = 0.0;
	for (int i = 0; i < 1000; i++) {
		double x = -20.0 + i * 0.04;
		sum_przyspieszenie += defuzzify_przyspieszenie[i];
		wsum_przyspieszenie += x * defuzzify_przyspieszenie[i];
	}
	przyspieszenie = wsum_przyspieszenie / sum_przyspieszenie;
}

// Fuzzify all variables
void FunctionBlock_zad6::fuzzify() {
	dystans_dlugi = membership_dystans_dlugi(dystans);
	dystans_krotki = membership_dystans_krotki(dystans);
	dystans_sredni = membership_dystans_sredni(dystans);
	predkosc_duza = membership_predkosc_duza(predkosc);
	predkosc_mala = membership_predkosc_mala(predkosc);
	predkosc_srednia = membership_predkosc_srednia(predkosc);
}

// Membership functions 
double FunctionBlock_zad6::membership_dystans_dlugi(double x) {
	if (x <= 250.0)	return 0.0;
	if (x > 500.0)	return 1.0;
	if (x <= 350.0)	return 0.0 + (1.0 - 0.0) * ((x - 250.0) / (350.0 - 250.0));
	if (x <= 500.0)	return 1.0 + (1.0 - 1.0) * ((x - 350.0) / (500.0 - 350.0));
}

double FunctionBlock_zad6::membership_dystans_krotki(double x) {
	if (x <= 0.0)	return 1.0;
	if (x > 100.0)	return 0.0;
	if (x <= 50.0)	return 1.0 + (1.0 - 1.0) * ((x - 0.0) / (50.0 - 0.0));
	if (x <= 100.0)	return 1.0 + (0.0 - 1.0) * ((x - 50.0) / (100.0 - 50.0));
}

double FunctionBlock_zad6::membership_dystans_sredni(double x) {
	if (x <= 100.0)	return 0.0;
	if (x > 350.0)	return 0.0;
	if (x <= 200.0)	return 0.0 + (1.0 - 0.0) * ((x - 100.0) / (200.0 - 100.0));
	if (x <= 350.0)	return 1.0 + (0.0 - 1.0) * ((x - 200.0) / (350.0 - 200.0));
}

double FunctionBlock_zad6::membership_predkosc_duza(double x) {
	if (x <= 60.0)	return 0.0;
	if (x > 100.0)	return 1.0;
	if (x <= 70.0)	return 0.0 + (1.0 - 0.0) * ((x - 60.0) / (70.0 - 60.0));
	if (x <= 100.0)	return 1.0 + (1.0 - 1.0) * ((x - 70.0) / (100.0 - 70.0));
}

double FunctionBlock_zad6::membership_predkosc_mala(double x) {
	if (x <= 0.0)	return 1.0;
	if (x > 40.0)	return 0.0;
	if (x <= 30.0)	return 1.0 + (1.0 - 1.0) * ((x - 0.0) / (30.0 - 0.0));
	if (x <= 40.0)	return 1.0 + (0.0 - 1.0) * ((x - 30.0) / (40.0 - 30.0));
}

double FunctionBlock_zad6::membership_predkosc_srednia(double x) {
	if (x <= 22.0)	return 0.0;
	if (x > 78.0)	return 0.0;
	if (x <= 50.0)	return 0.0 + (1.0 - 0.0) * ((x - 22.0) / (50.0 - 22.0));
	if (x <= 78.0)	return 1.0 + (0.0 - 1.0) * ((x - 50.0) / (78.0 - 50.0));
}

double FunctionBlock_zad6::membership_przyspieszenie_utrzymaj(double x) {
	if (x <= -10.0)	return 0.0;
	if (x > 10.0)	return 0.0;
	if (x <= 0.0)	return 0.0 + (1.0 - 0.0) * ((x - -10.0) / (0.0 - -10.0));
	if (x <= 10.0)	return 1.0 + (0.0 - 1.0) * ((x - 0.0) / (10.0 - 0.0));
}

double FunctionBlock_zad6::membership_przyspieszenie_zredukuj(double x) {
	if (x <= -20.0)	return 1.0;
	if (x > 0.0)	return 0.0;
	if (x <= -10.0)	return 1.0 + (1.0 - 1.0) * ((x - -20.0) / (-10.0 - -20.0));
	if (x <= 0.0)	return 1.0 + (0.0 - 1.0) * ((x - -10.0) / (0.0 - -10.0));
}

double FunctionBlock_zad6::membership_przyspieszenie_zwiekszaj(double x) {
	if (x <= 0.0)	return 0.0;
	if (x > 20.0)	return 1.0;
	if (x <= 10.0)	return 0.0 + (1.0 - 0.0) * ((x - 0.0) / (10.0 - 0.0));
	if (x <= 20.0)	return 1.0 + (1.0 - 1.0) * ((x - 10.0) / (20.0 - 10.0));
}


// Print 
void FunctionBlock_zad6::print() {
	printf("Function block zad6:\n");
	printf("	Input  %20s : %f\n", "dystans", dystans);
	printf("	       %20s : %f\n", "dystans_dlugi", dystans_dlugi);
	printf("	       %20s : %f\n", "dystans_krotki", dystans_krotki);
	printf("	       %20s : %f\n", "dystans_sredni", dystans_sredni);
	printf("	Input  %20s : %f\n", "predkosc", predkosc);
	printf("	       %20s : %f\n", "predkosc_duza", predkosc_duza);
	printf("	       %20s : %f\n", "predkosc_mala", predkosc_mala);
	printf("	       %20s : %f\n", "predkosc_srednia", predkosc_srednia);
	printf("	Output %20s : %f\n", "przyspieszenie", przyspieszenie);
}

// Reset output
void FunctionBlock_zad6::reset() {
	for (int i = 0; i < 1000; i++) { defuzzify_przyspieszenie[i] = 0.0; }
}

int main(int argc, char* argv[]) {
	// Create function blocks
	FunctionBlock_zad6 zad6;
	zad6.dystans = 1000.0;
	zad6.predkosc = 0.0;
	// Parse input
	int interval = 2;

	while (zad6.dystans >= 25) {

		std::cout << "D: " << zad6.dystans << " , V: " << zad6.predkosc << " , Acc: " << zad6.przyspieszenie << std::endl;
		zad6.predkosc = zad6.predkosc + zad6.przyspieszenie;

		zad6.dystans -= zad6.predkosc * interval * 1000 / 3600;

		zad6.calc();
		if (zad6.predkosc < 0) {
			break;
		}
	}
}