#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    int Flight_NOAr[10]={100,101,102,103,104,105,106,107,108,109};
    char sourceAr[10][10]={"Colombo","Colombo","Mattala","Colombo","Colombo","Colombo","Mattala","Mattala","Mattala","Colombo"};
    //char *destinationAr[]={"Thailand","Dubai","Singapore","London","Bangkok","Tokyo","Pris","Sydney","Indonesia","Canada"};
    char destinationAr[10][10]={"Thailand","Dubai","Singapore","London","Bangkok","Tokyo","Pris","Sydney","Indonesia","Canada"};
    int Av_seatsAr[]={25,10,18,12,20,15,8,6,22,14};
    float economy_priceAr[]={15000.00,45000.00,38000.00,95000.00,28000.00,72000.00,88000.00,99000.00,32000.00,41000.00};
    float businessClass_priceAr[]={300000.00,450000.00,300000.00,550000.00,600000.00,570000.00,420000.00,430000.00,540000.00,600000.00};
    float fristClass_priceAr[]={1200000.00,1100000.00,1400000.00,1800000.00,1250000.00,1760000.00,2000000.00,1650000,2200000.00,2400000.00};


    //user loging details :

    //char *userNAmeAr[]={"Mihiran"};
    //char *userPassword[]={"1002%m"};

    char userNAmeAr[1][10]={"Mihiran"};
    char userPassword[1][10]={"1002%m"};


    int size = sizeof(userNAmeAr) / sizeof(userNAmeAr[0]);

    /*
    char *tempUserNAmeAr[size + 1];
    char *tempUserPassword[size + 1];       */

    /*
    for(int i=0; i<size; i++){
        tempUserNAmeAr[i]=userNAmeAr[i];
        tempUserPassword[i]=userPassword[i];
    }
    userNAmeAr=tempUserNAmeAr;
    userPassword=tempUserPassword;  */



struct Flight {
    int flight_no;
    char source[20];
    char destination[20];
    int seats;
    float economy_price;
    float business_price;
    float firstClass_price;
};


void insertFlights() {
    FILE *fp;
    int i;



    struct Flight flights[10] = {
        {100, "Colombo", "Thailand", 25, 15000.00, 300000.00, 1200000.00},
        {101, "Colombo", "Dubai", 10, 45000.00, 450000.00, 1100000.00},
        {102, "Mattala", "Singapore", 18, 38000.00, 300000.00, 1400000.00},
        {103, "Colombo", "London", 12, 95000.00, 550000.00, 1800000.00},
        {104, "Colombo", "Bangkok", 20, 28000.00, 600000.00, 1250000.00},
        {105, "Colombo", "Tokyo", 15, 72000.00, 570000.00, 1760000.00},
        {106, "Mattala", "Paris", 8, 88000.00, 420000.00, 2000000.00},
        {107, "Mattala", "Sydey", 6, 99000.00, 430000.00, 1650000},
        {108, "Mattala", "Indonesia", 22, 32000.00, 540000.00, 2200000.00},
        {109, "Colombo", "Canada", 14, 41000.00, 600000.00, 2400000.00}
    };

    fp = fopen("flights.dat","wb");   // "wb" clear old data
    if (fp == NULL) {
        printf("File cannot be opened.\n");
        return;
    }

    for (i = 0; i < 10; i++) {
        fwrite(&flights[i], sizeof(struct Flight), 1, fp);
    }

    fclose(fp);

}
void displayFlights() {
    FILE *fp;
    struct Flight f;

    fp = fopen("flights.dat", "rb");

    printf("\n---------------------------------------------------------------------------------------------------------------\n");
    printf("%-10s %-14s %-16s %-20s %-15s %15s %15s\n",
           "Flight No", "Source", "Destination", "Available Seats", "Economy_Class", "Businesss_Class", "First_Class");
    printf("---------------------------------------------------------------------------------------------------------------\n");

    while (fread(&f, sizeof(f), 1, fp)) {
        if (f.seats > 0) {
            printf("%-10d %-14s %-16s %-25d %.2f %15.2f %15.2f\n",
                   f.flight_no,
                   f.source,
                   f.destination,
                   f.seats,
                   f.economy_price,
                   f.business_price,
                   f.firstClass_price);
        }
    }
    printf("---------------------------------------------------------------------------------------------------------------\n");

    fclose(fp);

}

void viewFlight(){

    printf("                             _ _       _     _        ______ _ _       _     _           \n");
    printf("              /\\            (_) |     | |   | |      |  ____| (_)     | |   | |          \n");
    printf("             /  \\__   ____ _ _| | __ _| |__ | | ___  | |__  | |_  __ _| |__ | |_ ___     \n");
    printf("            / /\\ \\ \\ / / _\' | | |/ _\' | \'_ \\| |/ _ \\ |  __| | | |/ _\' | \'_ \\| __/ __|    \n");
    printf("           / ____ \\ V / (_| | | | (_| | |_) | |  __/ | |    | | | (_| | | | | |_\\__ \\    \n");
    printf("          /_/    \\_\\_/ \\__,_|_|_|\\__,_|_.__/|_|\\___| |_|    |_|_|\\__, |_| |_|\\__|___/    \n");
    printf("                                                                  __/ |                  \n");
    printf("                                                                 |___/                   \n");

    printf("\n\n ");

}

void bookFlight(){
    printf("          ______ _ _       _     _     ____              _    _               \n");
    printf("         |  ____| (_)     | |   | |   |  _ \\            | |  (_)              \n");
    printf("         | |__  | |_  __ _| |__ | |_  | |_) | ___   ___ | | ___ _ __   __ _   \n");
    printf("         |  __| | | |/ _\' | \'_ \\| __| |  _ < / _ \\ / _ \\| |/ / | \'_ \\ / _\` |  \n");
    printf("         | |    | | | (_| | | | | |_  | |_) | (_) | (_) |   <| | | | | (_| |  \n");
    printf("         |_|    |_|_|\\__, |_| |_|\\__| |____/ \\___/ \\___/|_|\\_\\_|_| |_|\\__, |  \n");
    printf("                      __/ |                                            __/ |  \n");
    printf("                     |___/                                            |___/   \n");

    printf("\n\n");



    int No_Passanger,F_class,F_no;

    printf("   Enter Flight Number : ");
    scanf("%d",&F_no);

    int length = sizeof(Flight_NOAr) / sizeof(Flight_NOAr[0]);

    for(int i=0; i<length; i++){
        if(F_no==Flight_NOAr[i]){
            printf("\n");
            printf("   Departure City         : %s\n", sourceAr[i]);
            printf("   Destination City       : %s\n",destinationAr[i]);
            printf("   Available Seats        : %d\n",Av_seatsAr[i]);

        }
    }

    //



    printf("\n\n   Enter Number of Passengers   : ");
    scanf("%d",&No_Passanger);

    printf("   Choose Class               \n ");
    printf("   1.Economy, 2.Business, 3.First :");
    scanf("%d",&F_class);
    printf("\n\n");




}



void homePage(){


    /*
     L1:do{



        char option = getchar();
        if(option=='\n'){
            break;
        }else{
            printf("Try again......\n\n");
            //goto L1;
        }
    }while(1);   */

    printf("[1]. view Flights \n");
    printf("[2]. Book a Flight\n");
    printf("[3]. Cancel Booking \n");
    printf("[4]. Viwe My Booking \n");
    printf("[5]. Search Flight \n");
    printf("[6]. Exit \n\n");


    L2:do{
        printf("Enter an option to Continue -> ");
        int option1;
        scanf("%d",&option1);



        switch(option1){
        case 1:
            viewFlight();
            insertFlights();
            displayFlights();

            char option3;
            L3:do{
                printf("\n\nDo you want to go to home page (Y/N) :");
                scanf(" %c",&option3);
                if(option3=='Y' || option3=='y'){
                    homePage();
                    return;
                }else if(option3=='N' || option3=='n'){
                    return;
                }else{
                    printf("Try again..\n");
                    goto L3;
                }
            }while(1);
            return;
        case 2:

            bookFlight();

            char option4;

            L4:do{
                printf("Do you want to go to home page : ");
                scanf(" %c",&option4);
                if(option4=='Y' || option4=='y'){
                        printf("\n\n");
                    goto L2;
                }else if(option4=='N' || option4=='n'){
                    return;
                }else{
                    printf("Try again..");
                    goto L4;
                }
        }while(1);




            return;
        case 3:
            //cancelBooking();
            return;
        case 4:
            //viweMyBooking();
            return;
        case 5:
            //searchFlight();
            return;
        case 6:
            //Exit
            return;
        default:
            printf("Try again.. \n\n");
            goto L2;

        }
    }while(1);


}


int main()
{





    printf("                                                                  ________  __  __            __         __             \n");
    printf("                                                                 |        \\|  \\|  \\          |  \\       |  \\            \n");
    printf("                                                 ______          | $$$$$$$$| $$ \\$$  ______  | $$____  _| $$_           \n");
    printf("                                                /      \\  ______ | $$__    | $$|  \\ /      \\ | $$    \\|   $$ \\          \n");
    printf("                                               |  $$$$$$\\|      \| $$  \\    | $$| $$|  $$$$$$\\| $$$$$$$\\\\$$$$$$          \n");
    printf("                                               | $$    $$ \\$$$$$$| $$$$$   | $$| $$| $$  | $$| $$  | $$ | $$ __         \n");
    printf("                                               | $$$$$$$$        | $$      | $$| $$| $$__| $$| $$  | $$ | $$|  \\        \n");
    printf("                                                \\$$     \\        | $$      | $$| $$ \$$    $$ |$$   | $$  \\$$  $$        \n");
    printf("                                                 \\$$$$$$$         \\$$       \\$$ \\$$ _\\$$$$$$$ \\$$   \\$$   \\$$$$         \n");
    printf("                                                                                   |  \\__| $$                           \n");
    printf("                                                                                    \\$$    $$                           \n");
    printf("                                                                                     \\$$$$$$                            \n");

    printf("\n\n");

    printf("Plan your journey effortlessly with us! Our system stores all flight and passenger data safely, so your information is always preserved. Experience a fast, easy, and user-friendly way to manage\nyour air travel plans!\n\n");
    printf("Experience the joy of effortless travel planning at your fingertips.\nWith our system, booking a flight, managing your reservations, and checking seat availability is fast, simple, and reliable.Sit back, relax, and let us to handle your journey seamlessly — your next adventure is just a few clicks away!\n\n");



    printf("      +-------+                           \n");
    printf("Press | ENTER | Button to continue........\n");
    printf("      +-------+                           ");

     L1:do{
        char option = getchar();
        if(option=='\n'){
            break;
        }else{
            printf("Try again......\n\n");
            //goto L1;
        }
    }while(1);

    printf("\n\n");

    printf("+-------------------------------------------------+\n");
    printf("|                  LOGIN DETAILS                  |\n");
    printf("+-------------------------------------------------+\n");



    printf("Enter your name : ");
    char name[20];
    scanf("%s",&name);

    printf("Enter Password(Maximum 10 characters) : ");
    char password1[10];
    scanf("%s",&password1);

    L2:do{
        char password2[10];
        printf("Enter Password again : ");
        scanf("%s",&password2);


       // char *tempUserNAmeAr[size + 1];
        //char *tempUserPassword[size + 1];

        char *tempUserNAmeAr[size + 1][10];
        char *tempUserPassword[size + 1][10];


        if(strcmp(password1, password2) == 0){

            for(int i=0; i<size; i++){
                *tempUserNAmeAr[i][10]=userNAmeAr[i][10];
                *tempUserPassword[i][10]=userPassword[i][10];
            }
            userNAmeAr=tempUserNAmeAr;
            userPassword=tempUserPassword;

            userNAmeAr[size]=name;
            userPassword[size]=password2;



              printf("ssssss\n\n");

            //memcpy(userNAmeAr, tempUserNAmeAr, sizeof(tempUserNAmeAr));
            //memcpy(userPassword, tempUserPassword, sizeof(tempUserPassword));


            userNAmeAr[size]=name;
            userPassword[size]=password2;

            printf("ggggg");

           //break;

           homePage();




        }else{
            printf("NOT Mach\n\n");
            printf("Try again...\n");
            goto L2;

        }


    }while(1);




    //homePage();





    return 0;
}
