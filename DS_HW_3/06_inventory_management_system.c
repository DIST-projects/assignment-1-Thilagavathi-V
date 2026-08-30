#include <stdio.h>

struct Product
{
    int id;
    char name[20];
    int quantity;
    float price;
};

int main()
{
    struct Product p[100];
    int n, i;
    float total;

    printf("Enter number of products: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of product %d\n", i + 1);

        printf("Product ID: ");
        scanf("%d", &p[i].id);

        printf("Product Name: ");
        scanf("%s", p[i].name);

        printf("Quantity: ");
        scanf("%d", &p[i].quantity);

        printf("Price: ");
        scanf("%f", &p[i].price);
    }

    printf("\n--- Inventory ---\n");

    for(i = 0; i < n; i++)
    {
        total = p[i].quantity * p[i].price;

        printf("\nID       : %d\n", p[i].id);
        printf("Name     : %s\n", p[i].name);
        printf("Quantity : %d\n", p[i].quantity);
        printf("Price    : %.2f\n", p[i].price);
        printf("Total    : %.2f\n", total);
    }

    return 0;
}