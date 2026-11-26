
#include <stdio.h>
#include <stdlib.h>

struct Book
{
    int id;
    char title[100];
    char author[100];
    int copies;
};

int main()
{
    struct Book b;
    FILE *fp, *temp;
    int choice, searchID, found, newCopies;

    do
    {
        printf("\n===== LIBRARY BOOK RECORD SYSTEM =====\n");
        printf("1. Add Book Records\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Update Available Copies\n");
        printf("5. Delete Book Record\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            // Add book records
            case 1:
                fp = fopen("books.dat", "ab");

                if(fp == NULL)
                {
                    printf("Error opening file!\n");
                    break;
                }

                int n;
                printf("Enter number of books: ");
                scanf("%d", &n);

                for(int i = 1; i <= n; i++)
                {
                    printf("\nEnter Book ID: ");
                    scanf("%d", &b.id);

                    printf("Enter Book Title: ");
                    scanf(" %99[^\n]", b.title);

                    printf("Enter Author Name: ");
                    scanf(" %99[^\n]", b.author);

                    printf("Enter Available Copies: ");
                    scanf("%d", &b.copies);

                    fwrite(&b, sizeof(b), 1, fp);
                }

                fclose(fp);
                printf("\nBooks added successfully!\n");
                break;

            // Display all books
            case 2:
                fp = fopen("books.dat", "rb");

                if(fp == NULL)
                {
                    printf("No book records found!\n");
                    break;
                }

                printf("\n===== ALL BOOK RECORDS =====\n");

                while(fread(&b, sizeof(b), 1, fp) == 1)
                {
                    printf("\nBook ID: %d\n", b.id);
                    printf("Title: %s\n", b.title);
                    printf("Author: %s\n", b.author);
                    printf("Available Copies: %d\n", b.copies);
                }

                fclose(fp);
                break;

            // Search book by ID
            case 3:
                fp = fopen("books.dat", "rb");

                if(fp == NULL)
                {
                    printf("File not found!\n");
                    break;
                }

                printf("Enter Book ID to search: ");
                scanf("%d", &searchID);

                found = 0;

                while(fread(&b, sizeof(b), 1, fp) == 1)
                {
                    if(b.id == searchID)
                    {
                        printf("\nBook Found!\n");
                        printf("Book ID: %d\n", b.id);
                        printf("Title: %s\n", b.title);
                        printf("Author: %s\n", b.author);
                        printf("Available Copies: %d\n", b.copies);

                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                    printf("Book ID not found!\n");

                fclose(fp);
                break;

            // Update available copies
            case 4:
                fp = fopen("books.dat", "rb+");

                if(fp == NULL)
                {
                    printf("File not found!\n");
                    break;
                }

                printf("Enter Book ID to update: ");
                scanf("%d", &searchID);

                found = 0;

                while(fread(&b, sizeof(b), 1, fp) == 1)
                {
                    if(b.id == searchID)
                    {
                        printf("Current Available Copies: %d\n", b.copies);

                        printf("Enter New Available Copies: ");
                        scanf("%d", &newCopies);

                        b.copies = newCopies;

                        fseek(fp, -(long)sizeof(b), SEEK_CUR);
                        fwrite(&b, sizeof(b), 1, fp);

                        found = 1;
                        printf("Book record updated successfully!\n");
                        break;
                    }
                }

                if(found == 0)
                    printf("Book ID not found!\n");

                fclose(fp);
                break;

            // Delete book record
            case 5:
                fp = fopen("books.dat", "rb");

                if(fp == NULL)
                {
                    printf("File not found!\n");
                    break;
                }

                temp = fopen("temp.dat", "wb");

                if(temp == NULL)
                {
                    printf("Error creating temporary file!\n");
                    fclose(fp);
                    break;
                }

                printf("Enter Book ID to delete: ");
                scanf("%d", &searchID);

                found = 0;

                while(fread(&b, sizeof(b), 1, fp) == 1)
                {
                    if(b.id == searchID)
                    {
                        found = 1;
                    }
                    else
                    {
                        fwrite(&b, sizeof(b), 1, temp);
                    }
                }

                fclose(fp);
                fclose(temp);

                if(found == 1)
                {
                    if(remove("books.dat") == 0 &&
                       rename("temp.dat", "books.dat") == 0)
                    {
                        printf("Book deleted successfully!\n");
                    }
                    else
                    {
                        printf("Error replacing book file!\n");
                    }
                }
                else
                {
                    remove("temp.dat");
                    printf("Book ID not found!\n");
                }

                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 6);

    return 0;
}
