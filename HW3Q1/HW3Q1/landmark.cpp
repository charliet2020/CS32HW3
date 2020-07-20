/*
#include <iostream>
#include <string>
using namespace std;
//all about polymorphism
//*/

//Landmark declaration
class Landmark
{
public:
	Landmark(string name);
	
	virtual string name() const; //not pure because I want this to be inherited into Restaurant and Hotel

	virtual string icon() const = 0; //alone is sufficient to prevent Landmark construction

	virtual string color() const;
	//want color to be inherited since no 2 functions with non-empty bodies
	//may have the same implementation
	
	virtual ~Landmark();

private:
	string m_name;
	//Landmark* m_landmark;
};

//Hotel declaration
class Hotel : public Landmark
{
public:
	Hotel(string name);
	virtual string icon() const;
	//color inherited from Landmark
	//name inherited from Landmark

	virtual ~Hotel();
private:
	//string m_name; No class may have a data member whose value is identical for every object of a particular class type
	//Landmark *lm;
};

//Restaurant declaration
class Restaurant : public Landmark
{
public:
	Restaurant(string name, int cap);
	virtual string icon() const;
	virtual ~Restaurant();
	//color inherited from Landmark
	//name inherited from Landmark

private:
	//string m_name; No class may have a data member whose value is identical for every object of a particular class type
	int m_cap;
	//Landmark *lm;
};

//Hospital declaration
class Hospital : public Landmark
{
public:
	Hospital(string name);
	virtual string icon() const;
	virtual string color() const;
	virtual ~Hospital();
	//name inherited from Landmark

private:
	//string m_name; No class may have a data member whose value is identical for every object of a particular class type
	//Landmark *lm;
};

//Landmark implementation
Landmark::Landmark(string name)
	: m_name(name)
{}

Landmark::~Landmark()
{
	/*
	string lm;
	if (m_landmark->icon() == "H")
	lm = "hospital";
	else if (m_landmark->icon() == "bed")
	lm = "hotel";
	else lm = "restaurant";
	*/
}

string Landmark::name() const
{
	return m_name;
}

string Landmark::color() const
{
	return "yellow";
}

//Hotel implementation
Hotel::Hotel(string name)
	: Landmark(name)
{
	//cerr << "hotel constructor called" << endl;
	//lm = new Hotel(name);
}

string Hotel::icon() const
{
	return "bed";
}

Hotel::~Hotel()
{
	//cout << "Destroying the " << "hotel" << " " << lm->name() << endl;
	cout << "Destroying the hotel " << name() << "." << endl; //or  Landmark::name()?
}

//Restaurant implementation
Restaurant::Restaurant(string name, int cap)
	: Landmark(name), m_cap(cap)
{}

string Restaurant::icon() const
{
	if (m_cap < 40)
		return "small knife/fork";
	else
		return "large knife/fork";
}

Restaurant::~Restaurant()
{
	//cout << "Destroying the " << "restaurant" << " " << lm->name() << endl;
	cout << "Destroying the restaurant " << name() << "." << endl;
}

//Hospital implementation
Hospital::Hospital(string name)
	: Landmark(name)
{}

string Hospital::icon() const
{
	return "H";
}

string Hospital::color() const
{
	return "blue";
}

Hospital::~Hospital()
{
	//cout << "Destroying the " << "hospital" << " " << lm->name() << endl;
	cout << "Destroying the hospital " << name() << "." << endl;
}

/*

void display(const Landmark* lm)
{
	cout << "Display a " << lm->color() << " " << lm->icon() << " icon for "
		<< lm->name() << "." << endl;
}

int main()
{
	
	Landmark* landmarks[4];
	landmarks[0] = new Hotel("Westwood Rest Good");
	// Restaurants have a name and seating capacity.  Restaurants with a
	// capacity under 40 have a small knife/fork icon; those with a capacity
	// 40 or over have a large knife/fork icon.
	landmarks[1] = new Restaurant("Bruin Bite", 30);
	landmarks[2] = new Restaurant("La Morsure de l'Ours", 100);
	landmarks[3] = new Hospital("UCLA Medical Center");

	

	cout << "Here are the landmarks." << endl;
	for (int k = 0; k < 4; k++)
		display(landmarks[k]);

	// Clean up the landmarks before exiting
	cout << "Cleaning up." << endl;
	for (int k = 0; k < 4; k++)
		delete landmarks[k];
	
	
}

//*/