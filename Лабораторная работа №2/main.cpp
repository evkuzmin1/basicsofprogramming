#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

class Animal
{

public:

    Animal(string name, int age, string activity, string residence)
        : name(name), age(age), activity(activity), residence(residence), info(" ") {}

    string getName()
    {
        return name;
    }

    void setName(string name)
    {
        name = name;
    }


    void Stand()
    {
        cout << name << " is standing" << endl;
    }


    void Lie()
    {
        cout << name << " is lying" << endl;
    }

    void Hunt()
    {
        cout << name << " is hunting" << endl;
    }

    void Feed()
    {
        cout << name << " is fed" << endl;
    }



    virtual void MakeSound()
    {
        cout << "" << endl;
    }

    virtual string Ability() {
        return "";
    }

    virtual string Tail_length()
    {
        return "";
    }

    void setInfo(string info)
    {
        info = info;
    } 

    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Activity: " << activity << endl;
        cout << "Residence: " << residence << endl;
        cout << Ability() << endl;
        cout << Tail_length() << endl;
        cout << endl;
    }


protected:
    string name;
    string info;
    string activity;
    string residence;
    double age;
};

class Zoo
{
private:
    vector<Animal*> animals;
public:

    void deleteAnimal(string name)
    {
        for (int i = 0; i < animals.size(); i++)
        {
            if (animals[i]->getName() == name)
            {
                animals.erase(animals.begin() + i);
                break;
            }
        }

    }

    void addAnimal(Animal* animal)
    {
        animals.push_back(animal);
    }

    void feedAll()
    {
        for (int i = 0; i < animals.size(); i++)
        {
            animals[i]->Feed();
        }
    }
    void MakeSoundSmb(string name)
    {
        for (int i = 0; i < animals.size(); i++)
        {
            if (animals[i]->getName() == name)
            {
                animals[i]->MakeSound();
                break;
            }
        }
    }

 
    void HuntSmb(string name)
    {
        for (int i = 0; i < animals.size(); i++)
        {
            if (animals[i]->getName() == name)
            {
                animals[i]->Hunt();
                break;
            }
        }
    }
    void randompositionAll()
    {
        srand(time(0));
        int x;
        x = rand() % 3 + 1;
 
        if (x == 2)
        {
            for (int i = 0; i < animals.size(); i++)
            {
                animals[i]->Lie();
            }
        }
        else
        {
            for (int i = 0; i < animals.size(); i++)
            {
                animals[i]->Stand();
            }
        }
        
    }
    void infoAll()
    {
        for (int i = 0; i < animals.size(); i++)
        {
            animals[i]->getInfo();
        }
    }
};

class Owl : public Animal
{
public:

    Owl(string name, int age, string activity, string residence, string superpower, string tail_length)
        : Animal(name, age, activity, residence), superpower(superpower), tail_length(tail_length) {}

    void fly()
    {
        cout << name << " is flying" << endl;
    }
    void MakeSound() override 
    {
        cout << name << ": uwu" << endl;
    }
    string Ability() override 
    {
        return name + "'s ability is " + superpower;
    }
    string Tail_length() override
    {
        return name + "'s tail length is " + tail_length;
    }

private:
    string superpower;
    string tail_length;
};

class Lion : public Animal
{
public:

    Lion(string name, int age, string activity, string residence, string superpower, string tail_length)
        : Animal(name, age, activity, residence), superpower(superpower), tail_length(tail_length) {}

    void yawn()
    {
        cout << name << " is yawning";
    }

    void MakeSound() override {
        cout << name << ": RRRRRRRRRRRRRRRRRRR" << endl;
    }
    string Ability() override {
        return name + "'s ability is " + superpower;
    }
    string Tail_length() override {
        return name + "'s tail length is " + tail_length;
    }
    

private:
    string superpower;
    string tail_length;
};

class Cayman : public Animal {
public:
    Cayman(string name, int age, string activity, string residence, string superpower, string tail_length)
        : Animal(name, age, activity, residence), superpower(superpower), tail_length(tail_length) {}

    void swim()
    {
        cout << name << " is swimming" << endl;
    }
    void MakeSound() override {
        cout << name << ": ..." << endl;
    }
    string Ability() override {
        return name + "'s ability is " + superpower;
    }
    string Tail_length() override {
        return name + "'s tail length is " + tail_length;
    }

private:
    string superpower;
    string tail_length;
    string tooth_length;
};

int main() {
    
    Zoo zoo; 
    


    

    Owl a("Lina", 1, "playin", "Vologodskaya oblast, Russian Federation", "vision", "5 cm");
    Lion b("Kolya", 2, "fightin for the leadership", "Dubai, UAE", "roar", "70cm");
    Cayman c("Boris", 3, "sleepin", "California beach, USA", "camouflage", "1,2m");

   


    zoo.addAnimal(&a);
    zoo.addAnimal(&b);
    zoo.addAnimal(&c);


    zoo.feedAll();
    cout << "" << endl;
    zoo.randompositionAll();
    cout << "" << endl;
    zoo.infoAll();
    cout << "" << endl;

    zoo.HuntSmb("Boris");
    zoo.MakeSoundSmb("Lina");

    cout << "----------------------------------------------------------------" << endl;
    cout << endl;

    zoo.deleteAnimal("Lina");

    zoo.feedAll();


 


    return 0;

}