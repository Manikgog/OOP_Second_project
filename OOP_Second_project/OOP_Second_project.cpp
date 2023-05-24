#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>

class Person {
private:
	std::string _name;
	int _age;
	
public:
	Person() : _name(""), _age(0)
	{}

	Person(const std::string& name, int age) : _name(name), _age(age)
	{}

	void SetName(const std::string& name) {
		_name = name;
	}

	void SetName(int age) {
		_age = age;
	}

	std::string GetName() {
		return _name;
	}

	int GetAge() {
		return _age;
	}

	void ShowAll() {
		std::cout << "Имя: " << _name << std::endl << "Возраст: " << _age << std::endl;
	}

	~Person() {
		std::cout << "Деструктор Person\n";
	}

};

class Pupil {
private:
	std::string _name;
	int _age;
	std::vector<int> _marks;

public:
	Pupil() : _name(""), _age(0)
	{}

	Pupil(const std::string& name, int age, const std::vector<int>& marks) : _name(name), _age(age)
	{
		_marks = marks;
	}

	void SetName(const std::string& name) {
		_name = name;
	}

	void SetAge(int age) {
		_age = age;
	}

	void SetMarks(const std::vector<int>& marks){
		_marks = marks;
	}

	std::string GetName() {
		return _name;
	}

	int GetAge() {
		return _age;
	}

	std::vector<int> GetMarks(){
		return _marks;
	}

	void ShowAll() {
		std::cout << "Имя: " << _name << std::endl << "Возраст: " << _age << std::endl;
		bool is_first = true;
		std::cout << "Оценки: ";
		for (const auto i : _marks) {
			if (!is_first) {
				std::cout << ' ';
			}
			is_first = false;
			std::cout << i;
		}
		std::cout << std::endl;
	}

	~Pupil() {
		std::cout << "Деструктор Pupil\n";
	}

};

class Proffessor {
private:
	std::string _name;
	std::string _degree;

public:
	Proffessor() : _name(""), _degree("")
	{}

	Proffessor(std::string name, std::string degree) : _name(name), _degree(degree)
	{}

	void SetName(std::string name) {
		_name = name;
	}

	void SetDegree(std::string degree) {
		_degree = degree;
	}

	std::string GetName() {
		return _name;
	}

	std::string GetDegree() {
		return _degree;
	}

	
	void ShowAll();

	~Proffessor() {
		std::cout << "Proffessor Dest\n";
	}

};


void Proffessor::ShowAll() {
	std::cout << "Имя: " << _name << std::endl << "Степень: " << _degree << std::endl;
}

class Bank;

class Client {
private:
	std::string _name;
	int _age;
	double _bill;


public:
	Client() : _name(""), _age(0)
	{}

	Client(const std::string& name, int age, double bill) : _name(name), _age(age), _bill(bill)
	{}

	void ShowData() {
		std::cout << "Client's name: " << _name << '\n';
		std::cout << "Client's age: " << _age << '\n';
		std::cout << "Client's bill: " << _bill << '\n';
	}

};

class Bank {
private:
	std::vector<Client*> _clients;



public:

	void AddClient(Client* client) {
		_clients.push_back(client);
	}

	void ShowClients() {

		/*std::vector<Client*>::iterator it;
		for(it = _clients.begin(); it != _clients.end(); ++it)
			(*it)->ShowData();*/

		for (const auto& it : _clients) {
			it->ShowData();
		}
	}

	void ShowClient(int index) {
		if (index > _clients.size())
			return;
		(*_clients.at(index-1)).ShowData();
	}
};



int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	
	/*Person a("Name", 30);
	a.SetName("name");
	a.ShowAll();

	std::vector<int> marks = { 5, 4, 4, 3, 5 };
	Pupil b("Pupil", 18, marks);
	b.ShowAll();

	Proffessor c("Спицин", "Доктор наук");
	c.ShowAll();*/

	Bank* bank = new Bank();
	Client* client1 = new Client("Bob", 20, 50000);
	Client* client2 = new Client("Alex", 19, 30000);
	Client* client3 = new Client("Fibi", 27, 40000);
	Client* client4 = new Client("Ross", 29, 150000);
	Client* client5 = new Client("Joe", 28, 2000);
	Client* client6 = new Client("Chandler", 30, 530000);
	bank->AddClient(client1);
	bank->AddClient(client2);
	bank->AddClient(client3);
	bank->AddClient(client4);
	bank->AddClient(client5);
	bank->AddClient(client6);
	bank->ShowClients();
	bank->ShowClient(5);
	return 0;
}

