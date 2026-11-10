#include <stdio.h>

int main()
{
    char s[3][5] = {
        {'_','_','_','_','_'},
        {'_','_','_','_','_'},
        {'R','R','R','R','R'}
    };

    char a;
    int id = 100;

    while(1)
    {
        int ro, co;
        int n = 0;
        int r = 0;
        int pay;
        int amount1, amount2, totalamount;

        printf("\nWELCOME TO KMIT THEATER\n");
        printf("DO YOU WANT TO BOOK TICKET? (y/n)\n");
        scanf(" %c", &a);

        if(a == 'n')
        {
            printf("Thank you for visiting!\n");
            break;
        }

        if(a == 'y')
        {
            printf("\nR = Reserved Seat\n");
            printf("B = Booked Seat\n\n");

            printf("SEATING ARRANGEMENT\n");
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 5; j++)
                {
                    printf("%c ", s[i][j]);
                }
                printf("\n");
            }

            char name[30];

            printf("\nENTER YOUR NAME: ");
            scanf("%s", name);

            printf("YOUR ID IS %d\n", id);
            id++;

            printf("NO OF RESERVED TICKETS: ");
            scanf("%d", &r);

            printf("NO OF NON-RESERVED TICKETS: ");
            scanf("%d", &n);

            amount1 = n * 100;
            amount2 = r * 200;
            totalamount = amount1 + amount2;

            printf("TOTAL AMOUNT = %d\n", totalamount);

            printf("IF PAYMENT IS DONE ENTER 1: ");
            scanf("%d", &pay);

            if(pay == 1)
            {
                printf("\nPAYMENT SUCCESSFUL\n");

                /* Non-reserved tickets */
                if(n > 0)
                {
                    for(int i = 0; i < n; i++)
                    {
                        printf("\nTicket %d\n", i + 1);

                        printf("Enter row (0 or 1): ");
                        scanf("%d", &ro);

                        printf("Enter column (0 to 4): ");
                        scanf("%d", &co);

                        if(ro < 0 || ro > 1 || co < 0 || co > 4)
                        {
                            printf("Invalid seat!\n");
                            i--;
                            continue;
                        }

                        if(s[ro][co] != '_')
                        {
                            printf("Seat already booked or reserved!\n");
                            i--;
                        }
                        else
                        {
                            s[ro][co] = 'B';
                        }
                    }
                }

                /* Reserved tickets */
                if(r > 0)
                {
                    for(int i = 0; i < r; i++)
                    {
                        printf("\nReserved Ticket %d\n", i + 1);

                        printf("Enter reserved seat column (0 to 4): ");
                        scanf("%d", &co);

                        if(co < 0 || co > 4)
                        {
                            printf("Invalid column!\n");
                            i--;
                            continue;
                        }

                        if(s[2][co] == 'B')
                        {
                            printf("Seat already booked!\n");
                            i--;
                        }
                        else
                        {
                            s[2][co] = 'B';
                        }
                    }
                }

                printf("\nTICKETS BOOKED SUCCESSFULLY!\n");

                printf("\nUPDATED SEATING\n");
                for(int i = 0; i < 3; i++)
                {
                    for(int j = 0; j < 5; j++)
                    {
                        printf("%c ", s[i][j]);
                    }
                    printf("\n");
                }
            }
            else
            {
                printf("PAYMENT NOT DONE. BOOKING CANCELLED.\n");
            }
        }
        else
        {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
