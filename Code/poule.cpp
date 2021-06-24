#include "includes/poule.h"
#include <iostream>

Poule::Poule()
{
}

Poule::Poule(bool gender, int age, int ID) : Animal(gender, age)
{
    // Informations about Maladie
    m_State.s_Malade.Max_Days = 5;

    // Reproduction state
    m_State.s_Age.Life_Esperance = 300; // = 25 years
    m_State.s_Age.Sexual_Maturity = 6;  // = 6 mois
    m_ID = ID;

    if (gender)
    {
        //  define all parametters for male Eagle
        // Hungry state
        m_State.s_Hungry.Max_Days = 2; //coq
        m_Type_Of_Food = "graine";
        m_Food_Quantity = 0.18;
    }
    else
    {
        // define all parametters for female Eagle
        // Hungry state
        m_State.s_Hungry.Max_Days = 1; //poule
        m_Type_Of_Food = "graine";
        m_Food_Quantity = 0.15;
    }
}

void Poule::Print()
{
    std::cout << "----------" << std::endl;
    std::cout << "ID : " << m_ID << std::endl;
    std::cout << "Poule de " << m_State.s_Age.Current_Age << " mois, " << m_Gender << std::endl;
    std::cout << "----------" << std::endl;
}

Poule::~Poule()
{
}

float Poule::CheckPriceValue()
// Function which will return the price of the current animal according to the age
{
    // if the animal is a male
    if (m_State.s_Malade.Is_Malade || m_State.s_Hungry.Is_Hungry)
    {
        return 0.0;
    }

    if (m_Gender)
    {
        return 20;
    }
    else
    {
        return 10;
    }
}

int Poule::Get_ID()
{
    return m_ID;
}