#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef struct online{
    char cust_id[10];
    char name[100],item_name[100];
    char monthOfPurchase[10];
    int quantity,price,discount, total;
};
void findingMaxPurchase(online *o1,int l){
    int o2[12]= {0,0,0,0,0,0,0,0,0,0,0,0};
    char *o2_name0[100],*o2_name1[100],*o2_name2[100],*o2_name3[100];
    char *o2_name4[100],*o2_name5[100],*o2_name6[100],*o2_name7[100];
    char *o2_name8[100],*o2_name9[100],*o2_name10[100],*o2_name11[100];
    for(int i=0;i<l;i++){
        if(o1->monthOfPurchase == "Jan"){
            if(o2[0] < o1->total){
                o2[0] = o1->total;
                strcpy(*o2_name0,o1->item_name);
            }
        }
        else if(o1->monthOfPurchase == "Feb"){
            if(o2[1]< o1->total){
                    o2[1] = o1->total;
                *o2_name1 = o1->item_name;
            }
        }
        else if(o1->monthOfPurchase == "Mar"){
            if(o2[2]< o1->total){
                    o2[2] = o1->total;
                *o2_name2 = o1->item_name;
            }
        }
        else if(o1->monthOfPurchase == "Apr"){
            if(o2[3]< o1->total){
                    o2[3] = o1->total;
                *o2_name3 = o1->item_name;
            }
        }
        else if(o1->monthOfPurchase == "May"){
            if(o2[4]< o1->total){
                    o2[4] = o1->total;
                *o2_name4 = o1->item_name;
            }
        }
        else if(o1->monthOfPurchase == "Jun"){
            if(o2[5]< o1->total){
                    o2[5] = o1->total;
                *o2_name5 = o1->item_name;
            }
        }
        else if(o1->monthOfPurchase == "Jul"){
            if(o2[6]< o1->total){
                    o2[6] = o1->total;
                *o2_name6 = o1->item_name;
            }
        }
        else if(o1->monthOfPurchase == "Aug"){
            if(o2[7]< o1->total){
                    o2[7] = o1->total;
                *o2_name7 = o1->item_name;
            }
        }
        else if(o1->monthOfPurchase == "Sept"){
            if(o2[8]< o1->total){
                    o2[8] = o1->total;
                *o2_name8 = o1->item_name;
            }
        }
        else if(o1->monthOfPurchase == "Oct"){
            if(o2[9]< o1->total){
                    o2[9] = o1->total;
                *o2_name9 = o1->item_name;
            }
        }
        else if(o1->monthOfPurchase == "Nov"){
            if(o2[10]< o1->total){
                    o2[10] = o1->total;
                *o2_name10 = o1->item_name;
            }
        }
        else if(strcmp(o1->monthOfPurchase,"Dec")==0){
            if(o2[11]< o1->total){
                o2[11] = o1->total;
                strcpy(*o2_name11,o1->item_name);
            }
        }
        o1 = o1+1;
    }
    cout<<endl<<endl;
    fflush(stdout);
    for(int i=0;i<12;i++){
        switch(i){
            case 0:
                cout<<"The item name of max purchase in Jan month is"<<*o2_name0;
                break;
            case 1:
                cout<<"The item name of max purchase in Feb month is"<<*o2_name1;
                break;
            case 2:
                cout<<"The item name of max purchase in Mar month is"<<*o2_name2;
                break;
            case 3:
                cout<<"The item name of max purchase in Apr month is"<<*o2_name3;
                break;
            case 4:
                cout<<"The item name of max purchase in May month is"<<*o2_name4;
                break;
            case 5:
                cout<<"The item name of max purchase in Jun month is"<<*o2_name5;
                break;
            case 6:
                cout<<"The item name of max purchase in Jul month is"<<*o2_name6;
                break;
            case 7:
                cout<<"The item name of max purchase in Aug month is"<<*o2_name7;
                break;
            case 8:
                cout<<"The item name of max purchase in Sept month is"<<*o2_name8;
                break;
            case 9:
                cout<<"The item name of max purchase in Oct month is"<<*o2_name9;
                break;
            case 10:
                cout<<"The item name of max purchase in Nov month is"<<*o2_name10;
                break;
            case 11:
                cout<<"The item name of max purchase in Dec month is"<<*o2_name11;
                break;
        }
    }

}
void findTotal(online *o1,int l,int l1){
    for(int i=0;i<l;i++){
        o1->total = o1->price * o1->quantity;
        cout<<o1->total<<endl;
        o1 = o1+1;
    }
}
int main(){
    online o[10] ={ {"C0001","aalap","mouse","Dec",10,1100,0},
                    {"C0002","ishan","Books","Dec",6,500,0},
                    {"C0010","rishikesh","football","Jun",3,500,0},
                    {"C0109","rithiv","Pen","Jan",10,50,0},
                    {"C0098","ishita","Make-up","Feb",15,1000,5},
                    {"C0010","rishikesh","shoes","Jun",2,6000,10},
                    {"C0420","rakshit","phone","May",1,65000,15},
                    {"C0786","arupam","Laptop","Feb",1,75000,5},
                    {"C0056","rejath","Gaming control","Sept",2,2500,1},
                    {"C0879","sagar","headphones","Sept",1,4000,1}};

    int l = sizeof(o)/sizeof(o[0]);
    cout<<l<<endl;
    int l1 = sizeof(o[0]);
    findTotal(&o[0],l,l1);
    findingMaxPurchase(&o[0],l);
    return 0;
}
