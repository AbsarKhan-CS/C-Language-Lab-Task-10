
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char item[100], location[100], contact[50];
    char searchItem[100];
    char fileItem[100], fileLocation[100], fileContact[50];
    int n, i, found = 0;

    // Open file in append mode
    fp = fopen("lostfound.txt", "a");

    if (fp == NULL)
    {
        printf("Error opening file!");
        return 1;
    }

    printf("Enter number of records to add: ");
    scanf("%d", &n);
    getchar();

    // Add new records
    for (i = 1; i <= n; i++)
    {
        printf("\nEnter item name: ");
        fgets(item, sizeof(item), stdin);
        item[strcspn(item, "\n")] = '\0';

        printf("Enter location: ");
        fgets(location, sizeof(location), stdin);
        location[strcspn(location, "\n")] = '\0';

        printf("Enter student contact ID: ");
        fgets(contact, sizeof(contact), stdin);
        contact[strcspn(contact, "\n")] = '\0';

        fprintf(fp, "%s|%s|%s\n",
                item, location, contact);
    }

    // Close file after writing
    fclose(fp);

    // Open file for reading
    fp = fopen("lostfound.txt", "r");

    if (fp == NULL)
    {
        printf("Error reading file!");
        return 1;
    }

    // Display all records
    printf("\n--- All Lost and Found Records ---\n");

    while (fscanf(fp, "%99[^|]|%99[^|]|%49[^\n]\n",
                  fileItem, fileLocation, fileContact) == 3)
    {
        printf("\nItem Name: %s\n", fileItem);
        printf("Location: %s\n", fileLocation);
        printf("Contact ID: %s\n", fileContact);
    }

    fclose(fp);

    // Search for an item
    printf("\nEnter item name to search: ");
    fgets(searchItem, sizeof(searchItem), stdin);
    searchItem[strcspn(searchItem, "\n")] = '\0';

    fp = fopen("lostfound.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file for searching!");
        return 1;
    }

    found = 0;

    while (fscanf(fp, "%99[^|]|%99[^|]|%49[^\n]\n",
                  fileItem, fileLocation, fileContact) == 3)
    {
        if (strcmp(searchItem, fileItem) == 0)
        {
            printf("\n--- Record Found ---\n");
            printf("Item Name: %s\n", fileItem);
            printf("Location: %s\n", fileLocation);
            printf("Contact ID: %s\n", fileContact);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nNo matching record found!\n");
    }

    // Close file after searching
    fclose(fp);

    return 0;
}
