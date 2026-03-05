#include "recommendation.h"

// pv คือ เลขที่ผู้ใช้เลือกจังหวัด
vector<place> Screening_provice(vector<place> &allplace, int pv){
    vector<place> province_accordingto_condition;
    string PV;
    if(pv == 1) PV = "Chiang Mai";
    if(pv == 2) PV = "Chiang Rai";
    if(pv == 3) PV = "Mae Hong Son";
    if(pv == 4) PV = "Lamphun";
    if(pv == 5) PV = "Lampang";
    if(pv == 6) PV = "Phayao";
    if(pv == 7) PV = "Phrae";
    if(pv == 8) PV = "Nan";
    if(pv == 9) PV = "Uttaradit";
    if(pv == 10) PV = "Tak";
    if(pv == 11) PV = "Sukhothai";
    if(pv == 12) PV = "Phitsanulok";
    if(pv == 12) PV = "Kamphaeng Phet";
    if(pv == 14) PV = "Phetchabun";
    if(pv == 15) PV = "Phichit";
    if(pv == 16) PV = "Nakhon Sawan";
    if(pv == 17) PV = "Uthai Thani";

    for(int i = 0; i < allplace.size(); i++){
        place p = allplace[i];
        if(PV == p.province[i]){
            province_accordingto_condition.push_back(allplace[i]);
        }
    }
    return province_accordingto_condition;
}

// ts คือ เลขที่ผู้ใช้เลือก type สถานที่
vector<place> Recommendation_place(vector<place> &pac, int ts ){
    vector<place> Place_accordingto_condition;
    string TS;
    if(ts == 1) TS = "Culture";
    if(ts == 2) TS = "Adventure";
    if(ts == 3) TS = "Natural";
    if(ts == 4) TS = "Photo";
    if(ts == 5) TS = "Cafe";

    for(int i = 0; i < pac.size(); i++){
        place p = pac[i];
        if(TS == p.type[i]){
            Place_accordingto_condition.push_back(pac[i]);
        }
    }
    return Place_accordingto_condition;
}


// โชว์สถานที่ ที่ตรงกับเงื่อนไข
void Show_Place(vector<place> &P){
    cout << "========================================" << endl;
    for(int i = 0; i < P.size(); i++){
        place p = P[i];
        cout << "Name of place " << "[" << i+1 << "] : " << p.name << endl;
        cout << "District : " << p.district << endl;
        cout << "Entrance Fee : " << p.price << endl;
        cout << "========================================" << endl;
    }
}
