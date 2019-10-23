#include<stdio.h>

void write_data_to_file(struct data details[])
{
  printf("---------write_data_to_file()----------\n");
    char ch;
    int i,choice,temp,selected_location;
  //  NoRes.restaurants=0;
      FILE *fp;
      fp=fopen("price.txt","rb");
      if(fp == NULL)
              {
                     printf("\nCan't open file or file doesn't exist.");

              }
  //  fread(&NoRes,sizeof(struct NoOfRestaurants),1,fp);
    printf("Total Restaurants before writing restaurant to file %d\n",details[0].location[details[0].No_of_locations].No_of_restaurants);
  //   for(i=0;i<details.No_of_locations;i++)
    fread(&details[0],sizeof(struct data),20,fp);
  printf("Location scanned:%s\n",details[0].location[details[0].No_of_locations].Location_name);
    printf("do u want to add restaurant?:\n");
    scanf("%c",&ch);
    if(ch=='y'){
 printf("-----Adding Restaurant------\n");
    printf("Restaurant No:%d\n",details[0].location[details[0].No_of_locations].No_of_restaurants+1);
    do{
    fflush(stdin);
    printf("Res Name:");
    scanf("%[^\n]s",details[0].location[details[0].No_of_locations].restaurant[details[0].location[details[0].No_of_locations].No_of_restaurants].restaurant_name);
    fflush(stdin);
    printf("Rating:");
    scanf("%f",&details[0].location[details[0].No_of_locations].restaurant[details[0].location[details[0].No_of_locations].No_of_restaurants].rating);
    printf("No Of Items:");
    scanf("%d",&details[0].location[details[0].No_of_locations].restaurant[details[0].location[details[0].No_of_locations].No_of_restaurants].No_of_items);
    printf("Enter %d items:",details[0].location[details[0].No_of_locations].restaurant[details[0].location[details[0].No_of_locations].No_of_restaurants].No_of_items);
     fflush(stdin);
    for(int i=0;i<details[0].location[details[0].No_of_locations].restaurant[details[0].location[details[0].No_of_locations].No_of_restaurants].No_of_items;i++){
        scanf("%[^\n]s",details[0].location[details[0].No_of_locations].restaurant[details[0].location[details[0].No_of_locations].No_of_restaurants].items[i].item_name);
        fflush(stdin);
        printf("%s price:",details[0].location[details[0].No_of_locations].restaurant[details[0].location[details[0].No_of_locations].No_of_restaurants].items[i].item_name);
        scanf("%d",&details[0].location[details[0].No_of_locations].restaurant[details[0].location[details[0].No_of_locations].No_of_restaurants].items[i].item_price);
        fflush(stdin);
    }
    details[0].location[details[0].No_of_locations].No_of_restaurants++;
    printf("do u want to add restaurant?(y/n):");
        scanf("%c",&ch);
    }
    while(ch=='y');
    }
    fclose(fp);

    fp=fopen("price.txt","wb+");
    fseek(fp, 0, SEEK_SET);
      if(fp == NULL)
              {
                     printf("\nCan't open file or file doesn't exist.");

              }
   //fwrite(&NoRes,sizeof(struct NoOfRestaurants),1,fp);
   // for(int i=0;i<No_of_locations;i++){
     fwrite(&details[0],sizeof(struct data),20,fp);
   // }
     printf("data written to file\n");
    fclose(fp);
}
