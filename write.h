#include<stdio.h>

void write_data_to_file(struct data restaurant[],struct NoOfRestaurants NoRes)
{

    char ch;
    int i,choice,temp;
  //  NoRes.restaurants=0;
      FILE *fp;
      fp=fopen("price.txt","rb");
      if(fp == NULL)
              {
                     printf("\nCan't open file or file doesn't exist.");

              }
    fread(&NoRes,sizeof(struct NoOfRestaurants),1,fp);
    printf("Total Restaurants before writing restaurant to file %d\n",NoRes.restaurants);
     for(i=0;i<NoRes.restaurants;i++)
    fread(&restaurant[i],sizeof(struct data),NoRes.restaurants+1,fp);
    printf("do u want to add restaurant?:");
    scanf("%c",&ch);
    if(ch=='y'){
    printf("Restaurant No:%d\n",NoRes.restaurants+1);
    do{
    fflush(stdin);
    printf("Res Name:");
    scanf("%[^\n]s",restaurant[NoRes.restaurants].restaurant_name);
    fflush(stdin);
    printf("Rating:");
    scanf("%f",&restaurant[NoRes.restaurants].rating);
    printf("No Of Items:");
    scanf("%d",&restaurant[NoRes.restaurants].No_of_items);
    printf("Enter %d items:",restaurant[NoRes.restaurants].No_of_items);
     fflush(stdin);
    for(int i=0;i<restaurant[NoRes.restaurants].No_of_items;i++){
        scanf("%[^\n]s",restaurant[NoRes.restaurants].items[i].item_name);
        printf("%s price:",restaurant[NoRes.restaurants].items[i].item_name);
        scanf("%d",&restaurant[NoRes.restaurants].items[i].item_price);
        fflush(stdin);
    }
    NoRes.restaurants++;
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
   fwrite(&NoRes,sizeof(struct NoOfRestaurants),1,fp);
   printf("No of Restaurant added %d:\n",NoRes.restaurants);
    for(int i=0;i<NoRes.restaurants;i++){
    fwrite(&restaurant[i],sizeof(struct data),NoRes.restaurants+1,fp);
    }
     printf("data written to file\n");
    fclose(fp);
}
