void getUserDetails(char *user_email)
{
    printf("enter your name: ");
    scanf("%s",user_email);
     return;
}
void DisplayRestaurants(int No_of_Restaurants,char restaurant[][50],float ratings[])
{
  for(int idx=0;idx<No_of_Restaurants;idx++)
  {
    printf("\t\t\t\t-------------------------------------------\n");
    printf("\t\t\t\t\t%d.%s\n",idx+1,restaurant[idx]);
    printf("\t\t\t\t\tRating:%.1f\n",ratings[idx]);
  //  printf("-------------------------------------------\n");
  }
  printf("\t\t\t\t-------------------------------------------\n");
     return;

}

int getSelectedRestaurant(int No_of_Restaurants)
{

    int selectedRestaurant;
    printf("\t\t\t\t\tSelect Restaurant:");
    scanf("%d",&selectedRestaurant);
    printf("\n");
    while(selectedRestaurant>No_of_Restaurants || selectedRestaurant <= 0 )
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
        return 0;
}
void printSelectedRestaurant(int selectedRestaurant,char restaurant[][50])
{
    printf("\t\t\t\t\t---%s---\n",restaurant[selectedRestaurant]);
}
void DisplayItems(int restaurantId,char items[][3][50])
{
   for(int idx=0;idx<3;idx++){
  printf("\t\t\t\t-----------------------------------------------------\n");

        printf("\t\t\t\t\t%d.%s\n",idx+1,items[restaurantId][idx]);
   }
   printf("\t\t\t\t----------------------------------------------------");

}
 int get_selected_item(int selected_restaurant,int No_of_items[])
 {
     int selected_item;
     printf("\t\t\t\t\tSelect Item:");
     scanf("%d",&selected_item);
     while(selected_item > No_of_items[selected_restaurant])
     {
         printf("\t\t\t\t\tInvalid Item Selection!!!\n");
         printf("\t\t\t\t\tSelect Item:");
         scanf("%d",&selected_item);
     }
     return selected_item-1;

 }
 void select_quantity(char items[][3][50],int selected_item,int selected_restaurant,int quantity[50][50])
 {
     printf("\t\t\t\t\tEnter quantity for %s:",items[selected_restaurant][selected_item]);
     scanf("%d",&quantity[selected_restaurant][selected_item]);
 }
 void DisplayOrderDetails(char restaurant[][50],int selected_restaurant,int selecteditem,char *email,char items[][3][50],int quantity[50][50])
 {
     printf("\t\t\t\t\t----ORDER DETAILS----\n");
     printf("\t\t\t\t\tName:%s\n",email);
     printf("\t\t\t\t\tRestaurant Name:%s\n",restaurant[selected_restaurant]);
     printf("\t\t\t\t\tItem selected:%s\n",items[selected_restaurant][selecteditem]);
     printf("\t\t\t\t\tQty %d",quantity[selected_restaurant][selecteditem]);
 }


