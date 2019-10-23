int initialise_location(struct data details[])
{
  printf("-----------initialise_location()----------\n");
    FILE *fp;
    char ch;
     fp=fopen("price.txt","wb+");
    do{
    fflush(stdin);
    printf("Enter Location %d :\n",details[0].No_of_locations+1);
    scanf("%[^\n]s",details[0].location[details[0].No_of_locations].Location_name);
  //  loc[*No_of_locations].No_of_restaurants=0;
     fwrite(&details,sizeof(struct data),10,fp);
    printf("Location scanned:%s\n",details[0].location[details[0].No_of_locations].Location_name);
     fclose(fp);
    fflush(stdin);
    write_data_to_file(details);
    read_data_from_file(details);
    fflush(stdin);
    printf("Do you want to add location...??\n");
    scanf("%c",&ch);
     (details[0].No_of_locations)++;
    }
    while(ch=='y');

    fp=fopen("price.txt","wb+");
     fwrite(&details,sizeof(struct data),10,fp);
     fclose(fp);
    printf("Returing No of locations %d\n",details[0].No_of_locations);
    return details[0].No_of_locations;
}
