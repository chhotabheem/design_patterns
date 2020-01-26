#include<iostream>
using namespace std;

enum class Subject
{
	Physics,
	Maths,
	Chemistry,
	Computers
};

class Request
{
private:
	Subject subject;
public:
	Request(Subject sub): subject(sub){}
	Subject get_subject() const { return subject; }
};

class Professor
{
public:
	virtual void handle_request(Request* req) = 0;
	virtual void set_successor(Professor* prof) =0;
};

class MathsProfessor:public Professor
{
private:
	Professor* successor;
public:
	void handle_request(Request* req)
	{
		Subject sub = req->get_subject();
		if (sub == Subject::Maths)
		{
			cout << "handling maths request" << endl;
		}
		else
		{
			successor->handle_request(req);
		}
	}
	void set_successor(Professor* prof)
	{
		successor = prof;
	}

};

class PhysicsProfessor :public Professor
{
private:
	Professor* successor;
public:
	void handle_request(Request* req)
	{
		Subject sub = req->get_subject();
		if (sub == Subject::Physics)
		{
			cout << "handling physics request" << endl;
		}
		else
		{
			successor->handle_request(req);
		}
	}
	void set_successor(Professor* prof)
	{
		successor = prof;
	}

};

class ChemistryProfessor :public Professor
{
private:
	Professor* successor;
public:
	void handle_request(Request* req)
	{
		Subject sub = req->get_subject();
		if (sub == Subject::Chemistry)
		{
			cout << "handling chemistry request" << endl;
		}
		else
		{
			cout << "not able to handle the request";
		}
	}
	void set_successor(Professor* prof)
	{
		successor = prof;
	}

};

int main()
{
	Professor* maths_prof = new MathsProfessor;
	Professor* phy_prof = new PhysicsProfessor;
	Professor* che_prof = new ChemistryProfessor;
	maths_prof->set_successor(phy_prof);
	phy_prof->set_successor(che_prof);
	Request req(Subject::Physics);
	maths_prof->handle_request(&req);
	return 0;
}