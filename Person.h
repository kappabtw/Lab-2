#include <iostream>
using namespace std;
#pragma once
class Person {  
    public:       
        Person();   
        void setName(string);   
        string getName();
        void calculate(int);
        int getbase();
        int getstat(string);
        int getstamina();
        void plusstat(int, string);
        int getebuff();
        void getibuff();
        void getsbuff();
        void startstamina(); //использовать в самом начале для рассчёта базовой стамины

    private: 
        string nameperson;// имя     
        int endu;
        int inte;
        int stre;
        int bufinte;
        int bufendu;//кол-во восстанавливаемой стамины
        int bufstre;
        int stamina;
        int basestamina;
        int base;


};