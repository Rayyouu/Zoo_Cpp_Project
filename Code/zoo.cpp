#include "./includes/zoo.h"
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

Zoo::Zoo(/* args */)
{
}

Zoo::~Zoo()
{
}

void Zoo::Menu()
{
    string choice;
    string player_name;
    string zoo_name;
    int number_of_round = 1;

    // system("cls");
    cout << "*******************************" << endl;
    cout << "      	    ZOOLAND           " << endl;
    cout << "*******************************" << endl;
    cout << "\nBienvenue dans ZooLand !" << endl;
    cout << "\nIl s'agit d'un jeu de gestion en tour par tour d'un ZOO !\nCe simulateur de Zoo revisite est inpire par le celebre jeu ZOOTYCOON!" << endl;
    cout << "\nEnjoy !!" << endl;

    do
    {
        cout << "\n*******************************" << endl;
        cout << "      	    MENU            " << endl;
        cout << "\n Que souhaitez-vous faire ?" << endl;
        cout << "\nTapez 1: Lancez une partie." << endl;
        cout << "\nTapez 2: Fermez le programme.\n"
             << endl;
        cin >> choice;
    } while (choice != "1" && choice != "2");

    if (choice == "1")
    {
        // start the game with the "cycle" function

        cout << "\nEntrez votre pseudo : \n"
             << endl;
        cin >> player_name;
        cout << "\nBienvenue" << player_name << "!! Definissez le nom de votre Zoo : \n"
             << endl;
        cout << endl;
        cin >> zoo_name;
        cout << "\n"
             << player_name << ", la construction de votre zoo : " << zoo_name << " peut commencer !" << endl;
    }
    else
    {
        // leave the game
    }
}

void Zoo::Delete_Animal(int type, int ID)
// Function which will delete an animal, according to his type, and ID
{
    switch (type)
    {
    case 1: // aigle
        for (int i = 0; i < m_Eagle_Habitats.size(); i++)
        {
            Animal_Sell result = m_Eagle_Habitats[i].Delete_Animal(ID);
            if (result.Sell_Check)
            {
                m_Budget.Sell_Something(result.Price);
                cout << "\nVotre animal a ete supprime !" << endl;
            }
        }

        break;
    case 2: // tigre
        for (int i = 0; i < m_Tiger_Habitats.size(); i++)
        {
            Animal_Sell result = m_Tiger_Habitats[i].Delete_Animal(ID);
            if (result.Sell_Check)
            {
                m_Budget.Sell_Something(result.Price);
                cout << "\nVotre animal a ete supprime !" << endl;
            }
        }

        break;
    case 3: // hen
        for (int i = 0; i < m_Hen_Habitats.size(); i++)
        {
            Animal_Sell result = m_Hen_Habitats[i].Delete_Animal(ID);
            if (result.Sell_Check)
            {
                m_Budget.Sell_Something(result.Price);
                cout << "\nVotre animal a ete supprime !" << endl;
            }
        }
        break;

    default:
        break;
    }

    cout << "\nID inconnu, veuillez rentrer un ID correct la prochaine fois !" << endl;
}

void Zoo::Add_Animal(int type, int age, bool gender)
// Function which will add an Animal according to the type : 1 for eagle, 2 for tiger, 3 for hen
{
    switch (type)
    {
    case 1:
    {
        Aigle New_Animal(gender, age, m_Eagle_ID);
        m_Eagle_ID++;

        for (int i = 0; i < m_Eagle_Habitats.size(); i++)
        {
            if (m_Eagle_Habitats[i].Add_Animal_In_Habitat(New_Animal))
            {
                cout << "\nVotre animal est arrive !! Felicitations !" << endl;
                return;
            }
        }
        cout << "\nVotre animal ne peut pas venir dans votre zoo, car il n'a pas d'enclos pour le recevoir.\nVeuillez prevoir une habitation la prochaine fois!!" << endl;
    }
    break;
    case 2:
    {
        Tigre New_Animal(gender, age, m_Tiger_ID);
        m_Tiger_ID++;

        for (int i = 0; i < m_Tiger_Habitats.size(); i++)
        {
            if (m_Tiger_Habitats[i].Add_Animal_In_Habitat(New_Animal))
            {
                cout << "\nVotre animal est arrive !! Felicitations !" << endl;
                return;
            }
        }
        cout << "\nVotre animal ne peut pas venir dans votre zoo, car il n'a pas d'enclos pour le recevoir.\nVeuillez prevoir une habitation la prochaine fois!! " << endl;
    }
    break;
    case 3:
    {
        Poule New_Animal(gender, age, m_Hen_ID);
        m_Hen_ID++;

        for (int i = 0; i < m_Hen_Habitats.size(); i++)
        {
            if (m_Hen_Habitats[i].Add_Animal_In_Habitat(New_Animal))
            {
                cout << "\nVotre animal est arrive !! Felicitations !" << endl;
                return;
            }
        }
        cout << "\nVotre animal ne peut pas venir dans votre zoo, car il n'a pas d'enclos pour le recevoir.\nVeuillez prevoir une habitation la prochaine fois!! " << endl;
    }
    break;
    default:
        cout << "ERREUR LORS DE LA CREATION DE L'ANIMAL" << endl;
        break;
    }
}

void Zoo::Evenly_Buy_Animal()
{
    // Buy Animal action
    int Animal_Choice;
    int Sex_Choice;
    int Animal_Age;
    int confirm;
    cout << "\nVoulez vous acheter un tigre, un aigle, ou une poule/coq ?" << endl;
    do
    {
        cout << "\nTapez 1 pour aigle.\nTapez 2 pour tigre.\nTapez 3 pour poule/coq.\n\nVotre reponse : ";
        cin >> Animal_Choice;
    } while (Animal_Choice != 1 && Animal_Choice != 2 && Animal_Choice != 3);

    cout << "\nVous avez choisi un " << Display_Good_Animal(Animal_Choice, 0, 0) << endl;

    if (Animal_Choice != 3)
    {
        cout << "\nMaintenant choisissons l'age de votre futur " << Display_Good_Animal(Animal_Choice, 0, 0) << endl;

        do
        {
            cout << "\nTapez 1 pour 6 mois.\nTapez 2 pour 4 ans.\nTapez 3 pour 14 ans.\n\nVotre reponse : ";
            cin >> Animal_Age;
        } while (Animal_Age != 1 && Animal_Age != 2 && Animal_Age != 3);

        switch (Animal_Age)
        {
        case 1:
            Animal_Age = 6;
            break;
        case 2:
            Animal_Age = 48;
            break;
        case 3:
            Animal_Age = 168;
            break;
        default:
            break;
        }
    }
    else
    {
        Animal_Age = 6;
    }

    cout << "\nEnfin, veuillez choisir le sexe de votre animal : " << endl;

    do
    {
        cout << "\nTapez 1 pour male.\nTapez 2 pour femelle.\n\nVotre reponse : ";
        cin >> Sex_Choice;
    } while (Sex_Choice != 1 && Sex_Choice != 2);

    cout << "\nSuper ! Ce sera donc " << Display_Good_Animal(0, Sex_Choice, 0) << endl;

    int price = Check_Price_Buy_Value(Animal_Choice, Animal_Age, Sex_Choice);
    cout << "\nVotre " << Display_Good_Animal(Animal_Choice, 0, 0) << " va donc couter " << price << " euros !" << endl;
    do
    {
        cout << "\nTapez 1 pour Confirmer.\nTapez 2 pour Annuler.\n\nVotre reponse : " << endl;
        cin >> confirm;
    } while (confirm != 1 && confirm != 2);

    if (confirm == 1)
    {
        cout << "\nAjout de l'animal a votre enclos..." << endl;
        // m_Budget.Buy_Something(price);
        // Add_Animal(Animal_Choice, Animal_Age, Sex_Choice == 1)
        cout << "C'est" << Display_Good_Animal(0, Sex_Choice, 0) << " " << Display_Good_Animal(Animal_Choice, 0, 0) << " de " << Animal_Age << " mois.\n"
             << endl;
        cout << "C'est fait !" << endl;
    }
    else
    {
        cout << "La transaction a ete annule" << endl
             << endl
             << endl;
    }
}

string Zoo::Display_Good_Animal(int Animal_Choice, int Sex_Choice, int Animal_Age)
{
    if (Animal_Choice != 0)
    {
        switch (Animal_Choice)
        {
        case 1:
            return "aigle";
            break;
        case 2:
            return "tigre";
            break;
        default: // = case 3
            return "coq/poule";
            break;
        }
    }
    else if (Sex_Choice != 0)
    {
        if (Sex_Choice == 1)
        {
            return "un male";
        }
        return "une femelle";
    }
    else
    {
        switch (Animal_Age)
        {
        case 6: // 6 ans
            return " 6 mois";
            break;
        case 48: // 4 ans
            return " 4 ans";
            break;
        case 168: // 14 ans
            return " 14 ans";
            break;
        default:
            break;
        }
    }

    return ""; // check error
}

int Zoo::Check_Price_Buy_Value(int type, int age, int sex)
// Return the value of potential achat of an animal with the age and evenly sex
{
    switch (type)
    {
    case 1:
        switch (age)
        {
        case 6:
            return 1000;
            break;
        case 48:
            return 4000;
            break;
        case 168:
            return 2000;
            break;
        default:
            break;
        }
        break;
    case 2:
        switch (age)
        {
        case 6:
            return 3000;
            break;
        case 48:
            return 120000;
            break;
        case 168:
            return 60000;
            break;
        default:
            break;
        }
        break;
    case 3:
        if (sex == 1) // male
        {
            return 100;
        }
        else
        {
            return 20;
        }
        break;

    default:
        break;
    }

    return -1; // check error
}

void Zoo::Print_All_Animals()
{
    // Function which will display all the Animal on the Zoo
    for (int i = 0; i < m_Eagle_Habitats.size(); i++)
    {
        std::vector<Aigle> Current_Habitat = m_Eagle_Habitats[i].Get_All_Animals();
        for (int j = 0; j < Current_Habitat.size(); j++)
        {
            Current_Habitat[j].Print(); // Print informations about the animal
        }
    }

    // ! Print for Tiger
    for (int i = 0; i < m_Tiger_Habitats.size(); i++)
    {
        std::vector<Tigre> Current_Habitat = m_Tiger_Habitats[i].Get_All_Animals();
        for (int j = 0; j < Current_Habitat.size(); j++)
        {
            Current_Habitat[j].Print(); // Print informations about the animal
        }
    }

    // ! Print for eagle
    for (int i = 0; i < m_Hen_Habitats.size(); i++)
    {
        std::vector<Poule> Current_Habitat = m_Hen_Habitats[i].Get_All_Animals();
        for (int j = 0; j < Current_Habitat.size(); j++)
        {
            Current_Habitat[j].Print(); // Print informations about the animal
        }
    }
}

void Zoo::Evenly_Sell_Animal()
{
    int ID_Selected;
    int type;
    int confirm;

    cout << "\nVoici vos animaux : " << endl;
    Print_All_Animals();
    cout << "\nQuel Animal voulez-vous vendre ?" << endl;
    do
    {
        cout << "\nTapez 1 pour un aigle.\nTapez 2 pour un tigre.\nTapez 3 pour une poule ou un coq.\n\nVotre reponse : ";
        cin >> type;
    } while (type != 1 && type != 2 && type != 3);

    cout << "\nSelectionnez desormais le numero de l'animal que vous voulez supprimer : " << endl;
    cin >> ID_Selected;

    do
    {
        cout << "\nConfirmer ? \nAppuyez sur 1 pour Confirmer, sur 2 pour Annuler.\n\nVotre reponse : " << endl;
    } while (confirm != 1 && confirm != 2);

    Delete_Animal(type, ID_Selected);
}

void Zoo::Evenly_Buy_Habitat()
{
    int Habitat_Choice;

    cout << "Quel type d'habitat voulez vous ?" << endl
         << endl;

    do
    {
        cout << "Tapez 1 pour un habitat d'aigle" << endl;
        cout << "Tapez 2 pour un habitat de tigre" << endl;
        cout << "Tapez 3 pour un habitat de poule" << endl;
        cin >> Habitat_Choice;
    } while (Habitat_Choice != 1 && Habitat_Choice != 2 && Habitat_Choice != 3);

    switch (Habitat_Choice)
    {
    case 1:
    {
        Eagle_Habitat New_Habitat;
        m_Eagle_Habitats.push_back(New_Habitat);
        cout << "Rangement des animeaux..." << endl;
        m_Budget.Buy_Something(2000);
        cout << "Achat réussi ! " << endl;
        // ! Lancer une fonction qui permet de reloger les animeaux en trop vers le nouvel habitat
    }
    break;
    case 2:
    {
        Tiger_Habitat New_Habitat;
        m_Tiger_Habitats.push_back(New_Habitat);
        cout << "Rangement des animeaux..." << endl;
        m_Budget.Buy_Something(2000);
        cout << "Achat réussi ! " << endl;
        // ! Lancer une fonction qui permet de reloger les animeaux en trop vers le nouvel habitat
    }
    break;
    case 3:
    {
        Hen_Habitat New_Habitat;
        m_Hen_Habitats.push_back(New_Habitat);
        cout << "Rangement des animeaux..." << endl;
        m_Budget.Buy_Something(300);
        cout << "Achat réussi ! " << endl;
        // ! Lancer une fonction qui permet de reloger les animeaux en trop vers le nouvel habitat
    }
    break;

    default:
        break;
    }
}

void Zoo::Evenly_Sell_Habitat()
{
    int Habitat_Choice;
    int ID_Choice;
    int confirm;
    cout << "Quel type d'habitat voulez vous vendre ?" << endl;

    do
    {
        cout << "Tapez 1 pour les Habitats d'Aigle" << endl;
        cout << "Tapez 2 pour les Habitats de Tigre" << endl;
        cout << "Tapez 3 pour les Habitats de Poule/Coq" << endl;
        cin >> Habitat_Choice;
    } while (Habitat_Choice != 1 && Habitat_Choice != 2 && Habitat_Choice != 3);

    switch (Habitat_Choice)
    {
    case 1:
        if (m_Eagle_Habitats.size() != 0)
        {
            cout << "Voici vos habitats actuels\n"
                 << endl;
            for (int i = 0; i < m_Eagle_Habitats.size(); i++)
            {
                m_Eagle_Habitats[i].Print();
            }

            cout << "Veuillez rentrer l'ID de l'habitat que vous voulez supprimer : ";
            cin >> ID_Choice;

            cout << "ATTENTION ! Tout les animaux de l'habitat seront supprime" << endl;
            do
            {
                cout << "Tapez 1 pour confirmer, 2 pour annuler" << endl;
                cin >> confirm;
            } while (confirm != 1 && confirm != 2);

            if (confirm == 1)
            {
                if (Delete_Habitat(Habitat_Choice, ID_Choice))
                {
                    cout << "Votre habitat a bien ete supprime" << endl;
                }
                else
                {
                    cout << "Une erreur est survenue. Veuillez donner un ID correct. Transaction annule..." << endl;
                }
            }
            else
            {
                cout << "Achat annule..." << endl;
            }
        }

        break;
    case 2: // ! Pareil pour tigre
        /* code */
        break;
    case 3: // ! Pareil pour poule/coq
        /* code */
        break;

    default:
        break;
    }
}

bool Zoo::Delete_Habitat(int type, int ID)
{
    switch (type)
    {
    case 1:
        for (int i = 0; i < m_Eagle_Habitats.size(); i++)
        {
            if (m_Eagle_Habitats[i].Get_ID() == ID)
            {
                m_Eagle_Habitats[i], m_Eagle_Habitats[m_Eagle_Habitats.size() - 1] = m_Eagle_Habitats[m_Eagle_Habitats.size() - 1], m_Eagle_Habitats[i];
                m_Eagle_Habitats.pop_back();
                return true;
            }
        }
        break;
    case 2: // ! Pareil pour Tigre
        /* code */
        break;
    case 3: // ! Pareil pour Poule
        /* code */
        break;

    default:
        break;
    }
    return false;
}

void Zoo::Evenly_Buy_Food()
{
    int choice_food;
    int number_kilo_food;
    // 1 : demander quel nourriture il veut acheter
    // 2 : Demander quelle quantité il veut
    // 3 : Déduire du Budget avec la fonction Buy_Something
    // 4 : Ajouter à la quantité de bouffe la quatité acheté
    // 5 : C'st finit

    cout << "\nQuel type de nourriture souhaitez-vous acheter ?" << endl;
    do
    {
        cout << "\nTapez 1 pour de la Viande.\nTapez 2 pour des Graines.\n\nVotre reponse : " << endl;
        cin >> choice_food;
    } while (choice_food != 1 && choice_food != 2);

    switch (choice_food)
    {
    case 1: //viande
        cout << "\nCombien de kilogramme de viandes souhaitez-vous ?" << endl;
        cout << "Le prix du kilo de Viande est de 5 euros.\n\nVotre reponse : " << endl;
        cin >> number_kilo_food;
        // conditon pour verifier si l'utilisateur rentre bien un chiffre
        number_kilo_food *= 5;
        cout << "Vous achetez " << number_kilo_food << " de kilo de viandes." Buy_Something(number_kilo_food);
        m_Viande_Quantity += number_kilo_food;
        break;
    default:
        cout << "\nCombien de kilogramme de graines souhaitez-vous ?" << endl;
        cout << "Le prix du kilo de Viande est de 2,5 euros.\n\nVotre reponse : " << endl;
        cin >> number_kilo_food;
        // conditon pour verifier si l'utilisateur rentre bien un chiffre
        number_kilo_food *= 2.5;
        cout << "Vous achetez " << number_kilo_food << " de kilo de graines." Buy_Something(number_kilo_food);
        m_Graine_Quantity += number_kilo_food;
        break;
    }
}

void Zoo::Turn_Menu()
{
    // . Informer l'utilisateur des news de son zoo !
    int Action_Choice;
    cout << "Que voulez vous faire ? " << endl;

    while (Action_Choice != 6)
    {

        do
        {
            cout << endl
                 << "Tapez 1 pour acheter un habitat" << endl;
            cout << "Tapez 2 pour vendre un habitat" << endl;
            cout << "Tapez 3 pour acheter un animal" << endl;
            cout << "Tapez 4 pour vendre un animal" << endl;
            cout << "Tapez 5 pour acheter de la nourriture" << endl;
            cout << "Tapez 6 pour passer au mois suivant !" << endl;
            cout << "Choix : ";
            cin >> Action_Choice;
        } while (Action_Choice != 1 && Action_Choice != 2 && Action_Choice != 3 && Action_Choice != 4 && Action_Choice != 5 && Action_Choice != 6);

        switch (Action_Choice)
        {
        case 1:
            Evenly_Buy_Habitat();
            break;
        case 2:
            Evenly_Sell_Habitat();
            break;
        case 3:
            Evenly_Buy_Animal();
            break;
        case 4:
            Evenly_Sell_Animal();
            break;
        case 5:
            Evenly_Buy_Food();
            break;

        default:
            break;
        }
    }

    cout << "Mois suivant..." << endl;
}

void Zoo::Update_Month()
{
    /**
     * Update Hungry State of Animal
     * Update Maladie State of Animal
     * Update Reproduction State Of Animal
    */
}

void Zoo::Update_All_Animal_Reproduction_State()
{
    for (int i = 0; i < m_Eagle_Habitats.size(); i++)
    {
        std::vector<Aigle> Current_Habitat = m_Eagle_Habitats[i].Get_All_Animals();
        for (int j = 0; j < Current_Habitat.size(); j++)
        {
            /* code */
        }
    }
}

void Zoo::Update_All_Animal_Maladie_State()
{
}

void Zoo::Update_All_Animal_Hungry_State()
{
}