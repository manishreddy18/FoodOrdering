int initialise_location(struct place location[],int No_of_locations)
{
  printf("-------initialise location()-----started\n");
    char ch;

    do{
    fflush(stdin);
    printf("Enter Location %d :\n",No_of_locations);
    scanf("%[^\n]s",location[No_of_locations].Location_name);
  //  loc[*No_of_locations].No_of_restaurants=0;
    fflush(stdin);
    read_data_from_file(location,No_of_locations);
    take_input_from_admin(location,No_of_locations);
   // write_data_to_file(location,No_of_locations);
    read_data_from_file(location,No_of_locations);
    fflush(stdin);
    printf("Do you want to add location...??\n");
    scanf("%c",&ch);
        if(ch=='y')
        No_of_locations++;
    }
    while(ch=='y');
    No_of_locations++;
    printf("Returing No of locations %d\n",No_of_locations);
    return No_of_locations;
   printf("-----------initialise location()----------ended\n");
}
