#include <stdio.h>
#include<string.h>
struct list_of_items
{
    int sno;
    char item_name[100];
    int quantity;
    int price;
}s[1000];//s=list_of_items struct variable
struct list_of_customers
{
    int id;
    char customer_name[100];
    char mno[100];//mobile number
    char address[1000];    
    struct bills *billing[100];     
    int billingcount;
}c[1000];//c=list_of_customers struct variable
int totalitems=0;//no of items available
int totalcustomers=0;//no of customers available
int billcount=0,bc=0;
struct bills
{
    int bill_no;
    char customer_name[100];
    char date[100];
    struct list_of_customers *cptr;
    char customer_no[100];
    int itemcount;
    int totalamt;
    int actualamt;
    struct data
    {
        int sno;
        char item[100];
        int quantity;
        int price;
        struct list_of_items *items;
        int cusprice;
    }d[100];//d to access list of items in bill
    
}b[1000];//b to access bill no
////////////   TO   INSERT   ITEMS   /////////////    OPTION-1
void insertitem()
{
    int itemcount,repeat,f=0,v=0;
    char t[100];
    printf("Enter no of items to be inserted");
    scanf("%d",&itemcount);
    v=totalitems;
    for(int i=totalitems+1;i<=itemcount+v;i++)
    {
        printf("Enter name of item");
        scanf("%s",t);
        for(int j=1;j<=totalitems;j++)
        {
            if(strcmp(t,s[j].item_name)==0)
            {
                f=j;
                break;
            }
        }
        if(f==0){
            totalitems=totalitems+1;
            s[i].sno=totalitems;
             strcpy(s[i].item_name,t);
            printf("Enter quantity of item");
            scanf("%d",&s[i].quantity);
            printf("Enter the price of product");
            scanf("%d",&s[i].price);
        }
        else
        {
            printf("Enter quantity of item");
            scanf("%d",&repeat);
            s[f].quantity=repeat+s[f].quantity;
            
        }
    }
    printf("%d items inserted in Itemlist........\n Total no of items in list is %d........",itemcount,totalitems);
}
////////////   TO   DISPLAY   ITEMS   /////////////   OPTION-6
void display_item_table()
{
    if(totalitems==0)
    {
        printf("No items found.............");
    }
    else{
        printf("\nSno   Item_name     quantity     price");
        for(int i=1;i<=totalitems;i++)
        {
            printf("\n%d     %s        %d           %d",s[i].sno,s[i].item_name,s[i].quantity,s[i].price);
        }
    }
}
////////////   TO   INSERT   CUSTOMERS   /////////////     OPTION-2
void insertcustomer()
{
    int customercount;
    printf("Enter no of items to be inserted");
    scanf("%d",&customercount);
    for(int i=1;i<=customercount;i++)
    {
        totalcustomers=totalcustomers+1;
        c[totalcustomers].id=totalcustomers;
        printf("\nEnter name of Customer");
        scanf("%s",c[totalcustomers].customer_name);
        printf("\nEnter mobile no of customer");
        scanf("%s",c[totalcustomers].mno);
        printf("\nEnter address of customer");
        scanf("%s",c[totalcustomers].address);
    }
    printf("%d customer inserted in Customerlist........\n Total no of customer in list is %d........",customercount,totalcustomers);
}
////////////   TO   DISPLAY   CUSTOMERS   /////////////    OPTION-7
void display_customer_table()
{
    if(totalcustomers==0)
    {
        printf("\nNo customers found.............");
    }
    else
    {
        printf("\nCustomer_ID   Customer_name    Mobile_no   Address");
        for(int i=1;i<=totalcustomers;i++)
        {
            printf("\n%d      %s        %s         %s",c[i].id,c[i].customer_name,c[i].mno,c[i].address);
        }
    }
}
//////////////////  ADD CUSTOMER   /////////////////// 
void add_customer(char no[100])
{
    totalcustomers=totalcustomers+1;
    c[totalcustomers].id=totalcustomers;
    printf("\nEnter name of Customer");
    scanf("%s",c[totalcustomers].customer_name);
    strcpy(c[totalcustomers].mno,no);
    printf("\nEnter address of customer");
    scanf("%s",c[totalcustomers].address);
}
///////////////  BILL  CREATION //////////     OPTION-3
void create_bill()
{
    int choice,t=0,cus_id;
    int tt=0,customerprice=0;
    char name[100],no[100];
    printf("\n Enter customer mobile no : ");
    scanf("%s",no);
    for(int i=1;i<=totalcustomers;i++)
    {
        if(strcmp(c[i].mno,no)!=0)
        {
            t=i;
        }
        else
        {
            cus_id=i;
            break;
        }
    }
    if(t==totalcustomers)
    {
        add_customer(no);
        cus_id=totalcustomers;
    }
    int n=1,count=0,totalprice=0,actualprice=0;
    do{
        display_item_table();
        printf("\nEnter Your choice : ");
        scanf("%d",&choice);
        //choice=choice;
        if(choice>totalitems&& choice<0){
            printf("\nEnter valid item from 1 to %d...... ",totalitems);
        }
        else{
        for(int i=1;i<=totalitems;i++)//for loop unnessary because to choice=i
        {
            if(s[i].sno==choice)
            {
                if(s[i].quantity>0)
                {
                    printf("Quantity Available : %d",s[i].quantity);
                    printf("\nEnter the quanlity");
                    scanf("%d",&count);
                    printf("\nEnter the sales price : ");;
                    scanf("%d",&customerprice);
                    if(count<=s[i].quantity)
                    {
                        billcount=billcount+1;
                        strcpy(b[bc].d[billcount].item,s[i].item_name);
                        b[bc].d[billcount].quantity=count;
                        s[i].quantity=s[i].quantity-count;
                        b[bc].d[billcount].price=s[i].price*count;
                        b[bc].d[billcount].cusprice=customerprice*count;
                        actualprice=actualprice+(s[i].price*count);
                        totalprice=totalprice+(customerprice*count);
                        b[bc].d[billcount].items = &s[i];
                        //strcpy(b[bc].customer_no,no);
                        break;
                    }
                    else
                    {
                        printf("\nSorry !! Entered Quantity not available");
                    }
                    
                }
                else
                {
                    printf("\nSorry!! Outof Stock");
                }
            }
        }
        }
       printf("Press 1 to continue purchasing items : ");
       scanf("%d",&n);
    }while(n==1);
    if(billcount>0){
        int cc=0,att=0;
        printf("\n Enter the date");
        scanf("%s",b[bc].date);
        b[bc].cptr= &c[cus_id];
        printf("\n____________________________________________________________________________________________\n");
        printf("\n Bill no:%d  MobileNo :  %s    ",bc,no);
        strcpy(b[bc].customer_no,no);
        for(int i=1;i<=billcount;i++)
        {
            if(strcmp(no,c[i].mno)==0)
            {
                printf("  Customer name : %s\t Date : %s",b[bc].cptr->customer_name,b[bc].date);
                strcpy(b[bc].customer_name,c[i].customer_name);
            }
        }
        printf("\n____________________________________________________________________________________________");
        printf("\n\nItem_name      Quantity        ActualPrice        SalePrice");
       for(int i=1;i<=billcount;i++)
       {
           printf("\n%s\t   \t %d \t \t   %d\t\t%d",b[bc].d[i].item,b[bc].d[i].quantity,b[bc].d[i].price,b[bc].d[i].cusprice);
           tt=tt+b[bc].d[i].price;
           att=att+b[bc].d[i].cusprice;
           cc=cc+1;
       }
       printf("\n____________________________________________________________________________________________\n");
       printf("\n\t\tTotal    :   %d\tInstead of %d",att,tt);
       b[bc].totalamt=tt;
       b[bc].actualamt=att;
       b[bc].itemcount=cc;
       cc=0;
       printf("\n____________________________________________________________________________________________");
       billcount=0;
    }
    else
    {
        printf("\n Sorry!!! Your cart found empty");
    }
    c[cus_id].billingcount=c[cus_id].billingcount+1;
    c[cus_id].billing[c[cus_id].billingcount] = &b[bc];
    b[bc].cptr=&c[cus_id];
    printf("\n%dcount:%d",cus_id,c[cus_id].billingcount);
    b[bc].bill_no=bc;
    bc++;
}
/////////////// ACCESSING PARTICULAR BILL //////   OPTION-6
void bill_access()
{
    int bill;
    printf("Enter bill no from 0 to %d :",bc-1);
    scanf("%d",&bill);
    int i=bill;
    if(bill>=0 && bill<bc){
    // for(int i=0;i<bc;i++)
    // {
                printf("\nCustomer name : %s \tCustomer no : %s",b[i].cptr->customer_name,b[i].cptr->mno);
                
                printf("\n\nItem_name\t\tQuantity\t\tActualPrice\t\tSalePrice");
                for(int j=1;j<=b[i].itemcount;j++)
                {
                    printf("\n%s\t\t%d\t\t%d\t\t%d",b[i].d[j].item,b[i].d[j].quantity,b[i].d[j].price,b[i].d[j].cusprice);
                }
                printf("\n\t  Total amount : %d\t\tActual Total amount : %d",b[i].actualamt,b[i].totalamt);
    // }
    }
    else
    {
        printf("\nEnter valid bill id.......");
    }
}
//////////////////// BILLING  DETAILS  ///////////////    OPTION-7
void bill_details()
{
    for(int i=0;i<bc;i++)
    {
       printf("\n____________________________________________________________________________________________");
        printf("\n\nBill no:%d\tCustomer name:%s\tCustomer no:%s\tDate:%s",i,b[i].customer_name,b[i].customer_no,b[i].date);
        printf("\n____________________________________________________________________________________________");
        printf("\n\nItem_name\t\tQuantity\t\tActualPrice\t\tSalePrice");
        for(int j=1;j<=b[i].itemcount;j++)
        {
            printf("\n%s\t\t%d\t\t%d\t\t%d",b[i].d[j].item,b[i].d[j].quantity,b[i].d[j].price,b[i].d[j].cusprice);
        }
        printf("\n\t  Total amount : %d\t\tActual Total amount : %d",b[i].actualamt,b[i].totalamt);

    }
}
//////////////// TOTAL AMOUNT BY THE CUSTOMER //////   OPTION-8
void cus_amt()
{
     char a[100],cusname[100];
     int amt=0,id,amt2=0;
    printf("\nEnter cumtomer mobile no : ");
    scanf("%s",a);
    for(int i=1;i<=totalcustomers;i++)
    {
        if(strcmp(c[i].mno,a)==0)
        {
            id=i;
            for(int j=1;j<=c[i].billingcount;j++)
            {
                printf("\n dj");
                amt=c[i].billing[j]->actualamt+amt;
                amt2=c[i].billing[j]->totalamt+amt2;
                printf("\n%dknk",amt);
            }
        }
    }
    printf("\n Customer name : %s",c[id].customer_name);
    printf("\n************************************************************************");
    printf("\n*\n*  \tTotal amount by the customer : %d Instead of %d\n*",amt,amt2);
    printf("\n************************************************************************");
}
/////////////// PARTICULAR BILLS OF CUSTOMER ////////  OPTION-9
void cus_bill()
{
    char a[100];
    printf("\nEnter cumtomer mobile no : ");
    scanf("%s",a);
    for(int i=1;i<=totalcustomers;i++)
    {
        if(strcmp(c[i].mno,a)==0)
        {
            for(int j=1;j<=c[i].billingcount;j++){
            printf("\n____________________________________________________________________________________________");
            printf("\nItem_name\t\tQuantity\t\tActual Price\t\tSalesPrice");
            printf("\n____________________________________________________________________________________________");
            for(int k=1;k<=c[i].billing[j]->itemcount;k++)
            {
                printf("\n%s\t\t%d\t\t%d\t\t%d",c[i].billing[j]->d[k].item,c[i].billing[j]->d[k].quantity,c[i].billing[j]->d[k].price,c[i].billing[j]->d[k].cusprice);
            }
            printf("\n\t Total amount : %d\tActual total amount : %d",c[i].billing[j]->actualamt,c[i].billing[j]->totalamt);
            }
        }
    }
}
int main()
{
    int n=1,choice;
    do{
        printf("\n1.Add items in list\n2.Display Itemslist\n3.Add customer in list\n4.Display Customer list\n5.Create bill/invoices\n6.Bill detail based on bill name\n7.Bill details\n8.Total amount by the Customer\n9.Specific customer bill\nEnter your choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insertitem();
                break;
            case 2:
                display_item_table();
                break;
            case 3:
                insertcustomer();
                break;
            case 4:
                display_customer_table();
                break;
            case 5:
                create_bill();
                break;
            case 6:    
                bill_access();
                break;
            case 7:
                bill_details();
                break;
            case 8:
                cus_amt();
                break;
            case 9:
                cus_bill();
                break;
            
        }
        printf("\n\nPress 1 to continue : ");
        scanf("%d",&n);
    }while(n==1);

    return 0;
}


