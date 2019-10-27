#include<stdio.h>

void read_data_from_file(struct place location[],int No_of_locations)
{
printf("--------Read data from file()---------started.\n");
    FILE *fp;
    int i;
    fp=fopen("price.txt","rb");
    if(fp == NULL)
              {
                     printf("\nCan't open file or file doesn't exist.");

              }
 //   struct data restaurant[30];
 //   struct NoOfRestaurants NoRes;
  // NoRes.restaurants=0;
  //   fread(&NoRes,sizeof(struct NoOfRestaurants),1,fp);
   //    printf("Total Restaurants after reading from file:%d\n",NoRes.restaurants);
    for(i=0;i<No_of_locations;i++){
    fread(&location[i],sizeof(struct place),(No_of_locations)+1,fp);

    }
  /*
   for(int idx=0;idx<NoRes.restaurants;idx++){

    printf("\t\tres name %s\n\t\trating %.1f \n\t\tNo of items:%d\n",restaurant[idx].restaurant_name,restaurant[idx].rating,restaurant[idx].No_of_items);
     for(i=0;i<restaurant[idx].No_of_items;i++){
        printf("\t\titem %d %s %d\n",i+1,restaurant[idx].items[i].item_name,restaurant[idx].items[i].item_price);
     }
      printf("\t   -------------------------\n");
   }
   */
  fclose(fp);
 printf("-----------read data from file()---------------ended.\n");
}

