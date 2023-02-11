#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>
using namespace std;

typedef struct{
    string foodname;
    int stock;
    double cost;
} Food;

typedef struct{
    string username;
    string foodname;
    int quantity;
    double total_cost;
} User;

vector<User> user_data;

vector<Food> food_data;

bool open_store = false;

string myname;

vector<Food> getfooddata(){
    vector<Food> FoodData;
    ifstream FoodFile("../src/data/food.csv");
    string line;
    while(getline(FoodFile, line)){
        stringstream lineStream(line);
        string cell;
        vector<string> cells;
        while(getline(lineStream, cell, ',')){
            cells.push_back(cell);
        }
        Food food;
        food.foodname = cells[0];
        food.stock = stoi(cells[1]);
        food.cost = stod(cells[2]);
        FoodData.push_back(food);
    }   
    return FoodData; 
}

void printfooddata(vector<Food> data){
    int i= 1;
    for(const auto &row: data){
        cout << i++ << ". Food name = " << row.foodname << endl;
        cout << "\tFood stock = " << row.stock << endl;
        cout << "\tFood cost = " << row.cost << endl;
    }
}

vector<User> getuserdata(){
    vector<User> UserData;
    ifstream UserFile("data/user.csv");
    string line;
    while(getline(UserFile, line)){
        stringstream lineStream(line);
        string cell;
        vector<string> cells;
        while(getline(lineStream, cell, ',')){
            cells.push_back(cell);
        }
        User user;
        user.username = cells[0];
        user.foodname = cells[1];
        try {
            user.quantity = stoi(cells[2]);
        } catch (const std::invalid_argument& ia) {
            std::cout << "Invalid argument: " << ia.what() << '\n';
        }
        try {
            user.total_cost = stod(cells[3]);
        } catch (const std::invalid_argument& ia) {
            std::cout << "Invalid argument: " << ia.what() << '\n';
        }
    }   
    return UserData; 
}

void printuserdata(vector<User> data){
    if(data.size() == 0){
        cout << "Tidak Ada Penjualan." << endl;
    }else{
        int i= 1;
        for(const auto &row: data){
            cout << i++ << ". User name = " << row.username << endl;
            cout << "\tFood name = " << row.foodname << endl;
            cout << "\tFood quantity = " << row.quantity << endl;
            cout << "\tTotal cost = " << row.quantity << endl;
        }
    }
}

void reset_data_user(){
    ofstream file("../src/data/user.csv", ios::trunc);
    if (!file) {
        cerr << "Failed to open file for writing." << endl;
    }
    file.close();
    cout << "File successfully truncated." << endl;
}

void reset_food_data(){
    for (auto &row: food_data){
        if(row.stock != 5){
            row.stock = 5;
        }
    }
}

void printtocsv(){
    ofstream UserFile("../src/data/user.csv");
    UserFile << "name,foodname,quantity,totalcost" << endl;
    for(const auto &row : user_data){
        UserFile << row.username << "," << row.foodname << "," << row.quantity << "," << row.total_cost << std::endl;
    }
    UserFile.close();
}

void printtocsvfood(){
    ofstream FoodFile("../src/data/food.csv");
    for(const auto &row : food_data){
        FoodFile << row.foodname << "," << row.stock << "," << row.cost << std::endl;
    }
    FoodFile.close();
}

void homepage();

void developer_mode();

void developer_choice(){
    cout << "Please choose the number below" << endl;
    cout << "1. Open the store" << endl;
    cout << "2. Close the store" << endl;
    cout << "3. Exit developer mode" << endl;
    cout << "4. Restock" << endl;
    int choice;
    cout << "Your Choice : ";
    cin >> choice;
    if(choice == 1){
        reset_data_user();
        cout << "The data has been set and the store has open." << endl << "Customer now can enter the store!";
        cout << endl << "What we gonna do again, sir?" << endl;
        open_store = true;
        developer_choice();
    }else if(choice == 2){
        cout << "Here is your transcript sir?" << endl << "Please save it before openning the store again!" << endl;
        printuserdata(user_data);
        printtocsv();
        printtocsvfood();
        open_store = false;
        exit(0);
    }else if(choice == 3){
        cout << "U're out from developer mode" << endl;
        cout << "Please input your name again!" << endl;
        homepage();
    }else if(choice == 4){
        cout << "All stock will be restock!" << endl;
        reset_food_data();  
        cout << endl << "What we gonna do again, sir?" << endl;
        developer_choice(); 
    }else{
        cout << "Your choice is not included, Please try it again!";
        developer_mode();
    }
}

void developer_mode(){
    cout << "Welcome sir! ^ ^" << endl << "How was your day?" << endl << "I hope you are good! ^ ^" << endl;
    cout << "What we gonna do today, sir?" << endl;
    developer_choice();
}

void user_choice();

void choose_quantity(string foodname){
    for(int i= 0; i< food_data.size(); i++){
        if(food_data[i].foodname == foodname){
            int quantity;
            cout << "This food last " << food_data[i].stock << endl;
            cout << "Please print your quantity : ";
            cin >> quantity;
            if(quantity <= food_data[i].stock){
                int user_data_size = user_data.size();
                User data;
                data.username = myname;
                data.foodname = foodname;
                data.quantity = quantity;
                data.total_cost = quantity * food_data[i].cost;
                food_data[i].stock -= quantity;
                user_data.push_back(data);
            }else{
                cout << "The stock is not enough" << endl;
                user_choice();
            }
            break;
        }
    }
}

void buy_food();

void after_buy_choice(){
    cout << "Do you want to buy more?" << endl << "Please Type Yes or No : ";
    string choice;
    cin >> choice;
    if (choice == "Yes" || choice == "yes"){
        user_choice();
    }else{
        cout << "You will exit and please input your name again" << endl;
        homepage();
    }
}

void buy_food(){
    cout << "Which food do you want to buy" << endl << "Please include the name of the food : ";
    string foodname;
    cin >> foodname;
    bool found= false;
    for(int i= 0; i< food_data.size(); i++){
        cout << food_data[i].foodname;
        if(food_data[i].foodname == foodname){
            found = true;
            choose_quantity(foodname);
            break;
        }
    }
    if(!found){
        cout << "There isn't have that food, Please input again!" << endl;
        buy_food();
    }
    after_buy_choice();
}

void user_choice(){
    cout << "1. Menu" << endl << "2. Buy food" << endl;
    cout << "3. Exit" << endl;
    cout << "Input the number!" << endl;
    cout << "Choice : ";
    int choice;
    cin >> choice;
    if(choice == 1){
        printfooddata(food_data);
        user_choice();
    }else if(choice == 2){
        buy_food();
    }else if (choice == 3){
        cout << "You will exit and please input your name again" << endl;
        homepage();
    }else{
        cout << "Your choice is wrong please input again!" << endl;
        user_choice();
    }
}

void user_mode(){
    cout << "Welcome to food store" << endl;
    cout << "What do you want from us" << endl;
    user_choice();
}

void homepage(){
    printf(
"           ___,\n"
"          '._.'\\\n"
"       _____/'-.\\\n"
"      |    / |\n"
"      |~~~/~~|\n"
"      \\ ()   /\n"
"       '.__.'\n"
"         ||\n"
"        _||_\n"
"       `----`\n"
"___________               .___ ________          __  .__          __   \n"
"\\_   _____/___   ____   __| _/ \\_____  \\  __ ___/  |_|  |   _____/  |_ \n"
" |    __)/  _ \\ /  _ \\ / __ |   /   |   \\|  |  \\   __\\  | _/ __ \\   __\\\n"
" |     \\(  <_> |  <_> ) /_/ |  /    |    \\  |  /|  | |  |_\\  ___/|  | \n" 
" \\___  / \\____/ \\____/\\____ |  \\_______  /____/ |__| |____/\\___  >__| \n\n" 
"     \\/                    \\/          \\/                      \\/ \n"    
    );
    cout << "Please Enter Your Name : ";
    cin >> myname;
    if (myname == "Pemilik" || myname == "pemilik"){
        developer_mode();
    }else{
        if(open_store){
            user_mode();
        }else{
            cout << "The store isn't available yet!" << endl << "Please wait for the owner!" << endl;
            homepage();
        }
    }
}

int main(){
    system("cls");
    food_data = getfooddata();
    homepage();
}