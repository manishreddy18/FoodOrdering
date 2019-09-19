#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"restaurants.h"

char user_email[50];
int No_of_Restaurants=4;
int quantity[50][50]={0};

int main()
{
     char restaurant[10][50]={ {"LUCKY'S BIRYANI HOUSE"},
                               { "MY FRIENDS CIRCLE RESTAURANT" },
                                 {"KFC"},
                                 {"DOMINOS PIZZA"} };
     char items[4][3][50]={ {"Butter Chicken ","Veg Biryani ","Chicken Biryani "},
                       {"Chicken 555 ","Tandoori Chicken ","Chicken 65 "},
                       {"Triple Treat ","Chick & Share ","Double Dose "},
                       {"Peppy Paneer ","Paneer & Onion ","veg Pizza "}   };
     float ratings[10]={3.7,4.2,4.0,4.3,4.2};
     int No_of_items[10]={3,3,3,3};
   getUserDetails(user_email);
    system("cls");
    DisplayRestaurants(No_of_Restaurants,restaurant,ratings);

 int selected_restaurant = getSelectedRestaurant(No_of_Restaurants);
     system("cls");
    printSelectedRestaurant(selected_restaurant,restaurant);
    DisplayItems(selected_restaurant,items);
    fflush(stdin);
   while(changeRestaurant())
   {
       system("cls");
       DisplayRestaurants(No_of_Restaurants,restaurant,ratings);
       selected_restaurant = getSelectedRestaurant(No_of_Restaurants);
        system("cls");
        printSelectedRestaurant(selected_restaurant,restaurant);
       DisplayItems(selected_restaurant,items);
       fflush(stdin);
   }
 int selected_item = get_selected_item(selected_restaurant,No_of_items);
       select_quantity(items,selected_item,selected_restaurant,quantity);
       system("cls");
    DisplayOrderDetails(restaurant,selected_restaurant,selected_item,user_email,items,quantity);
  return 0;
}

