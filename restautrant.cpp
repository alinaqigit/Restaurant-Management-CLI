#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <conio.h>

using namespace std;


struct Order {
    string itemName;
    int price;
};

void panel();

string tokenizer(int column, string s);
string fetchData(int row);
bool auth(int row, string &name);
bool login();                                  
void order();



int main() {
    while (true)
    {   
        if(login()){
            panel();
            break;
        }
    }
    return 0;
}


void panel(){
    string choice;
    bool again = true;
    do {
        cout << "\nMain Menu:\n";
        cout << "1. Take Order\n";
        cout << "2. Check Orders\n";
        cout << "3. Logout\n";
        cout << "Enter your choice: ";
        getline(cin ,choice);
        system("CLS");
        if((choice.compare("1") && choice.compare("2") && choice.compare("3"))){
            cout << "Invalid Input!";
            continue;
        }
        else if(stoi(choice) == 1)
        {
            order();
        }
        else if(!choice.compare("2")){
            string line;
            ifstream logs("logs.csv");

            while (getline(logs, line))
            {
                cout << line;
                cout << "\n";
            }
                cout << "Enter any key to continue";
                getch();
                system("CLS");
            
        }
        else if(stoi(choice) == 3)
            again = false;
    } while (again);
}

string tokenizer(int column, string s)
{
    char del = ',';
    stringstream ss(s);
    string word;
    for (int i = 0; i < column; i++) 
        getline(ss, word, del);
    return word;
}

string fetchData(int row){
    string data;
    ifstream database("loginDatabase.csv");
    if (database.is_open())
    {
        for (char i =0; i < row; i++)
        {
            getline(database, data);
        }
    }else   cout << "Failed to load database!";
    database.close();
    return data;
}

bool auth(int row, string &name){
    bool status = 0;
    while (true)
    {
        string enteredUserName, actualUserName;
        string data = fetchData(row);
        actualUserName = tokenizer(2, data);
        cout << "Enter your username(0 to go back):";
        getline(cin, enteredUserName);
        system("CLS");
        if(!enteredUserName.compare("0")){
            break;
        }
        else{
            if(actualUserName.compare(enteredUserName)){
                cout << "No such user with this username!" << endl << "Please try again!" << endl;
                continue;
            }
            else
            {
                while(true){
                    string enteredPin;
                    string actualPin = tokenizer(4, data);
                    cout << "Enter your 4 digit pin code(Enter 0 to go Back):" << endl;
                    getline(cin, enteredPin);
                    if (!enteredPin.compare("0")){
                        break;
                    } else if(enteredPin.compare(actualPin)){
                        cout << "Wrong pin! Try again!" << endl;
                        continue;
                    }else
                    {
                        name = tokenizer(1, data);
                        status = 1;
                        break;
                    }
                    
                }
                break;
            }
        }
        
    }
    return status;
}

bool login(){
    string name;
    string choice;
    do{
        cout << "Welcome Sir!" << endl;
        cout << "Press ctrl + c to exit program at any point!" << endl;
        cout << "Please enter your login details "<< endl;
        cout << "Press number according to your Roll (0 to exit):" << endl
            << "1. Manager" << endl
            << "2. Finance Manager" << endl
            << "3. Service Manager" << endl 
            << "4. Kitchen Supervisor" << endl<< endl;
        getline(cin, choice);
        system("CLS");
        if((choice.compare("1") && choice.compare("2") && choice.compare("3") && choice.compare("4"))){
            cout << "Invalid input! Try Again! (press any key)";
            getch();
            system("CLS");
            continue;
        }else{
            break;
        }
    }while (true);
    
    if(auth(stoi(choice), name))
    {
        cout << "Login Succesful!(press any key)";
        getch();
        system("CLS");
        return 1;
    }
    else{
        cout << "Login Failed!(press any key)";
        getch();
        system("CLS");
        return 0;
    }
}

void order() {
    string choice;
    vector<Order> orders; 

    do {
        
        cout << "1. Check Menu\n";
        cout << "2. Place Order\n";
        cout << "3. Genreate Bill\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        getline(cin, choice);
        system("CLS");
        if(choice.compare("1") && choice.compare("2") && choice.compare("3") && choice.compare("4")  ){
            cout << "Invalid Input!" << endl;
            continue;
        }else {
        string foodChoice;
        switch( stoi(choice)) {
            case 1: 
                
                cout << "\n" << left << setw(20) << "Food" << setw(10) << "Price" << endl;
                cout << string(30, '-') << endl;
                cout << "1. " << left << setw(20) << "Nihari" << "Rs.799/-" << endl;
                cout << "2. " << left << setw(20) << "Karahi" << "Rs.999/-" << endl;
                cout << "3. " << left << setw(20) << "Malai Boti" << "Rs.1299/-" << endl;
                cout << "4. " << left << setw(20) << "Biryani" << "Rs.599/-" << endl;
                cout << "5. " << left << setw(20) << "Saag" << "Rs.399/-" << endl;
                cout << "6. " << left << setw(20) << "Shami Kabab" << "Rs.259/-" << endl;
                cout << "7. " << left << setw(20) << "Kabli Pulao" << "Rs.899/-" << endl;
                cout << "8. " << left << setw(20) << "Daal" << "Rs.199/-" << endl;
                cout << "9. " << left << setw(20) << "Chapli Kabab" << "Rs.699/-" << endl;
                cout << "10. " << left << setw(20) << "Naan" << "Rs.49/-" << endl;
                cout << "11. " << left << setw(20) << "Chicken Korma" << "Rs.239/-" << endl;
                
                break;
            
            case 2: 
                
                do {
                    cout << "\nEnter the serial number of the food item to order (0 to complete order): ";
                    getline(cin, foodChoice);
                    if(choice.compare("0") && choice.compare("1") && choice.compare("2")  && choice.compare("3") && choice.compare("4") && choice.compare("5") && choice.compare("6") && choice.compare("7") && choice.compare("8")  && choice.compare("9") && choice.compare("10") && choice.compare("11") && choice.compare("0"))
                        cout << "Invalid Input!" << endl;
                    else{
                        switch (stoi(foodChoice)) {
                            case 1: 
                                cout << "Nihari added to your order. Thank you!\n"; 
                                orders.push_back({"Nihari", 799});
                                break;
                            case 2: 
                                cout << "Karahi added to your order. Thank you!\n"; 
                                orders.push_back({"Karahi", 999});
                                break;
                            case 3: 
                                cout << "Malai Boti added to your order. Thank you!\n"; 
                                orders.push_back({"Malai Boti", 1299});
                                break;
                            case 4: 
                                cout << "Biryani added to your order. Thank you!\n"; 
                                orders.push_back({"Biryani", 599});
                                break;
                            case 5: 
                                cout << "Saag added to your order. Thank you!\n"; 
                                orders.push_back({"Saag", 399});
                                break;
                            case 6: 
                                cout << "Shami Kabab added to your order. Thank you!\n"; 
                                orders.push_back({"Shami Kabab", 259});
                                break;
                            case 7: 
                                cout << "Kabli Pulao added to your order. Thank you!\n"; 
                                orders.push_back({"Kabli Pulao", 899});
                                break;
                            case 8: 
                                cout << "Daal added to your order. Thank you!\n"; 
                                orders.push_back({"Daal",199 });
                                break;
                            case 9: 
                                cout << "Chapli Kabab added to your order. Thank you!\n"; 
                                orders.push_back({"Chapli Kabab", 699});
                                break;
                            case 10: 
                                cout << "Naan added to your order. Thank you!\n"; 
                          
                                orders.push_back({"Naan", 49});
                                break;
                            case 11: 
                                cout << "Chicken Korma added to your order. Thank you!\n"; 
                                orders.push_back({"Chicken Korma", 239});
                                break;
                            case 0: 
                                cout << "Order completed. Enjoy your meal!\n"; 
                                break;
                            default: 
                                cout << "Invalid choice. Please try again.\n"; 
                                break;
                        }
                    }
                    
                } while (foodChoice.compare("0"));
                break;
            
            case 3: 
                if (orders.empty()) {
                    cout << "\nNo items ordered yet.\n";
                } else {
                    time_t now = time(0); 
                    char* date_time = ctime(&now);
                    int totalBill = 0;
                    cout << "\nYour Bill:\n";
                    cout << left << setw(20) << "Food Item" << setw(10) << "Price" << endl;
                    cout << string(30, '-') << endl;
                    for (const auto& order : orders) {
                        cout << left << setw(20) << order.itemName << "Rs." << order.price << "/-" << endl;
                        totalBill += order.price;
                    }
                    cout << string(30, '-') << endl;
                    cout << left << setw(20) << "Total" << "Rs." << totalBill << "/-" << endl;
                    ofstream logFile("logs.csv", ios::app);
                    logFile << left << setw(20) << date_time << ",Rs." << totalBill << "/-" << endl;
                    logFile.close();
                }
                break;
            
            case 4:
                cout << "Exiting Order section.\n";
                break;

        }
        }
    } while (choice.compare("4"));
}