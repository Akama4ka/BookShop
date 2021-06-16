#ifndef ADMIN_H
#define ADMIN_H
using namespace std;
#include"User.h"
class Admin:public User
{
	
public:
	Admin(){}
	void deleteUser();
	void createAdmin();
	void createUser();
	bool filesearch();
	bool CheckingAdmin();
	~Admin() {}
};

#endif 
