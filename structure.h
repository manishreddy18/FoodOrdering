struct list_of_items
{
    char item_name[20];
    int item_price;
};
struct restaurant_details
{
    char restaurant_name[20];
    float rating;
    int No_of_items;
    struct list_of_items items[10];
};
struct place
{
    char Location_name[20];
    int No_of_restaurants;
    struct restaurant_details restaurant[30];
};
struct data
{
    int No_of_locations;
    struct place location[10];
};



