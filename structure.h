struct list_of_items
{
    char item_name[20];
    int item_price;
};
struct data
{
    char restaurant_name[20];
    float rating;
    int No_of_items;
    struct list_of_items items[10];
};
struct NoOfRestaurants
{
    int restaurants;
};
