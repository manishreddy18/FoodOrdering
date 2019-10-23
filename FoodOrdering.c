#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"structure.h"
#include"write.h"
#include"read.h"
#include"restaurants.h"
#include"location.h"


int main()
{
    FILE *fptr;

    struct data details[3];

     char user_email[50],temp[50]="admin";
     int quantity=0,idx1=0,idx=0;
     details[0].No_of_locations=0;
 /*
     fptr=fopen("sample.txt","r");
     while( fscanf(fptr,"%d\n",&No_of_locations) != EOF)
     {
         printf("No of locations Read from file %d\n",No_of_locations);
     }
     fclose(fptr);
  */

    FILE *fp;
    fp=fopen("price.txt","rb");
    if(fp == NULL)
              {
                     printf("\nCan't open file or file doesn't exist.");

              }
        read_data_from_file(details);
        printf("No of locations %d\n",details[0].No_of_locations);
    getUserDetails(user_email);
    fflush(stdin);
         if(strcmp(user_email,temp)==0){
    details[0].No_of_locations=initialise_location(details);
       printf("No of locations after initialise locations %d\n",details[0].No_of_locations);
         }
    read_data_from_file(details);
       printf("Location scanned in main():%s\n",details[0].location[details[0].No_of_locations].Location_name);
      printf("No of locations written to file %d\n",details[0].No_of_locations);
 //    fptr=fopen("sample.txt","w");
 //    fprintf(fptr,"%d\n",No_of_locations);
 //    fclose(fptr);
   // fread(&NoRes,sizeof(struct NoOfRestaurants),1,fp);
      printf("Locations read:\n");
      for(int i=0;i<details[0].No_of_locations;i++)
      printf("%s\n",details[0].location[i].Location_name);
    DisplayLocation(details);
int selectedLocation=getSelectedLocation(details);
    DisplayRestaurants(details,selectedLocation);
 int selected_restaurant = getSelectedRestaurant(details,selectedLocation);
     system("cls");
    printSelectedRestaurant(selected_restaurant,selectedLocation,details);
    DisplayItems(selected_restaurant,selectedLocation,details);
    fflush(stdin);
   while(changeRestaurant())
   {
    DisplayRestaurants(details,selectedLocation);
    selected_restaurant = getSelectedRestaurant(details,selectedLocation);
       system("cls");
    printSelectedRestaurant(selected_restaurant,selectedLocation,details);
    DisplayItems(selected_restaurant,selectedLocation,details);
    fflush(stdin);
   }
 int selected_item = get_selected_item(selected_restaurant,selectedLocation,details);
     quantity= select_quantity(details,selected_item,selected_restaurant,selectedLocation,quantity);
       system("cls");
     DisplayOrderDetails(details,selectedLocation,selected_restaurant,selected_item,user_email,quantity);
     while(Order())
     {
        DisplayLocation(details);
    selectedLocation=getSelectedLocation(details);
    DisplayRestaurants(details,selectedLocation);
    selected_restaurant = getSelectedRestaurant(details,selectedLocation);
      system("cls");
    printSelectedRestaurant(selected_restaurant,selectedLocation,details);
    DisplayItems(selected_restaurant,selectedLocation,details);
    fflush(stdin);
   while(changeRestaurant())
   {
    DisplayRestaurants(details,selectedLocation);
    selected_restaurant = getSelectedRestaurant(details,selectedLocation);
       system("cls");
    printSelectedRestaurant(selected_restaurant,selectedLocation,details);
    DisplayItems(selected_restaurant,selectedLocation,details);
    fflush(stdin);
   }
 int selected_item = get_selected_item(selected_restaurant,selectedLocation,details);
     quantity= select_quantity(details,selected_item,selected_restaurant,selectedLocation,quantity);
       system("cls");
     DisplayOrderDetails(details,selectedLocation,selected_restaurant,selected_item,user_email,quantity);
   }

  return 0;
}
