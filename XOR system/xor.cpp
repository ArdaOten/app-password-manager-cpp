#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
#include <cstdio>

struct ADMIN {
    bool adminOP=0;
};
struct UserData{
    std::string password;
    std::string username;
};
struct WebKeyData{
    std::string webpassword;
    std::string websitename;
};
class AccountData {
    std::string checkpassword;
    
    char c;
    std::vector<UserData>usercreate;
    public:
    void XORsave(UserData &data){
        std::fstream f("usersdatas.txt", std::ios::app);
        for(int i=0; i < data.password.length(); i++){
        c = data.password.at(i);
        f << (char)(c ^ 42);
    }
    f << std::endl;
    f << data.username << std::endl;
    f.close();
}
    void XOR(UserData &data){
        std::ifstream f("usersdatas.txt");
        std::string line;
        int lineCounter = 0;
        while(std::getline(f, line)){
        if(lineCounter == 0){
        for(int i=0; i < line.length(); i++){
        std::cout << (char)(line.at(i) ^ 42);
        }
    } 
    else {
        std::cout << data.username;
    }
    lineCounter++; 
}
f.close();
}
       UserData XORload(std::ifstream &f,UserData &data){
        if (!f.is_open()){
            std::cout << "File is couldn't open!";
        }
        data.password = "";
        data.username = "";
        while(f.get(c) && c != '\n'){
        data.password += (char)(c ^ 42);
        }
        std::getline(f, data.username);
        return data;
    }
    void AccountCreate(UserData &data){bool checking=0; std::string chusername; bool chusern=0;
        std::ifstream f("usersdatas.txt");
        usercreate.clear();
        while(f.peek() != EOF) {
        usercreate.push_back(XORload(f, data)); }
        do{
        std::cout << "---Create User---" << std::endl;
        std::cout << " Create Username : ";
        std::cin >> chusername;
        for(int i=0; i < usercreate.size(); i++){
        if(usercreate.at(i).username == data.username){
            if(chusername == usercreate.at(i).username){ 
                chusern = 1;
                break;
            }
        }
        }
        if(chusern == 1){
            std::cout << "registered username!";
            Sleep(1000);
        }
        else if(!chusern){
        std::cout << " Create Password : ";
        std::cin >> data.password;
        std::cout << "Enter Again Password : ";
        std::cin >> checkpassword;
        std::cout << "\n";
        if(data.username.length() < 4 || data.password.length() < 4){std::cout << "Password/Username too short try again!"; Sleep(1000); system("cls");}
        else if(data.username == data.password){std::cout << "Password and Username can't be same!"; Sleep(1000); system("cls");}
        else if(checkpassword == data.password){std::cout << "Password, created succesfully!"; Sleep(1000); system("cls"); checking=1; XORsave(data);}
        else{std::cout << "Password are not same try again!"; Sleep(1000); system("cls");}
    }
    }while(!checking);
        checking = 0;
        system("cls");
    }
};
class UserKeysData {
    private:
    std::vector <WebKeyData>websites;
    public:
        void UserMenu(UserData &data,WebKeyData &wkeydata){ system("cls"); int select=0;
        do{
        std::cout << "---Save UserData's APP---" << std::endl;
        std::cout << "[1] Create New Key Data" << std::endl;
        std::cout << "[2] Search Data" << std::endl;
        std::cout << "[3] See All Data's" << std::endl;
        std::cout << "[4] Delete All Data's" << std::endl;
        std::cout << "[5] Exit" << std::endl;
        std::cout << "[*] >>> ";
        std::cin >> select;
        switch(select){
         case 1:CreateNewData(data, wkeydata); break;
         case 2:searchupdata(data, wkeydata); break;
         case 3:SeeAllData(data, wkeydata); break;
         default: break;
        }
        }while(select != 5);
        system("cls");
    }
    void KeyData(UserData &data, WebKeyData &wkeydata){system ("cls"); 
    char c;
    std::string filename = data.username + "_secrets.txt";
    std::fstream f(filename, std::ios::app);
    f << wkeydata.websitename << std::endl;
    for(int i=0; i < wkeydata.webpassword.length(); i++){
        c = wkeydata.webpassword.at(i);
        f << (char)(c ^ 7);
    }
    f << std::endl;
}
    void CreateNewData(UserData &data, WebKeyData &wkeydata){ system("cls"); 
        bool checkit=0; 
        bool save=0; 
        std::string YorN;
        do{
        std::cout << "---Save UserData's APP---" << std::endl;
        std::cout << "[*] Website Name: ";
        std::cin >> wkeydata.websitename;
        std::cout << "[*] Website Password: " << std::endl;
        std::cin >> wkeydata.webpassword;
        if(!save){
        std::cout << "[*] Type 'N' for reset!" << std::endl;
        std::cout << "[*] Wanna Save?(Y/N)" << std::endl;
        std::cin >> YorN;
        if(YorN == "Y" || YorN == "y"){
        KeyData(data, wkeydata);
        std::cout << "[*] Succesfully Saved!" << std::endl;
        Sleep(1500);
        save =1;
        checkit =1;
        
        }
        else if(YorN == "N" || YorN == "n"){save=0; checkit=0;}
        }
        system("cls");
        }while(!checkit);
    }
    
    
    WebKeyData WEBPASSDATA(std::ifstream &f,WebKeyData &wkeydata){
        if (!f.is_open()){
            std::cout << "File is couldn't open!";
        }
        char c;
        wkeydata.websitename = "";
        wkeydata.webpassword = "";
        std::getline(f, wkeydata.websitename);
        while(f.get(c) && c != '\n'){
        wkeydata.webpassword += (char)(c ^ 7);
        }
        return wkeydata;
    }
    void DeleteKeyData(UserData &data, WebKeyData &wkeydata){system ("cls"); 
    char c;
    wkeydata.websitename = "";
    wkeydata.webpassword = "";
    std::string filename = data.username + "_secrets.txt";
    std::fstream f(filename, std::ios::out);
    for(int i=0; i < websites.size(); i++){
    f << websites.at(i).websitename << std::endl;
    for(int j=0; j < websites.at(i).webpassword.length(); j++){
        f << (char)(websites.at(i).webpassword.at(j) ^ 7);
    }
    f << std::endl;
}
}
    void searchupdata(UserData &data,WebKeyData &wkeydata){system ("cls");
    int answer;
    std::string checkwebsite;
    std::string websitepass;
    std::string filename = data.username + "_secrets.txt";
    std::ifstream f(filename);
    websites.clear();
    while(f.peek() != EOF) {
    websites.push_back(WEBPASSDATA(f, wkeydata)); }
    std::cout << "---UserData's APP---" << std::endl;
    std::cout << "[*] Website Name: ";
    std::cin >> checkwebsite;
    int i;
    for(i=0; i < websites.size(); i++){
        if(websites.at(i).websitename == checkwebsite){
            std::cout << "\n";
            std::cout << "Website Name: " << websites.at(i).websitename << std::endl;
            std::cout << "Password: "<< websites.at(i).webpassword << std::endl;
        }
    }
    std::cout << "\n";
    std::cout << "[1] just continue" << std::endl;
    std::cout << "[2] delete this data" << std::endl;
    std::cout << "[*]>>> ";
    std::cin >> answer;
    if(answer == 1) {
    std::cout << "Press any button to continue!";
    std::cin.ignore();
    std::cin.get();
    }
    else if(answer == 2){
        for(i=0; i < websites.size(); i++){
        if(websites.at(i).websitename == checkwebsite ){
        websites.erase(websites.begin() + i);
        DeleteKeyData(data, wkeydata);
        break;
        }
        
    } 
    }
    system("cls");
}

    void SeeAllData(UserData &data, WebKeyData &wkeydata){ system("cls");
    std::string filename = data.username + "_secrets.txt";
    std::ifstream f(filename);
    websites.clear();
    while(f.peek() != EOF) {
    websites.push_back(WEBPASSDATA(f, wkeydata)); }
        std::cout << "---Save UserData's APP---" << std::endl;
        std::cout << "[*] ALL DATA'S" << std::endl;
     for(int i=0; i < websites.size(); i++){
            std::cout << "\n";
            std::cout << "----------------------------------------------" << std::endl;;
            std::cout << "Website Name: " << websites.at(i).websitename << std::endl;
            std::cout << "Password: "<< websites.at(i).webpassword << std::endl;
            std::cout << "----------------------------------------------" << std::endl;
        }  
    std::cout << "Press any button to continue!";
    std::cin.ignore();
    std::cin.get();
    system("cls");
    }
};
class ADMINPANEL {
    private:
    std::vector <WebKeyData>websites;
    std::vector<UserData> users;
    AccountData accdata;
    public:
    void ADMINPANELMENU(ADMIN &admin,UserData &data, WebKeyData &wkeydata){system("cls"); 
        if(admin.adminOP==1){
        int select=0;
        do{
        std::cout << data.username << std::endl;;
        std::cout << "---[*] ADMIN PANEL [*]---" << std::endl;
        std::cout << "[1] Create New Key Data" << std::endl;
        std::cout << "[2] Search Data" << std::endl;
        std::cout << "[3] See All Data's" << std::endl;
        std::cout << "[4] Delete All Data's" << std::endl;
        std::cout << "[5] Choose Username" << std::endl;
        std::cout << "[6] Delete User And All Data's" << std::endl;
        std::cout << "[7] See All User's" << std::endl;
        std::cout << "[8] Exit" << std::endl;
        std::cout << "[*] >>> ";
        std::cin >> select;
        switch(select){
         case 1: CreateNewDataADMIN(data,wkeydata); break;
         case 2: searchupdataADMIN(data,wkeydata); break;
         case 3: SeeAllDataADMIN(data,wkeydata); break;
         case 4: DeleteKeyDataADMIN(data,wkeydata); break;
         case 5: ChooseUser(data,wkeydata); break;
         case 6: DeleteUserAndData(data,wkeydata); break;
         case 7: ListUsers(data,wkeydata); break;
         case 8: data.username = "" ;break;
         default: break;
        }
        }while(select != 8);
        system("cls");
    }
    }
    void ListUsers(UserData &data, WebKeyData  &wkeydata){ system("cls");
        std::ifstream f("usersdatas.txt");
        users.clear();
        while(f.peek() != EOF) {
        users.push_back(accdata.XORload(f, data)); }
        for(int i=0; i < users.size(); i++){
            std::cout << users.at(i).username << std::endl;
            std::cout << users.at(i).password << std::endl;
            std::cout << "-----------------------------------------"<<std::endl;
        }
        std::cin.ignore();
        std::cin.get();
        system("cls");
    }
    void ShowUsers(UserData &data, WebKeyData &wkeydata){ system("cls");
        std::ifstream f("usersdatas.txt");
        users.clear();
        while(f.peek() != EOF) {
        users.push_back(accdata.XORload(f, data)); }
        for(int i=0; i < users.size(); i++){
            std::cout << users.at(i).username << std::endl;
            std::cout << "-------------------"<<std::endl;
        }
    }
    void ChooseUser(UserData &data,WebKeyData &wkeydata){ system("cls");
        std::string chooseusername;
        bool check=0;
        std::cout << "---ADMIN UserData's APP---" << std::endl;
        std::cout << "[*] User's Username  " << std::endl;
        std::cout << "-------------------"<<std::endl;
        ShowUsers(data,wkeydata);
        std::cout << "[*] Enter Username:  ";
        std::cin >> chooseusername;
        for(int i=0; i < users.size(); i++){
            if(users.at(i).username == chooseusername){
                check=1; 
            }
        }
        if(check==1){
            data.username = chooseusername;
            std::cout << data.username << "' successfully selected!"; 
        }
        else std::cout << "Non users has found!";
        Sleep(1500);
        system("cls");
    }
    void DeleteUserAndData(UserData &data,WebKeyData &wkeydata){
        std::string deleteuser;
        bool detelech=0;
        std::cout << "---ADMIN DELETE ALL DATA UserData's APP---" << std::endl;
        std::cout << "[*] User's Username  " << std::endl;
        std::cout << "-------------------"<<std::endl;
        ShowUsers(data,wkeydata);
        std::cout << "[*] Choose Username To Delete All Data's:  ";
        std::cin >> deleteuser;
        for(int i=0; i < users.size(); i++){
            if(users.at(i).username == deleteuser){
                detelech=1;
                users.erase(users.begin() + i);
            }
        }
        if(detelech==1){
            data.username = deleteuser;
            std::string filename = data.username + "_secrets.txt";
            remove(filename.c_str());
            std::ofstream f("usersdatas.txt");
        for(int i=0; i < users.size(); i++){
        for(int j=0; j < users.at(i).password.length(); j++){
        f << (char)(users.at(i).password.at(j) ^ 42);
        }
        f << std::endl;
        f << users.at(i).username << std::endl;
    }
        }
        else std::cout << "Non users has found!";
        Sleep(1500);
        system("cls");
    }
    void KeyDataADMIN(UserData &data, WebKeyData &wkeydata){system ("cls"); 
    char c;
    std::string filename = data.username + "_secrets.txt";
    std::fstream f(filename, std::ios::app);
    f << wkeydata.websitename << std::endl;
    for(int i=0; i < wkeydata.webpassword.length(); i++){
        c = wkeydata.webpassword.at(i);
        f << (char)(c ^ 7);
    }
    f << std::endl;
}
    void CreateNewDataADMIN(UserData &data, WebKeyData &wkeydata){ system("cls"); 
        bool checkit=0; 
        bool save=0; 
        std::string YorN;
        do{
        std::cout << "---ADMIN Save UserData's APP---" << std::endl;
        std::cout << "[*] Website Name: ";
        std::cin >> wkeydata.websitename;
        std::cout << "[*] Website Password: " << std::endl;
        std::cin >> wkeydata.webpassword;
        if(!save){
        std::cout << "[*] Type 'N' for reset!" << std::endl;
        std::cout << "[*] Wanna Save?(Y/N)" << std::endl;
        std::cin >> YorN;
        if(YorN == "Y" || YorN == "y"){
        KeyDataADMIN(data, wkeydata);
        std::cout << "[*] Succesfully Saved!" << std::endl;
        Sleep(1500);
        save =1;
        checkit =1;
        
        }
        else if(YorN == "N" || YorN == "n"){save=0; checkit=0;}
        }
        system("cls");
        }while(!checkit);
    }
    
    
    WebKeyData WEBPASSDATAADMIN(std::ifstream &f,WebKeyData &wkeydata){
        if (!f.is_open()){
            std::cout << "File is couldn't open!";
        }
        char c;
        wkeydata.websitename = "";
        wkeydata.webpassword = "";
        std::getline(f, wkeydata.websitename);
        while(f.get(c) && c != '\n'){
        wkeydata.webpassword += (char)(c ^ 7);
        }
        return wkeydata;
    }
    void DeleteKeyDataADMIN(UserData &data, WebKeyData &wkeydata){system ("cls"); 
    char c;
    wkeydata.websitename = "";
    wkeydata.webpassword = "";
    std::string filename = data.username + "_secrets.txt";
    std::fstream f(filename, std::ios::out);
    for(int i=0; i < websites.size(); i++){
    f << websites.at(i).websitename << std::endl;
    for(int j=0; j < websites.at(i).webpassword.length(); j++){
        f << (char)(websites.at(i).webpassword.at(j) ^ 7);
    }
    f << std::endl;
}
}
    void searchupdataADMIN(UserData &data,WebKeyData &wkeydata){system ("cls");
    int answer;
    std::string checkwebsite;
    std::string websitepass;
    std::string filename = data.username + "_secrets.txt";
    std::ifstream f(filename);
    websites.clear();
    while(f.peek() != EOF) {
    websites.push_back(WEBPASSDATAADMIN(f, wkeydata)); }
    std::cout << "---ADMIN UserData's APP---" << std::endl;
    std::cout << "[*] Website Name: ";
    std::cin >> checkwebsite;
    int i;
    for(i=0; i < websites.size(); i++){
        if(websites.at(i).websitename == checkwebsite){
            std::cout << "\n";
            std::cout << "Website Name: " << websites.at(i).websitename << std::endl;
            std::cout << "Password: "<< websites.at(i).webpassword << std::endl;
        }
    }
    std::cout << "\n";
    std::cout << "[1] just continue" << std::endl;
    std::cout << "[2] delete this data" << std::endl;
    std::cout << "[*]>>> ";
    std::cin >> answer;
    if(answer == 1) {
    std::cout << "Press any button to continue!";
    std::cin.ignore();
    std::cin.get();
    }
    else if(answer == 2){
        for(i=0; i < websites.size(); i++){
        if(websites.at(i).websitename == checkwebsite ){
        websites.erase(websites.begin() + i);
        DeleteKeyDataADMIN(data, wkeydata);
        break;
        }
        
    } 
    }
    system("cls");
}
    void SeeAllDataADMIN(UserData &data, WebKeyData &wkeydata){ system("cls");
    std::string filename = data.username + "_secrets.txt";
    std::ifstream f(filename);
    websites.clear();
    while(f.peek() != EOF) {
    websites.push_back(WEBPASSDATAADMIN(f, wkeydata)); }
        std::cout << "---ADMIN Save UserData's APP---" << std::endl;
        std::cout << "[*] ALL DATA'S" << std::endl;
     for(int i=0; i < websites.size(); i++){
            std::cout << "\n";
            std::cout << "----------------------------------------------" << std::endl;;
            std::cout << "Website Name: " << websites.at(i).websitename << std::endl;
            std::cout << "Password: "<< websites.at(i).webpassword << std::endl;
            std::cout << "----------------------------------------------" << std::endl;
        }  
    std::cout << "Press any button to continue!";
    std::cin.ignore();
    std::cin.get();
    system("cls");
    }
    
};
class Manager{
    private:
    std::vector<UserData> users;
    AccountData accdata;
    UserKeysData keymenu;
    ADMINPANEL adminpanel;
    char c;
    public:
    void Menu(UserData &data,WebKeyData &wkeydata,ADMIN &admin){ system("cls"); int menuselection=0;
        do{
        std::cout << "---Save UserData's APP---" << std::endl;
        std::cout << "[1] Create Acoount" << std::endl;
        std::cout << "[2] Login" << std::endl;
        std::cout << "[3] Exit" << std::endl;
        std::cout << "[*] >>> ";
        std::cin >> menuselection;
        switch(menuselection){
         case 1: accdata.AccountCreate(data); break;
         case 2: LOGIN(data, wkeydata,admin); break;
         case 3: break;
         default: break;
        }
        }while(menuselection != 3);
    }
        void LOGIN(UserData &data,WebKeyData &wkeydata, ADMIN &admin){ system("cls");
        bool check=0;
        std::ifstream f("usersdatas.txt");
        users.clear();
        while(f.peek() != EOF) {
        users.push_back(accdata.XORload(f, data)); }
        std::string checkpass,checkusername;

        do{ system("cls");
        std::cout << "---LOGIN MENU---" << std::endl;
        std::cout << " Username : ";
        std::cin >> checkusername;
        std::cout << " Password : ";
        std::cin >> checkpass;
        std::cout << "\n";
        if(checkusername == "admin" && checkpass == "wspdag"){
            check=1;
            admin.adminOP=1;
            data.username = "admin";
            adminpanel.ADMINPANELMENU(admin,data,wkeydata);
        }
        else{
        for(int i=0; i < users.size(); i++){
        if(users.at(i).username == checkusername && users.at(i).password == checkpass){
            std::cout << "LOGIN Successfully!"<< std::endl; 
            check = 1;
            data.username = users.at(i).username;
            keymenu.UserMenu(data,wkeydata);
        }}
        if(!check){
        std::cout << "Password Or Username Wrong!"; Sleep(1500); system("cls"); break;
        }
        std::cout << "Welcome!";
        Sleep(2000);
        }
        }while(!check);
        system("cls");
    }
};

int main() {
     Manager menu;
     UserData data;
     WebKeyData wkeydata;
     ADMIN admin;
    menu.Menu(data,wkeydata,admin);
}
