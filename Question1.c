#include <stdio.h>
int main()
{
    FILE *fptr;
    char description[100];
    float amount;
    int n,i;

    fptr = fopen("expenses.txt","w");
    
    if(fptr == NULL)
    {
        printf("Error opening File!");
        return 1;

    }
    printf("Enter number of expenses: \n");
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        printf("\nEnter expense description: ");
        scanf(" %[^\n]", description);

        printf("Enter expense amount: ");
        scanf("%f", &amount);

        fprintf(fptr, "%s - Rs. %.2f\n", description, amount);
    }
    fclose(fptr);

    fptr = fopen("expenses.txt", "r");

    if(fptr == NULL)
    {
        printf("Error opening file!");
        return 1;

    }
    printf("\n--- Saved Expenses ---\n");

    while(fgets(description,sizeof(description), fptr)!= NULL){
        printf("%s",description);
    }
    fclose(fptr);

    return 0;
}