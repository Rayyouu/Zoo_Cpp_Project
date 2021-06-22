// #include <iostream>
#ifndef BUDGET_H
#define BUDGET_H

#include <cmath>


class Budget {
    private:
        float m_Capital = 80000;
    public:
        Budget();
        ~Budget();
        void Add_Money_By_Subvention(int month, int Nbr_Tiger, int Nbr_Eagle);
        void Money_Incomme_By_Visitors(int month, int Nbr_Tiger, int Nbr_Poule, int Nbr_Eagle);
        float Get_Capital();
        void Buy_Habitat(int price);
        void Sell_Habitat(int price);
};



void Budget::Buy_Habitat(int price) {
    m_Capital -= price;
};

void Budget::Sell_Habitat(int price) {
    m_Capital += price;
};

#endif
