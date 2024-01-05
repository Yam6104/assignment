#include<iostream>
#include<conio.h>
using namespace std;

void mainmenu();
void adminmenu();
void customermenu();

class Admin {
private:
    string train_plan[3];
    float train_cost[3];

public:
    Admin() : train_plan{" ", " ", " "}, train_cost{0.0, 0.0, 0.0} {}

    void insert_plan() {
        for (int i = 0; i < 3; i++) {
            cin.ignore();
            cout << "Enter Training Plan\n";
            getline(cin, train_plan[i]);
            cout << "Enter Training Cost\n";
            cin >> train_cost[i];
        }
    }

    void view_training_plan() {
        cout << "Training Plan\t\t\tTraining Cost\n";
        for (int i = 0; i < 3; i++) {
            cout << train_plan[i] << "\t\t" << train_cost[i] << endl;
        }
    }
};

class Customer : public Admin {
private:
    string customer_name;
    int t_plan;
    string cu_plan;
    string weight;
    char tution;
    int tution_hr;
    float beginner_fees = 25.00;
    float intermediate_fees = 30.00;
    float elite_fees = 35.00;
    float tution_fees = 9.50;
    float total_cost = 0;
    float private_t;
    string cur_weight;
    char competition;
    int race;
    float comp_fees = 22.00;
    int comp = 0;

public:
    float private_tuition(char c) {
        if (c == 'y') {
            cout << "Enter private tuition hours \n";
            cin >> tution_hr;
            if (tution_hr < 5) {
                total_cost += (tution_fees * tution_hr);
                return total_cost;
            } else {
                cout << "You exceed the limited private hours\n";
                private_tuition(c);
            }
        } else {
            return total_cost;
        }
    }

    int weight_categories() {
        int current_weight;
        cout << "\n=========Competition Weight Categories========\n\n";
        cout << "Categories\t\t\tWeight Limit\n";
        cout << "1. Heavyweight\t\t\tUnlimited (Over 100)\n";
        cout << "2. Light-Heavyweight\t\t100\n";
        cout << "3. Middleweight\t\t\t90\n";
        cout << "4. Light-Middleweight\t\t81\n";
        cout << "5. Lightweight\t\t\t73\n";
        cout << "6. Flyweight\t\t\t66\n";
        cout << "Enter your current weight\n";
        cin >> current_weight;

        if (current_weight > 100) {
            cout << "You can join Heavyweight Competition \n";
            cur_weight = "Heavyweight";
        } else if (current_weight == 100) {
            cout << "You can join Light-Heavyweight Competition \n";
            cur_weight = "Light-Heavyweight";
        } else if ((current_weight < 100) && (current_weight >= 90)) {
            cout << "You can join Middleweight Competition \n";
            cur_weight = "Middleweight";
        } else if (current_weight < 90 && current_weight >= 81) {
            cout << "You can join Light-Middleweight Competition \n";
            cur_weight = "Light-Middleweight";
        } else if (current_weight < 81 && current_weight >= 73) {
            cout << "You can join Lightweight Competition \n";
            cur_weight = "Lightweight";
        } else if (current_weight < 73 && current_weight >= 66) {
            cout << "You can join Flyweight Competition \n";
            cur_weight = "Flyweight";
        } else {
            cout << "You can't join any competition\n";
            race = 0;
        }

        return race;
    }

    void getdata() {
        cin.ignore();
        cout << "Enter customer name\n";
        getline(cin, customer_name);
        Admin::view_training_plan();
        cout << "Choose training plan (1-3)\n";
        cin >> t_plan;

        if (t_plan == 1) {
            cu_plan = "Beginner";
            total_cost += beginner_fees;
        } else if (t_plan == 2) {
            cu_plan = "Intermediate";
            total_cost += intermediate_fees;
        } else if (t_plan == 3) {
            cu_plan = "Elite";
            total_cost += elite_fees;
        }

        cout << "Private tuition (y/n)\n";
        cin >> tution;
        private_t = private_tuition(tution);

        if ((t_plan == 2) || (t_plan == 3)) {
            race = weight_categories();
            if (race == 1) {
                cout << "You can join competition\n";
                cout << "Enter the number of competitions\n";
                cin >> comp;
                total_cost += (comp_fees * comp);
            } else {
                cout << "You can't join any competition\n";
            }
        } else {
            cout << "You can't compete as you are a beginner\n";
        }
    }

    void showdata() {
        cout << "Customer Name: " << customer_name << endl;
        cout << "Total Cost: £" << total_cost << endl;
        cout << "Weight Category: " << cur_weight << endl;
        cout << "Training Plan: " << cu_plan << endl;
        cout << "=========================\n";
    }
};

Admin obj_admin; 
Customer obj_customer[6];

int s = 0;

int main() {
    mainmenu();
    return 0;
}

void mainmenu() {
    int user;
    cout << "1. Admin\n2. Customer\n3. Exit\n";
    cin >> user;

    switch (user) {
        case 1:
            adminmenu();
            break;
        case 2:
            customermenu();
            break;
        case 3:
            exit(0);
        default:
            cout << "Invalid choice\n";
            mainmenu();
    }
}

void adminmenu() {
    int admin_task;
    cout << "1. Insert Plan\n2. View Training Plan\n3. Back to Main Menu\n";
    cin >> admin_task;

    switch (admin_task) {
        case 1:
            obj_admin.insert_plan();
            getch();
            adminmenu();
            break;
        case 2:
            obj_admin.view_training_plan();
            getch();
            adminmenu();
            break;
        case 3:
            mainmenu();
            break;
        default:
            cout << "Invalid choice\n";
            adminmenu();
    }
}

void customermenu() {
    int customer_task;
    char ch;

    cout << "1. Register\n2. View Information\n3. Back to Main Menu\n";
    cin >> customer_task;

    switch (customer_task) {
        case 1:
            do {
                obj_customer[s].getdata();
                s++;
                cout << "Do you want to continue registering? (y/n)\n";
                cin >> ch;
               } while (ch == 'y');
    customermenu();
}
} 