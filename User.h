#ifndef USER_H
#define USER_H
using namespace std;
class User
{
public:
	string username;
	string password;
	User(){
		username = "clear";
		password = "clear";
	}
	bool LoginandPaasword();
	void Registor();
	bool searchUser(std::string filePath);
	~User() {}
};
#endif
