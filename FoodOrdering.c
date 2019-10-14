#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"structure.h"
#include"write.h"
#include"read.h"
#include"restaurants.h"



int main()
{
    struct data restaurant[30];
    struct NoOfRestaurants NoRes;
    NoRes.restaurants=0;
     char user_email[50],temp[50]="admin";
     int quantity=0,idx1=0,idx=0;
    FILE *fp;
     fp=fopen("price.txt","rb");
    if(fp == NULL)
              {
                     printf("\nCan't open file or file doesn't exist.");

              }

     getUserDetails(user_email);
     fflush(stdin);
     if(strcmp(user_email,temp)==0)
    write_data_to_file(restaurant,NoRes);
    read_data_from_file(restaurant,NoRes);
    fread(&NoRes,sizeof(struct NoOfRestaurants),1,fp);
  printf("Total Res in main() %d\n",NoRes.restaurants);
    DisplayRestaurants(&restaurant,&NoRes);
 int selected_restaurant = getSelectedRestaurant(NoRes);
     system("cls");
    printSelectedRestaurant(selected_restaurant,restaurant);
    DisplayItems(selected_restaurant,restaurant,NoRes);
    fflush(stdin);
   while(changeRestaurant())
   {
       system("cls");
         DisplayRestaurants(&restaurant,&NoRes);
    selected_restaurant = getSelectedRestaurant(NoRes);
     system("cls");
    printSelectedRestaurant(selected_restaurant,restaurant);
    DisplayItems(selected_restaurant,restaurant,NoRes);
    fflush(stdin);
   }
 int selected_item = get_selected_item(selected_restaurant,restaurant,NoRes);
      quantity= select_quantity(restaurant,selected_item,selected_restaurant,&quantity);
       system("cls");
     DisplayOrderDetails(restaurant,selected_restaurant,selected_item,user_email,quantity);
     while(Order())
     {
          DisplayRestaurants(&restaurant,&NoRes);
 int selected_restaurant = getSelectedRestaurant(NoRes);
     system("cls");
    printSelectedRestaurant(selected_restaurant,restaurant);
    DisplayItems(selected_restaurant,restaurant,NoRes);
    fflush(stdin);
   while(changeRestaurant())
   {
       system("cls");
         DisplayRestaurants(&restaurant,&NoRes);
    selected_restaurant = getSelectedRestaurant(NoRes);
     system("cls");
    printSelectedRestaurant(selected_restaurant,restaurant);
    DisplayItems(selected_restaurant,restaurant,NoRes);
    fflush(stdin);
   }
 int selected_item = get_selected_item(selected_restaurant,restaurant,NoRes);
       quantity=select_quantity(restaurant,selected_item,selected_restaurant,quantity);
       system("cls");
     DisplayOrderDetails(restaurant,selected_restaurant,selected_item,user_email,quantity);
     }
  return 0;
}
