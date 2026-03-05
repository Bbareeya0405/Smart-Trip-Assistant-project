#include "calculation.h"

// รวมค่าสถานที่
int calculatePlaceCost(vector<Place> places) {
    int total = 0;

    for (int i = 0; i < places.size(); i++) {
        total += places[i].price;
    }

    return total;
}

// รวมค่าอาหาร
int calculateRestaurantCost(vector<restaurant> foods) {
    int total = 0;

    for (int i = 0; i < foods.size(); i++) {
        total += foods[i].price;
    }

    return total;
}

// ค่าใช้จ่ายรวมทั้งหมด
int calculateTotalCost(vector<Place> places, vector<restaurant> foods) {

    int placeCost = calculatePlaceCost(places);
    int foodCost = calculateRestaurantCost(foods);

    int totalCost = placeCost + foodCost;

    return totalCost;
}

// ค่าใช้จ่ายต่อคน
double calculateCostPerPerson(int totalCost, int people) {

    if (people == 0) return 0;

    return (double)totalCost / people;
}

// ค่าใช้จ่ายต่อวัน
double calculateCostPerDay(int totalCost, int days) {

    if (days == 0) return 0;

    return (double)totalCost / days;
}

// เช็คงบประมาณ
bool isWithinBudget(int totalCost, int budget) {

    if (budget == 0) return true; // ผู้ใช้ไม่ได้กำหนดงบ

    return totalCost <= budget;
}

// งบคงเหลือ
int calculateRemainingBudget(int budget, int totalCost) {

    if (budget == 0) return 0;

    return budget - totalCost;
}