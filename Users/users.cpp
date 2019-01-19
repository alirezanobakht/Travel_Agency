 //
// Created by mgh on 12/24/18.
//

#include "users.h"
 void save_def_file(User _user){
     FILE* fp_d=fopen("Users/usrs/default.def","ab");
     fwrite(&(_user.user_name),sizeof(char),9,fp_d);
     fclose(fp_d);
 }
 void save_user_file(User _user){
     string folder_addr="Users/usrs/"+(string)_user.user_name;
     mkdir(folder_addr.c_str());
     string file_addr=folder_addr+"/profile"+".usr";
     FILE* fp_u=fopen(file_addr.c_str(),"wb");
     fwrite(&_user,sizeof(User),1,fp_u);
     fclose(fp_u);

 }
 vector<User> get_users(){
     vector<User> users;
     FILE* fp_d=fopen("Users/usrs/default.def","rb");
     if(fp_d!=NULL){
         while (true){
             char user_name[9]={};
             fread(&user_name,sizeof(char),9,fp_d);
             if(feof(fp_d))break;
             string file_addr="Users/usrs/"+(string)user_name+"/profile"+".usr";
             User temp={};
             FILE* fp_u=fopen(file_addr.c_str(),"rb");
             fread(&temp, sizeof(User),1,fp_u);
             fclose(fp_u);
             users.push_back(temp);
         }
         fclose(fp_d);
     }
     return users;
 }
 User get_user(char user_name[9]){
     string file_addr="Users/usrs/"+(string)user_name+"/profile"+".usr";
     FILE* fp_u=fopen(file_addr.c_str(),"rb");
     User temp={};
     if(fp_u!=NULL) {
         fread(&temp, sizeof(User),1,fp_u);
         fclose(fp_u);
     }
     return temp;
 }
 long int find_user_in_users(User _user){
     vector<User> users=get_users();
     for(long int i=0;i<users.size();i++){
         int j;
         for(j=0;j<9 && users[i].user_name[j]==_user.user_name[j];j++);
         if(j==9){
             return i;
         }
     }
     return -1;
 }
 long int find_user_in_file(char user_name[9]){
     string file_addr="Users/usrs/"+(string)user_name+"/profile"+".usr";
     FILE* fp_u=fopen(file_addr.c_str(),"rb");
     if(fp_u==NULL) return -1;
     fclose(fp_u);
     return 1;
 }
 int add_user(User _user){
     if(find_user_in_file(_user.user_name)==-1) {
         save_user_file(_user);
         save_def_file(_user);
         return 1;
     }
     return -1;
 }
 User user_login(char user_name[9],char user_pass[9]){
     if(find_user_in_file(user_name)!=-1){
         User _user=get_user(user_name);
         int j;
         for(j=0;j<9 && _user.user_name[j]==user_name[j];j++);
         if(j==9){
             int k;
             for(k=0;k<9 && _user.user_pass[k]==user_pass[k];k++);
             if(k==9){
                 return _user;
             }
         }
         return User{};
     }
     return User{};
 }
 void edit_user_profile(User _user){
     if(find_user_in_file(_user.user_name)!=-1) {
         save_user_file(_user);
     }
 }
 int remove_user(User _user){
     if(find_user_in_file(_user.user_name)!=-1) {
         vector<User> users=get_users();
         string folder_addr="Users/usrs/"+(string)_user.user_name;
         string file_addr=folder_addr+"/profile.usr";
         string ticks_addr=folder_addr+"/ticks.def";
         long int point=find_user_in_users(_user);
         users.erase(users.begin()+point);
         remove("Users/usrs/default.def");
         remove(file_addr.c_str());
         remove(ticks_addr.c_str());
         rmdir(folder_addr.c_str());
         for(int i=0;i<users.size();i++){
             save_def_file(users[i]);
         }
         return 1;
     }
     return -1;
 }
//--------------------------------------------------------------------------