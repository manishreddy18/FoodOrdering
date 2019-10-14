
void getUserDetails(char *user_email)
{
    printf("\t\t\t\t\tEnter your name: ");
    scanf("%s",user_email);
     return;
}
void DisplayRestaurants(struct data *restaurant,struct NoOfRestaurants *NoRes)
{
    system("cls");
   printf("\t\t\t\t--------Displaying Restaurants-----------\n");
  for(int idx=0;idx<NoRes->restaurants;idx++)
  {
    printf("\t\t\t\t-------------------------------------------\n");
    printf("\t\t\t\t\t%d.%s\n",idx+1,restaurant->restaurant_name);
    printf("\t\t\t\t\tRating:%.1f\n",restaurant->rating);
    restaurant++;
  //  printf("-------------------------------------------\n");
  }
  printf("\t\t\t\t-------------------------------------------\n");
     return;

}

int getSelectedRestaurant(struct NoOfRestaurants NoRes)
{

    int selectedRestaurant;
    printf("\t\t\t\t\tSelect Restaurant:");
    scanf("%d",&selectedRestaurant);
    while(selectedRestaurant>NoRes.restaurants || selectedRestaurant <= 0 )
    {

        printf("\t\t\t\t\tInvalid Selecetion...!!!!\n");
         printf("\t\t\t\t\tSelect Restaurant:");
        scanf("%d",&selectedRestaurant);

    }
    return selectedRestaurant-1;

}
int changeRestaurant()
{
    char choice;
    printf("\n\t\t\t\tDo u want to change Restaurant(Y/N): ");
    scanf("%c",&choice);
    if(choice=='Y' || choice=='y')
        return 1;
    else
        if(choice=='N' || choice=='n')
        return 0;
}
void printSelectedRestaurant(int selectedRestaurant,struct data restaurant[])
{
    printf("\t\t\t\t\t---%s---\n",restaurant[selectedRestaurant].restaurant_name);
}
void DisplayItems(int restaurantId,struct data restaurant[],struct NoOfRestaurants NoRes)
{
   for(int idx=0;idx<restaurant[restaurantId].No_of_items;idx++){
  printf("\t\t\t\t-----------------------------------------------------\n");

        printf("\t\t\t\t\t%d.%s\n",idx+1,restaurant[restaurantId].items[idx].item_name);
        printf("\t\t\t\t\tRs.%d\n",restaurant[restaurantId].items[idx].item_price);
   }
   printf("\t\t\t\t----------------------------------------------------\n");

}
 int get_selected_item(int selected_restaurant,struct data restaurant[],struct NoOfRestaurants NoRes)
 {
     int selected_item;
     printf("\t\t\t\t\tSelect Item:");
     scanf("%d",&selected_item);
     while(selected_item > restaurant[selected_restaurant].No_of_items || selected_item < 0)
     {
         printf("\t\t\t\t\tInvalid Item Selection!!!\n");
         printf("\t\t\t\t\tSelect Item:");
         scanf("%d",&selected_item);
     }
     return selected_item-1;

 }
 int select_quantity(struct data restaurant[],int selected_item,int selected_restaurant,int quantity)
 {
     printf("\t\t\t\t\tEnter quantity for %s:",restaurant[selected_restaurant].items[selected_item].item_name);
     scanf("%d",&quantity);
     while(quantity<=0)
     {
         printf("\t\t\t\t\tInvalid Quantity selection!!!\n");
         printf("\t\t\t\t\tEnter quantity for %s:",restaurant[selected_restaurant].items[selected_item].item_name);
         scanf("%d",&quantity);
     }
     return quantity;
 }
 int Order()
 {
     fflush(stdin);
     char choice;
     printf("\n\t\t\t\t\tDo u want to order anything else(Y/N):");
     scanf("%c",&choice);
     if(choice=='y' || choice=='Y')
        return 1;
     else
        return 0;
 }
 void DisplayOrderDetails(struct data restaurant[],int selected_restaurant,int selecteditem,char *email,int quantity)
 {
      printf("\n\t\t\t\t\tOrder Success :)\n");
     printf("\t\t\t\t\t----ORDER DETAILS----\n");
     printf("\t\t\t\t\tName:%s\n",email);
     printf("\t\t\t\t\tRestaurant Name:%s\n",restaurant[selected_restaurant].restaurant_name);
     printf("\t\t\t\t\tItem selected:%s\n",restaurant[selected_restaurant].items[selecteditem].item_name);
     printf("\t\t\t\t\tQty %d\n",quantity);
     printf("\t\t\t\t\tPrice:%d",quantity*restaurant[selected_restaurant].items[selecteditem].item_price);
 }


