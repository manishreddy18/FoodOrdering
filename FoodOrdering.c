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

    struct place location[5];

     char user_email[50],temp[50]="admin";
     int quantity=0,idx1=0,idx=0,No_of_locations=0;
     fptr=fopen("sample.txt","r");
     while( fscanf(fptr,"%d\n",&No_of_locations) != EOF)
     {
         printf("No of locations Read from file %d\n",No_of_locations);
     }
     fclose(fptr);


    FILE *fp;
     fp=fopen("price.txt","rb");
    if(fp == NULL)
              {
                     printf("\nCan't open file or file doesn't exist.");

              }
   printf("No of locations %d\n",No_of_locations);
     getUserDetails(user_email);
     fflush(stdin);
         if(strcmp(user_email,temp)==0){
     No_of_locations=initialise_location(location,No_of_locations);
     printf("No of locations after initialise locations %d\n",No_of_locations);
         }
    read_data_from_file(location,No_of_locations);
    printf("No of locations written to file %d\n",No_of_locations);
     fptr=fopen("sample.txt","w");
     fprintf(fptr,"%d\n",No_of_locations);
     fclose(fptr);
   // fread(&NoRes,sizeof(struct NoOfRestaurants),1,fp);
   printf("Locations read:\n");
   for(int i=0;i<No_of_locations;i++)
    printf("%s\n",location[i].Location_name);
    DisplayLocation(location,No_of_locations);
int selectedLocation=getSelectedLocation(No_of_locations);
    DisplayRestaurants(location,selectedLocation);
 int selected_restaurant = getSelectedRestaurant(location,selectedLocation);
     system("cls");
    printSelectedRestaurant(selected_restaurant,selectedLocation,location);
    DisplayItems(selected_restaurant,selectedLocation,location);
    fflush(stdin);
   while(changeRestaurant())
   {
          DisplayRestaurants(location,selectedLocation);
  selected_restaurant = getSelectedRestaurant(location,selectedLocation);
     system("cls");
    printSelectedRestaurant(selected_restaurant,selectedLocation,location);
    DisplayItems(selected_restaurant,selectedLocation,location);
    fflush(stdin);
   }
 int selected_item = get_selected_item(selected_restaurant,selectedLocation,location);
      quantity= select_quantity(location,selected_item,selected_restaurant,selectedLocation,quantity);
       system("cls");
     DisplayOrderDetails(location,selectedLocation,selected_restaurant,selected_item,user_email,quantity);
     while(Order())
     {
       DisplayRestaurants(location,selectedLocation);
  selected_restaurant = getSelectedRestaurant(location,selectedLocation);
     system("cls");
    printSelectedRestaurant(selected_restaurant,selectedLocation,location);
    DisplayItems(selected_restaurant,selectedLocation,location);
    fflush(stdin);
   while(changeRestaurant())
   {
          DisplayRestaurants(location,selectedLocation);
  selected_restaurant = getSelectedRestaurant(location,selectedLocation);
     system("cls");
    printSelectedRestaurant(selected_restaurant,selectedLocation,location);
    DisplayItems(selected_restaurant,selectedLocation,location);
    fflush(stdin);
   }
  selected_item = get_selected_item(selected_restaurant,selectedLocation,location);
      quantity= select_quantity(location,selected_item,selected_restaurant,selectedLocation,quantity);
       system("cls");
     DisplayOrderDetails(location,selectedLocation,selected_restaurant,selected_item,user_email,quantity);

   }

  return 0;
}
