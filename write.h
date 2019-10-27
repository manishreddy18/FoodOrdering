

void take_input_from_admin(struct place location[],int No_of_locations)
{
  printf("----------take input from admin()-------started\n");
    char ch;
    int i,choice,temp,selected_location,selected_restaurant;
  //  NoRes.restaurants=0;
      FILE *fp;
      fp=fopen("price.txt","rb");
      if(fp == NULL)
              {
                     printf("\nCan't open file or file doesn't exist.");

              }
  //  fread(&NoRes,sizeof(struct NoOfRestaurants),1,fp);
    printf("Total Restaurants before writing restaurant to file %d\n",location[No_of_locations].No_of_restaurants);
     for(i=0;i<No_of_locations;i++)
    fread(&location[i],sizeof(struct place),No_of_locations+1,fp);
    DisplayLocation(location,No_of_locations);
    printf("select location\n");
    scanf("%d",&selected_location);

    printf("1.Add restaurant:\n2.Update Restaurant\nEnter ur choice:");
    scanf("%d",&choice);
  //  selected_location--;
    fflush(stdin);

     switch(choice)
     {
   case 1:
            selected_location--;
    printf("-----Adding Restaurant------\n");
    printf("Restaurant No:%d\n",location[selected_location].No_of_restaurants+1);
    do{
    fflush(stdin);
    printf("Res Name:");
    scanf("%[^\n]s",location[selected_location].restaurant[location[selected_location].No_of_restaurants].restaurant_name);
    fflush(stdin);
    printf("Rating:");
    scanf("%f",&location[selected_location].restaurant[location[selected_location].No_of_restaurants].rating);
    printf("No Of Items:");
    scanf("%d",&location[selected_location].restaurant[location[selected_location].No_of_restaurants].No_of_items);
    printf("Enter %d items:",location[selected_location].restaurant[location[selected_location].No_of_restaurants].No_of_items);
     fflush(stdin);
    for(int i=0;i<location[selected_location].restaurant[location[selected_location].No_of_restaurants].No_of_items;i++){
        scanf("%[^\n]s",location[selected_location].restaurant[location[selected_location].No_of_restaurants].items[i].item_name);
        fflush(stdin);
        printf("%s price:",location[selected_location].restaurant[location[selected_location].No_of_restaurants].items[i].item_name);
        scanf("%d",&location[selected_location].restaurant[location[selected_location].No_of_restaurants].items[i].item_price);
        fflush(stdin);
    }
    location[selected_location].No_of_restaurants++;
    printf("do u want to add restaurant?(y/n):");
        scanf("%c",&ch);

    }
    while(ch=='y');


       break;

   case 2:
        printf("---Updating Restaurant-----\n");
            selected_location--;
            DisplayRestaurants(location,selected_location);
        printf("\tSelect Restaurant to update Details\n");
        scanf("%d",&selected_restaurant);
        selected_restaurant--;
         fflush(stdin);
    printf("Res Name:");
    scanf("%[^\n]s",location[selected_location].restaurant[selected_restaurant].restaurant_name);
    fflush(stdin);
    printf("Rating:");
    scanf("%f",&location[selected_location].restaurant[selected_restaurant].rating);
    printf("No Of Items:");
    scanf("%d",&location[selected_location].restaurant[selected_restaurant].No_of_items);
    printf("Enter %d items:",location[selected_location].restaurant[selected_restaurant].No_of_items);
     fflush(stdin);
    for(int i=0;i<location[selected_location].restaurant[selected_restaurant].No_of_items;i++){
        scanf("%[^\n]s",location[selected_location].restaurant[selected_restaurant].items[i].item_name);
        fflush(stdin);
        printf("%s price:",location[selected_location].restaurant[selected_restaurant].items[i].item_name);
        scanf("%d",&location[selected_location].restaurant[selected_restaurant].items[i].item_price);
        fflush(stdin);
    }
         break;

   default:
        printf("Invalid Selection!!!!!\n");
     }



    write_data_to_file(location,No_of_locations);
    printf("----------take input from admin()-------ended\n");
    fclose(fp);
}
void write_data_to_file(struct place location[],int No_of_locations)
{
    printf("----------write data to file()--- %d locations-------started\n",No_of_locations);
    FILE *fp;
    fp=fopen("price.txt","wb+");
   // fseek(fp, 0, SEEK_SET);
      if(fp == NULL)
              {
                     printf("\nCan't open file or file doesn't exist.");

              }
   //fwrite(&NoRes,sizeof(struct NoOfRestaurants),1,fp);
   printf("No of locations %d\n",No_of_locations);
   printf("No of Restaurant added %d:\n",location[No_of_locations].No_of_restaurants);
    for(int i=0;i<No_of_locations;i++){
    fwrite(&location[i],sizeof(struct place),No_of_locations+1,fp);
    }
     printf("data written to file\n");
    fclose(fp);
printf("-----write data to file ------ended\n");
}
