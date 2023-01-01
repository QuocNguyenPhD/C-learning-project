#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool login(){
	std::string username, password, ua, pa;

	std::cout<< "username: "<< std::endl;
	std::cin>> username;

	std::cout<< "password: "<<std::endl;
	std::cin>> password;

	ifstream read("data\\"+username +".txt");
	getline(read, ua);
	getline(read, pa);

	if(username== ua && password== pa){
		return true;
	}
	else{
		return false;
	}
}


int main(){
	int choice;
	std::string username, password;
	std::cout<< "1) register:  \n2) login:  \n*) your choice: " << std::endl;
	std::cin>> choice ;

	if(choice==1){
		std::cout<< "username you want to register: "<< std::endl;
		std::cin>> username;

		std::cout<< "password you want to register: "<< std::endl;
		std::cin>> password; 

		ofstream file;
		file.open("data\\"+ username +".txt");
		file<< username<< std::endl;
		file<< password<< std::endl;

	}
	else if(choice==2){

		bool status = login();
		if(status){
			std::cout<< "successfuly login" << std::endl;
			return 1;
		}
		else{
			std::cout<< "fail to login"<< std::endl;
			return 0;

		}

		
	}
	else{
		std::cout<< "option is not valid"<< std::endl;
	}

	

	
return 0;	 
}