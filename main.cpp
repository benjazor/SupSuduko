#include <iostream>
#include <map>
#include <string>

using namespace std;

/* VERSION TAB 9 = BOX
 * class Game{
private:
    int Data[9*9];
public:
    Game(int data[]=new int[9*9]){
        for(int i = 0; i < 81; i++){
            this->Data[i] = data[i];
        }
    }
    string to_string(){
        string tmp;
        for (int i = 0; i < 81; i++){
            if (i != 0) {
                if (i%3 == 0) { tmp += " "; }
                if (i%9 == 0) { tmp += "\n"; }
                if (i%27 == 0) { tmp += "\n"; }
            }
            tmp += "[";
            if (this->Data[(i%3) + ((i/3%3) * 8) + (i/3) + (i/27*18)] == 0){
                tmp += ".";
            } else {
                tmp += std::to_string(this->Data[(i%3) + ((i/3%3) * 8) + (i/3) + (i/27*18)]);
            }
            tmp +=  "]";
        }
        return tmp;
    }

    string to_string2(){
        string tmp;
        for (int i = 0; i < 81; i++){
            if (i != 0) {
                if (i%3 == 0) { tmp += " "; }
                if (i%9 == 0) { tmp += "\n"; }
                if (i%27 == 0) { tmp += "\n"; }
            }
            tmp += "[";
            tmp += std::to_string((i%3) + ((i/3%3) * 8) + (i/3) + (i/27*18));
            tmp +=  "]";
        }
        return tmp;
    }

    void display(){
        cout << this->to_string() <<endl;
    }

    bool checkBox(int box){
        if (box > -1 && box < 9){
            std::map<int , int> tmp;
            for (int i=0; i<9; i++){ tmp[i+1]=0; }
            for (int i=0; i<9; i++){ tmp[this->Data[box*9 + i]] += 1; }
            bool result = true;
            for (int i=0; i<9; i++) {
                result = result && tmp[i+1] == 1;
            }
            return result;
        } else {
            return false;
        }
    }

    bool checkLine(int line){
        if (line > -1 && line < 9){
            std::map<int , int> tmp;
            for (int i=0; i<9; i++){ tmp[i+1]=0; }
            for (int i=0; i<9; i++){ tmp[this->Data[line/3*9+line%3+i%3*3+i/3*27]] += 1; }
            bool result = true;
            for (int i=0; i<9; i++) {
                result = result && tmp[i+1] == 1;
            }
            return result;
        } else {
            return false;
        }
    }

    bool checkRow(int row){
        if (row > -1 && row < 9){
            std::map<int , int> tmp;
            for (int i=0; i<9; i++){ tmp[i+1]=0; }
            for (int i=0; i<9; i++){ tmp[this->Data[row/3*27 + row%3*3 + i%3 + i/3*9]] += 1; }
            bool result = true;
            for (int i=0; i<9; i++) {
                result = result && tmp[i+1] == 1;
            }
            return result;
        } else {
            return false;
        }
    }

    bool checkBoard(){
        bool result = true;
        for (int i = 0; i < 9; i++){
            result = result && checkBox(i) && checkLine(i) && checkRow(i);
        }
        return result;
    }
}; */
/* VERSION TAB INT 81(9*9)
 * class Game{
private:
    int Data[9*9];
public:
    Game(int data[]=new int[9*9]){
        for(int i = 0; i < 81; i++){
            this->Data[i] = data[i];
        }
    }
    void display(){
        for(int i = 0; i < 81; i++){
            if (i%3 == 0) { cout << " "; }
            if (i%9 == 0) { cout << "\n"; }
            if (i%27 == 0) { cout << "\n"; }
            cout << "[" << this->Data[i] << "]";
        }
        cout << endl;
    }

    bool checkBox(int box){
        if (box > -1 && box < 9){
            std::map<int , int> tmp;
            for (int i=0; i<9; i++){ tmp[i+1]=0; }
            for (int i=0; i<9; i++){ tmp[this->Data[box/3*27 + box%3*3 + i%3 + i/3*9]] += 1; }
            bool result = true;
            for (int i=0; i<9; i++) {
                result = result && tmp[i+1] == 1;
            }
            return result;
        } else {
            return false;
        }
    }

    bool checkLine(int line){
        if (line > -1 && line < 9){
            std::map<int , int> tmp;
            for (int i = 0; i < 9; i++){ tmp[i+1]=0; }
            for (int i = 0; i < 9; i++){ tmp[this->Data[line*9 + i]] += 1; }
            bool result = true;
            for (int i = 0; i < 9; i++) {
                result = result && tmp[i+1] == 1;
            }
            return result;
        } else {
            return false;
        }
    }

    bool checkColumn(int column){
        if (column > -1 && column < 9){
            std::map<int , int> tmp;
            for (int i = 0; i < 9; i++){ tmp[i+1]=0; }
            for (int i = 0; i < 9; i++){ tmp[this->Data[column+ 9*i]] += 1; }
            bool result = true;
            for (int i = 0; i < 9; i++) {
                result = result && tmp[i+1] == 1;
            }
            return result;
        } else {
            return false;
        }
    }

    bool checkBoard(){
        bool result = true;
        for (int i = 0; i < 9; i++){
            result = result && checkBox(i) && checkLine(i) && checkColumn(i);
        }
        return result;
    }
};*/
/*
 * J'ai fait le choix de ne pas créer une classe suplémentaire pour la case,
 * mais plutôt de l'implémenter sous forme d'une paire de deux éléments dans un tableau,
 * un int pour la valeur de la case et un booléen affin d'implémenter la propriété "canChange" évoquée dans le sujet.
 */
class Game{
private:
    pair<int, bool> Data[9*9];
public:
    pair<int, bool> getData(int index){
        return this->Data[index];
    }
    void setData(int index, int value, bool canChange=true){
        this->Data[index] = pair<int, bool>(value, canChange);
    }
    void setData(int x, int y, int value, bool canChange=true){
        this->Data[x + y*9] = pair<int, bool>(value, canChange);
    }
    Game(pair<int, bool> data[]=new pair<int, bool>[9*9]){
        for(int i = 0; i < 81; i++){
            this->Data[i] = data[i];
        }
    }
    void display(){
        for(int i = 0; i < 81; i++){
            if (i%3 == 0) { cout << " "; }
            if (i%9 == 0) { cout << "\n"; }
            if (i%27 == 0) { cout << "\n"; }
            cout << "[";
            if(this->Data[i].first==0){
                cout << ".";
            } else{
                cout << this->Data[i].first;
            }

            cout << "]";
        }
        cout << endl;
    }

    bool checkBox(int box){
        if (box > -1 && box < 9){
            std::map<int , int> tmp;
            for (int i=0; i<9; i++){ tmp[i+1]=0; }
            for (int i=0; i<9; i++){ tmp[this->Data[box/3*27 + box%3*3 + i%3 + i/3*9].first] += 1; }
            bool result = true;
            for (int i=0; i<9; i++) {
                result = result && tmp[i+1] == 1;
            }
            return result;
        } else {
            return false;
        }
    }

    bool checkLine(int line){
        if (line > -1 && line < 9){
            std::map<int , int> tmp;
            for (int i = 0; i < 9; i++){ tmp[i+1]=0; }
            for (int i = 0; i < 9; i++){ tmp[this->Data[line*9 + i].first] += 1; }
            bool result = true;
            for (int i = 0; i < 9; i++) {
                result = result && tmp[i+1] == 1;
            }
            return result;
        } else {
            return false;
        }
    }

    bool checkColumn(int column){
        if (column > -1 && column < 9){
            std::map<int , int> tmp;
            for (int i = 0; i < 9; i++){ tmp[i+1]=0; }
            for (int i = 0; i < 9; i++){ tmp[this->Data[column+ 9*i].first] += 1; }
            bool result = true;
            for (int i = 0; i < 9; i++) {
                result = result && tmp[i+1] == 1;
            }
            return result;
        } else {
            return false;
        }
    }

    bool checkBoard(){
        bool result = true;
        for (int i = 0; i < 9; i++){
            result = result && checkBox(i) && checkLine(i) && checkColumn(i);
        }
        return result;
    }
};




int main() {
    pair<int, bool> test_data[9*9];
    for(int i = 0; i < 81; i++){ test_data[i] = pair<int, bool>((i%9 + i/9)%9+1, true); }
    Game test = Game(test_data);
    test.display();

    return 0;
}