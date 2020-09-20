#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

namespace myGlobals {
    int burgerCount;
    int friesCount;
    int saladCount;
    int hotdogCount;
    int drinksCount;
    float total;
    const float burgerCost = 1.99;
    const float friesCost = 0.99;
    const float saladCost = 1.50;
    const float hotdogCost = 1.45;
    const float drinksCost = 0.80;
}

using namespace std;

void menu(void){
    std::system("clear");
    printf("-----------------------------------------------INSTRUCTIONS--------------------------------------------\n");
    printf("To add and/or remove an item from the order enter the letter associated to the item followed by a space\n");
    printf("and then the quantity. To remove an item include a negative sign on the left of the quantity.\n");
    printf("-------------------------------------------------------------------------------------------------------\n\n");
    printf("-------------Menu-------------\n");
    printf("Burger(b) - $1.99\n");
    printf("Fries(f) - $0.99\n");
    printf("Salad(s) - $1.50\n");
    printf("Hotdog(h) - $1.45\n");
    printf("Drinks(d) - $0.80\n");
    printf("Completed Order(e 0)\n");
}

void itemCount(char item, int quantity){
    std::system("clear");
    char temp;

    if(item == 'b'){
        myGlobals::burgerCount = myGlobals::burgerCount + quantity;
        if(myGlobals::burgerCount < 0){
            myGlobals::burgerCount = 0;
        }
    }
    else if (item == 'f')
    {
        myGlobals::friesCount = myGlobals::friesCount + quantity;
        if(myGlobals::friesCount < 0){
            myGlobals::friesCount = 0;
        }
    }
    else if (item == 's')
    {
        myGlobals::saladCount = myGlobals::saladCount + quantity;
        if(myGlobals::saladCount < 0){
            myGlobals::saladCount = 0;
        }
    }
    else if (item == 'h')
    {
        myGlobals::hotdogCount = myGlobals::hotdogCount + quantity;
        if(myGlobals::hotdogCount < 0){
            myGlobals::hotdogCount = 0;
        }
    }
    else if (item == 'd')
    {
        myGlobals::drinksCount = myGlobals::drinksCount + quantity;
        if(myGlobals::drinksCount < 0){
            myGlobals::drinksCount = 0;
        }
    }
    else{
        //printf("****ITEM IS NOT PART OF THE MENU.****");

    }  
}

void itemTotals(){
    printf("-----------Totals-------------\n");
    if(myGlobals::burgerCount > 0){
        printf("Burgers: %d\n", myGlobals::burgerCount);
    }
    if(myGlobals::friesCount > 0){
        printf("Fries: %d\n", myGlobals::friesCount);
    }
    if(myGlobals::saladCount > 0){
        printf("Salad: %d\n", myGlobals::saladCount);
    }
    if(myGlobals::hotdogCount > 0){
        printf("Hotdog: %d\n", myGlobals::hotdogCount);
    }
    if(myGlobals::drinksCount > 0){
        printf("Drinks: %d\n", myGlobals::drinksCount);
    }

    myGlobals::total = (myGlobals::burgerCount * myGlobals::burgerCost) + (myGlobals::friesCount * myGlobals::friesCost) + (myGlobals::saladCount * myGlobals::saladCost) + (myGlobals::hotdogCount * myGlobals::hotdogCost) + (myGlobals::drinksCount * myGlobals::drinksCost);

    printf("Total: %.2f\n", myGlobals::total);
    printf("------------------------------\n");
}

void saveToFile(){
    std::ofstream outfile ("\\School\\C++\\Restaurant Menu V2\\RestaurantOrder.txt");
    outfile << "Item        Quantity" << std::endl;
    outfile << "--------------------" << std::endl;

    if(myGlobals::burgerCount > 0){
        outfile << "Burgers:    " << myGlobals::burgerCount << std::endl;       
    }

    if(myGlobals::friesCount > 0){
        outfile << "Fries:      " << myGlobals::friesCount << std::endl;       
    }

    if(myGlobals::saladCount > 0){
        outfile << "Fries:      " << myGlobals::saladCount << std::endl;       
    }

    if(myGlobals::hotdogCount > 0){
        outfile << "Hotdog:     " << myGlobals::hotdogCount << std::endl;       
    }

    if(myGlobals::drinksCount > 0){
        outfile << "Drinks:     " << myGlobals::drinksCount << std::endl;       
    }
    outfile << "--------------------" << std::endl;
    outfile << "Total:      " << myGlobals::total;

    outfile.close();
}

int main(void)
{
    char item;
    int quantity;

    while(item != 'e'){
        menu();
        itemTotals();

        printf("Enter the Item and quantity: ");
        std::cin >> item >> quantity;

        if(item != 'e'){
            itemCount(item, quantity);
        }
        else{
            saveToFile();
        }

    }

    return 0;
}