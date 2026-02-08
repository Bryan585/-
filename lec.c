#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct car
{
    int carid;
    float hours;
    float price;
};
void price(struct car *c){
    if(c->hours<=3){
        c->price=2.0;
    }
    else if(c->hours>3 && c->hours<=24){
        c->price=2.0+0.5*(c->hours)-3;
        if (c->price < 10){
            c->price=2.0+0.5*(c->hours)-3;
        }
        else if(c->price >=10){
            c->price=10.0;
        }   
    }
    else{
        c->price=10.0;
    }
}
int main(){
    struct car cars[3];
    int i;
    int carid= 1;
    for (i=0;i<3;i++){
    printf("Enter stay hours:\n");
    scanf("%f",&cars[i].hours);
    cars[i].carid=carid;
    price(&cars[i]);
    carid++;
    }

    printf("\n%-10s %10s %10s\n", "Car", "Hours", "Charge");
    float thours=0, tprice=0;
    for(i=0;i<3;i++){
        printf("%-10d %10.1f %10.2f\n", cars[i].carid, cars[i].hours, cars[i].price);
        thours += cars[i].hours;
        tprice += cars[i].price;
    }
    printf("%-10s %10.1f %10.2f\n", "TOTAL", thours, tprice);
    return 0;
}