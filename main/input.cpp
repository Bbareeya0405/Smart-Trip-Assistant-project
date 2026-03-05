#include<iostream>
#include<limits>
#include<string>
#include<sstream>
#include "input.h"


using namespace std;


void displayBanner(){

    cout << endl<<"===================================="<<endl;
    cout << endl<< "    SMART PLAN TRIP ASSITANT       "<<endl;
    cout << endl<<"===================================="<<endl;

}

void select_mode(){

    int select = 0; // 0 คือ สถานะยังไม่ได้เลือก
    string input = "";
    do {
        cout<<"[ 1 ] : Plan trip \n";
        cout<<"[ 2 ] : What to Eat Today ? \n";
        cout<<"[ 3 ] : Exit \n";
        cout<<"Select :  ";
        
        cin >> input;
        clearInputBuffer(); //ไม่มีก็ได้ แต่เผื่อเพิ่ม input ที่เป็น int

        if (input == "1") select = 1;
        else if (input == "2") select = 2;
        else if (input == "3") select = 3;
        else {
            Error();
            select = 0;
        }

        if(select != 1 && select != 2 && select != 3) Error();

        
    } while (select != 1 && select != 2 && select != 3);

    if(select == 1){
        //Feature 1 plan trip
        TravelPreference pref = getUserInput_1(); // [**1**]

    }else if(select == 2){
        //Feature 2 restaurant
        Restaurant rest = getUserInput_2(); // [**2**]

    }else if(select == 3){
        //exit
        
    }
}

// Enter 1 plan trip [**1**]
TravelPreference getUserInput_1(){

    TravelPreference pref;
    int day = 1;
    int place,type_trip,people,budget;
    int ts,pv; //input tripStyle , provice
    char again = 'n';

    cout<<"=====>>> Smart Trip Assistant <<<=====" << endl;
    cout<<"Please enter your travel information below.\n"<<endl;
    
    //1.long time กี่วัน
    pref.days = getValid_Integer("How many days will you be staying? :");
    day = pref.days;

    //2.ในแต่ละวันไปกี่ที่
    pref.num_place = getValid_Integer("How many places would you like to visit per day? :");
    place = pref.num_place;



    for(int i = 1 ; i < day+1 ; i++){
        cout<< "[ Day "<< i <<" ] "<<endl;
        line();
        //1.เลือกจังหวัด
        pref.province = getValid_Integer("Which province would you like to visit? : ");
        pv = pref.province;
        show_pv();//show output 17 provice
        
        //2.เลือกสไตล์
        pref.tripStyle = getValid_Integer("Preferred travel style :\n[ 1 ] Culture\n[ 2 ] Adventure\n[ 3 ] Natural\n[ 4 ] Photo\n[ 5 ] Cafe\nEnter 1-5 : ");
        ts =  pref.tripStyle;
        show_place(); //show all data place
    }
    
    //3.งบประมาณ เลือก 1.บอก 2.ให้โปรแกรมคิดให้
    pref.budget = getValid_Integer("How much to Budget : [Enter 0 if you not ]");
    budget = pref.budget;

    //4.ไปกี่คน
    pref.people  = getValid_Integer("Number of people : ");
    people = pref.people;

    return pref;
}

// Enter 2 Feature food
Restaurant getUserInput_2(){
    Restaurant rest;
    int ctm , ctgr ,btf , ml;

    cout<<"========== Restaurant ==========";
    
    //ถามจำนวนคน
    rest.customer = getValid_Integer("How many people are dining ? : ");
    ctm = rest.customer;
    

    for (int i = 0; i < ctm; i++){
        cout<<"People[ "<<i+1<<" ]"<<endl;
        Person p;
        
        p.meals = getValid_Integer("How many meals would you like ?\nEnter number: ");
        ml = p.meals;

        for(int j = 0 ; j < ml ; j ++){
            Meal m;

            cout<<"Meals[ "<<j+1<<" ]"<<endl;
            //เลือกเส้น หรือ ข้าว
            m.category = getValid_Integer("Select your preferred dish type:\n1. Noodles\n2. Rice\n3. Surprise me\nEnter your choice (1-3): ");
            ctgr = m.category;

            if(ctgr == 3){
                //random
                break;
            }
        }
    }

}



//เคลียร์
void clearInputBuffer(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');//reset error state ลบทุกอย่างจนกว่าจะเจอ newline
}

int getValid_Integer(const string &prompt){
    int value;

    while(1){
        cout << prompt;
        //check ว่าเป็น Number มั้ย
        if(cin >> value && value > 0){
            clearInputBuffer(); //ล้างสิ่งที่ผู้ใช้ป้อนค้างไว้ใน Buffer
            return value;
        }
        cout << "Error : Please enter a valid number or number more than zero. \n" ;
        clearInputBuffer(); //clear for next input
    }
}

// input type Yes/No แปลงเป็น Boolean
bool getYes_No_Input(const string &prompt){
    string input_YN;

    while(1){
        cout << prompt << "[Yes / No] : ";
        getline(cin,input_YN);

        for(char &text : input_YN){
            text = toupper(text);
        }
        
        if(input_YN == "YES" || input_YN == "Y"){
            return true;
        }else if(input_YN == "NO" || input_YN == "N"){
            return false;
        }else {
            cout << "Error: Please enter 'yes' or 'no'.\n";
        }
    }

}

//input type string
string getString_Input(const string& prompt){
    string str;

    while(1){
        cout << prompt;
        getline(cin,str);
        line(); //เส้นกั้น

        if(!str.empty()) return str;
        else cout << "Error : Input can't be empty"<<endl;

    }
}

// Error message helper
void Error(){
    cout<<"Error: Invalid input. Please try again."<<endl;
}

void line(){
    cout<<"---------------------------------"<<endl;
}

// check whether string is a number
bool Check_number(const string & str){
    int number;
    istringstream iss(str);
    iss >> number;
    return iss.eof() && !iss.fail();
}

//โขว์ข้อมูลจังงหวัด
void show_pv(){
    cout << "[ 1 ] Chiang Mai" << endl;
    cout << "[ 2 ] Chiang Rai" << endl;
    cout << "[ 3 ] Mae Hong Son" << endl;
    cout << "[ 4 ] Lamphun" << endl;
    cout << "[ 5 ] Lampang" << endl;
    cout << "[ 6 ] Phayao" << endl;
    cout << "[ 7 ] Phrae" << endl;
    cout << "[ 8 ] Nan" << endl;
    cout << "[ 9 ] Uttaradit" << endl;
    cout << "[ 10 ] Tak" << endl;
    cout << "[ 11 ] Sukhothai" << endl;
    cout << "[ 12 ] Phitsanulok" << endl;
    cout << "[ 13 ] Kamphaeng Phet" << endl;
    cout << "[ 14 ] Phetchabun" << endl;
    cout << "[ 15 ] Phichit" << endl;
    cout << "[ 16 ] Nakhon Sawan" << endl;
    cout << "[ 17 ] Uthai Thani" << endl;
}
